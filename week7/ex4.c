#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int n1, int n2) {
    return (n1 < n2) ? n1 : n2;
}

int *my_realloc(int *a, int n1, int n2) {
    if (n2 == 0) {
        free(a);
        return NULL;
    }
    if (a == NULL)
        return malloc(sizeof(int) * n2);
    int *a2 = malloc(sizeof(int) * n1);
    memcpy(a2, a, min(n1, n2));
    free(a);
    return a2;
}

int main() {
    int n1, n2;
    printf("Enter old array size: ");
    scanf("%d", &n1);
    printf("Enter new array size: ");
    scanf("%d", &n2);
    int *arr = (int *) malloc(sizeof(int) * n1);
    for (int i = 0; i < n1; ++i)
        arr[i] = i;
    arr = my_realloc(arr, n1, n2);
    for(int i = 0; i < n2; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}
