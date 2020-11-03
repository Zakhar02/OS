#include <stdio.h>

int main() {
    FILE *file = fopen("/dev/random", "r");
    char string[21];
    int a;
    for (int i = 0; i < 20; ++i) {
        a = fgetc(file);
        string[i] = a;
    }
    string[20] = '\0';
    for (int i = 0; i < 20; ++i)
        printf("%c", string[i]);
    printf("\n");
    fclose(file);
}
