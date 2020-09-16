#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct {
    int count;
    int capacity;
    int *array;
} b;

void *producer(void *vararg) {
    while (1) {
        while (b.count == b.capacity);
        b.array[b.count] = b.count;
        b.count += 1;
        printf("Produced %d\n", b.count);
    }
}

void *consumer(void *vararg) {
    while (1) {
        while (b.count == 0);
        b.array[b.count] = 0;
        b.count -= 1;
        printf("Consumed %d\n", b.count);
    }
}

int main() {
    b.capacity = 5;
    b.count = 0;
    b.array = (int *) malloc(b.capacity * sizeof(int));
    pthread_t prod, cons;
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    return 0;
}
