#include <stdio.h>
#include <pthread.h>

void *print_hello(void *arg) {
    printf("Hello\n");
    return NULL;
}

void *print_world(void *arg) {
    printf("World\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, print_hello, NULL);
    pthread_create(&thread2, NULL, print_world, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
