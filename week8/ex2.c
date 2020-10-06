#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    size_t size = 0;
    int *data = NULL;
    for (int i = 0; i < 10; ++i) {
        size += 10 * 1024 * 1024;
        data = realloc(data, size);
        memset(data, 0, size);
        sleep(1);
    }
    free(data);
    return 0;
}
