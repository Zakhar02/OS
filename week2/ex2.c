#include <stdio.h>
#include <string.h>

int main() {
    printf("Enter string\n");
    char A[20];
    scanf("%s", A);
    int size = strlen(A);
    for (int i = size - 1; i >= 0; i--)
        printf("%c", A[i]);
}
