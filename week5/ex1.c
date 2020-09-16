#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct thread {
    int number;
};

void *show(void *n) {
    struct thread *new_thread = n;
    printf("Hello from thread %d\n", new_thread->number);
    return 0;
}

int main() {
    pthread_t tid;
    int n = 3;
    for (int i = 0; i < n; i++) {
        struct thread new_thread;
        new_thread.number = i;
        printf("Creating thread %d\n", i);
        pthread_create(&tid, NULL, &show, &new_thread);
        pthread_join(tid, NULL);
        printf("Thread %d joined\n", i);
    }
    pthread_exit(NULL);
}
