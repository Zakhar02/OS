#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    if (input == NULL) return 2;
    char buffer[256];
    int e[50], a[50];
    int c[50][50], r[50][50];
    fgets(buffer, 256, input);
    char *b = buffer;
    int count = 0, tmp;
    while (*b != '\n') {
        tmp = strtol(b, &b, 10);
        count += 1;
        e[count] = tmp;
    }
    getc(input);
    fgets(buffer, 256, input);
    b = buffer;
    count = 0;
    while (*b != '\n') {
        tmp = strtol(b, &b, 10);
        count += 1;
        a[count] = tmp;
    }
    getc(input);
    int p_count = 0;
    while (strcmp(fgets(buffer, 256, input), "\n") != 0) {
        b = buffer;
        for (int i = 0; i < count; ++i) {
            tmp = strtol(b, &b, 10);
            c[p_count][i] = tmp;
        }
        p_count += 1;
    }
    for (int i = 0; i < p_count; ++i) {
        fgets(buffer, 256, input);
        b = buffer;
        for (int j = 0; j < count; ++j) {
            tmp = strtol(b, &b, 10);
            r[i][j] = tmp;
        }
    }
    int check[50] = {};
    while (1) {
        int flag = 0;
        for (int i = 0; i < p_count; ++i) {
            if (!check[i]) {
                int j;
                for (j = 0; j < count; ++j)
                    if (r[i][j] > a[j])
                        break;
                if (j == count) {
                    for (j = 0; j < count; ++j)
                        a[j] += r[i][j] + c[i][j];
                    flag = 1;
                    check[i] = 1;
                }
            }
        }
        if (flag == 0)
            break;
    }
    FILE *output = fopen("output.txt", "w");
    int deadlock = 0;
    for (int i = 0; i < p_count; ++i)
        if (!check[i]) {
            deadlock = 1;
            break;
        }
    if (deadlock) {
        fprintf(output, "Deadlock: ");
        for (int i = 0; i < p_count; ++i)
            if (!check[i])
                fprintf(output, "%d ", i);
    } else
        fprintf(output, "No deadlock");
    return 0;
}
