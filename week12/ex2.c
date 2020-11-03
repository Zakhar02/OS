#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int count = 0;
    if (argc > 1 && argv[1] == "-a")
        count = 1;
    int file_count = argc - count - 1;
    FILE **files = malloc(file_count * sizeof(FILE));
    const char *mode = count ? "a" : "w";
    for (int i = 0; i < file_count; ++i)
        files[i] = fopen(argv[i + count + 1], mode);
    char buffer[128];
    while (fgets(buffer, 127, stdin) != NULL) {
        printf("%s", buffer);
        for (int i = 0; i < file_count; ++i)
            fprintf(files[i], "%s", buffer);
    }
    for (int i = 0; i < file_count; ++i)
        fclose(files[i]);
    free(files);
}
