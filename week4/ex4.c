#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *extend(int size, char *command) {
    char *new = malloc(sizeof(char) * 2 * size);
    strcpy(new, command);
    free(command);
    return new;
}

char *read() {
    int size = 16;
    char *command = malloc(sizeof(char) * size);
    int i = 0;
    char tmp;
    while (1) {
        tmp = getchar();
        if (i + 1 == size) {
            command = extend(size, command);
            size *= 2;
        }
        if (tmp == '\n')
            break;
        else
            command[i] = tmp;
        i += 1;
    }
    command[i] = '\0';
    return command;
}

int main() {
    printf("Hello! Enter your command!\n");
    char *command;
    while (1) {
        command = read();
        if (strcmp("exit", command) == 0) {
            free(command);
            break;
        }
        system(command);
        free(command);
    }
}

