#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *read() {
    int size = 16;
    char *command = malloc(sizeof(char) * size);
    int i = 0;
    char tmp;
    while (1) {
        tmp = getchar();

        if (tmp == ' ' || tmp == '\n')
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
