#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubblesort(int *AT, int *BT, int lo, int hi) {
    for (int i = lo; i < hi; i++) {
        for (int j = lo; j < hi - i; j++)
            if (AT[j] > AT[j + 1]) {
                swap(&AT[j], &AT[j + 1]);
                swap(&BT[j], &BT[j + 1]);
            }
    }
}

int main() {
    int n;
    printf("Enter number of processes ");
    scanf("%d", &n);
    int *AT = (int *) malloc(sizeof(int) * n);
    int *BT = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time of process %d ", i + 1);
        scanf("%d", &AT[i]);
        printf("Enter burst time of process %d ", i + 1);
        scanf("%d", &BT[i]);
    }
    bubblesort(AT, BT, 0, n - 1);
    int *CT = (int *) malloc(sizeof(int) * n);
    int *TAT = (int *) malloc(sizeof(int) * n);
    int *WT = (int *) malloc(sizeof(int) * n);
    CT[0] = AT[0] + BT[0];
    WT[0] = 0;
    int time = 0, flag, i = 0;
    while (i < n) {
        if (AT[i] > time)
            time = AT[i];
        flag = 1;
        for (int j = i; j < n; j++)
            if (time < AT[j]) {
                bubblesort(BT, AT, i, j - 1);
                flag = 0;
                break;
            }
        if (flag)
            bubblesort(BT, AT, i, n - 1);
        CT[i] = time + BT[i];
        time = CT[i];
        i += 1;
    }
    for (int i = 0; i < n; i++)
        TAT[i] = BT[i] + WT[i];
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum1 += TAT[i];
        sum2 += WT[i];
    }
    float average_tat = (float) sum1 / (float) n;
    float average_wt = (float) sum2 / (float) n;
    printf("P#\t AT\t BT\t WT\t TAT\t CT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i + 1, AT[i], BT[i], WT[i], TAT[i], CT[i]);
    printf("The average turnaround time: %f\n", average_tat);
    printf("The average waiting time: %f\n", average_wt);
    free(AT);
    free(BT);
    free(CT);
    free(WT);
    free(TAT);
}
