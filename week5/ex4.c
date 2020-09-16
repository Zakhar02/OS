#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int gcd(int a, int b) {
    return a == 0 ? b : gcd(b % a, a);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

void *func(void *vars) {
    int *args = (int *) vars;
    int a = args[0];
    int b = args[1];
    int multiple = lcm(a, b);
    printf("%d\n", multiple);
    free(vars);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    char *file = argv[1];
    long threads_count = strtol(argv[2], NULL, 10);
    FILE *in = fopen(file, "r");
    pthread_t *threads = malloc(threads_count * sizeof(pthread_t));
    int count = 0;
    while (1) {
        int *args = malloc(2 * sizeof(int));
        if (fscanf(in, "%d %d", args, args + 1) == EOF) {
            free(args);
            break;
        }
        if (count >= threads_count) {
            for (int i = 0; i < threads_count; i++)
                pthread_join(threads[i], NULL);
            count = 0;
        }
        pthread_create(threads + count, NULL, func, args);
        count += 1;
    }
    for (int i = 0; i < threads_count; i++)
        pthread_join(threads[i], NULL);
    free(threads);
    return 0;
}
