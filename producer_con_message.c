#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message {
    long msg_type;
    int data;
};

void producer(int msgid) {
    struct message msg;
    msg.msg_type = 1;

    for (int i = 0; i < 10; i++) {
        msg.data = rand() % 100;
        msgsnd(msgid, &msg, sizeof(msg.data), 0);
        printf("Produced: %d\n", msg.data);
        sleep(1);
    }
}

void consumer(int msgid) {
    struct message msg;

    for (int i = 0; i < 10; i++) {
        msgrcv(msgid, &msg, sizeof(msg.data), 1, 0);
        printf("Consumed: %d\n", msg.data);
        sleep(2);
    }
}

int main() {
    int msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);

    if (fork() == 0) {
        producer(msgid);
        exit(0);
    } else {
        consumer(msgid);
        wait(NULL);
    }

    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}

