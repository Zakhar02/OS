#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    size_t size = 0;
    int *data = NULL;
    struct rusage mem;
    printf("| User CPU time (usec) | System CPU time (usec) | Page faults (w/o I/O) | Page faults (w/ I/O) | Context switches |\n");
    for (int i = 0; i < 10; ++i) {
        size += 10 * 1024 * 1024;
        data = realloc(data, size);
        memset(data, 0, size);
        getrusage(RUSAGE_SELF, &mem);
        printf("| %lld | %lld | %lld | %lld | %lld |\n", mem.ru_utime.tv_usec, mem.ru_stime.tv_usec,
               mem.ru_minflt, mem.ru_majflt, mem.ru_nvcsw + mem.ru_nivcsw);
        sleep(1);
    }
    free(data);
    return 0;
}
