#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define BUFFER_SIZE 5

struct shared_memory {
    int buffer[BUFFER_SIZE];
    int in, out;
};

void producer(int shmid, int semid) {
    struct shared_memory *shm = (struct shared_memory *)shmat(shmid, NULL, 0);
    int item = 0;

    for (int i = 0; i < 10; i++) {
        struct sembuf wait_empty = {0, -1, 0}; // Wait for empty slot
        struct sembuf wait_mutex = {1, -1, 0}; // Wait for mutex
        struct sembuf signal_mutex = {1, 1, 0}; // Signal mutex
        struct sembuf signal_full = {2, 1, 0}; // Signal full slot

        item = rand() % 100;
        semop(semid, &wait_empty, 1);
        semop(semid, &wait_mutex, 1);

        shm->buffer[shm->in] = item;
        printf("Produced: %d\n", item);
        shm->in = (shm->in + 1) % BUFFER_SIZE;

        semop(semid, &signal_mutex, 1);
        semop(semid, &signal_full, 1);

        sleep(1);
    }
}

void consumer(int shmid, int semid) {
    struct shared_memory *shm = (struct shared_memory *)shmat(shmid, NULL, 0);

    for (int i = 0; i < 10; i++) {
        struct sembuf wait_full = {2, -1, 0}; // Wait for full slot
        struct sembuf wait_mutex = {1, -1, 0}; // Wait for mutex
        struct sembuf signal_mutex = {1, 1, 0}; // Signal mutex
        struct sembuf signal_empty = {0, 1, 0}; // Signal empty slot

        semop(semid, &wait_full, 1);
        semop(semid, &wait_mutex, 1);

        int item = shm->buffer[shm->out];
        printf("Consumed: %d\n", item);
        shm->out = (shm->out + 1) % BUFFER_SIZE;

        semop(semid, &signal_mutex, 1);
        semop(semid, &signal_empty, 1);

        sleep(2);
    }
}

int main() {
    int shmid = shmget(IPC_PRIVATE, sizeof(struct shared_memory), IPC_CREAT | 0666);
    int semid = semget(IPC_PRIVATE, 3, IPC_CREAT | 0666);

    semctl(semid, 0, SETVAL, BUFFER_SIZE); // Empty slots
    semctl(semid, 1, SETVAL, 1);          // Mutex
    semctl(semid, 2, SETVAL, 0);          // Full slots

    if (fork() == 0) {
        producer(shmid, semid);
        exit(0);
    } else {
        consumer(shmid, semid);
        wait(NULL);
    }

    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);
    return 0;
}
