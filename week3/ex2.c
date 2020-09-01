#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubble_sort(int a[], int n) {
    do {
        int newn = 0;
        for (int i = 1; i < n; i++)
            if (a[i - 1] > a[i]) {
                swap(&a[i - 1], &a[i]);
                newn = i;
            }
        n = newn;
    } while (n >= 1);
}

int main() {
    printf("What is the size of the array?\n");
    int n;
    scanf("%d", &n);
    int *a;
    a = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    bubble_sort(a, n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
