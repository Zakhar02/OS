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
    int n, quantum;
    printf("Enter number of processes ");
    scanf("%d", &n);
    printf("Enter the quantum ");
    scanf("%d", &quantum);
    int *AT = (int *) malloc(sizeof(int) * n);
    int *BT = (int *) malloc(sizeof(int) * n);
    int *BT_copy = (int *) malloc(sizeof(int) * n);
    int *CT = (int *) malloc(sizeof(int) * n);
    int *WT = (int *) malloc(sizeof(int) * n);
    int *TAT = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time of process %d ", i + 1);
        scanf("%d", &AT[i]);
        printf("Enter burst time of process %d ", i + 1);
        scanf("%d", &BT[i]);
    }
    bubblesort(AT, BT, 0, n - 1);
    for (int i = 0; i < n; i++)
        BT_copy[i] = BT[i];
    int time = 0, flag;
    while (1) {
        for (int i = 0; i < n; i++)
            if (BT[i] > 0 && AT[i] <= time) {
                if (BT[i] <= quantum) {
                    CT[i] = time + BT[i];
                    time = CT[i];
                    BT[i] = 0;
                } else {
                    BT[i] -= quantum;
                    time += quantum;
                }
            }
        flag = 1;
        for (int i = 0; i < n; ++i)
            if (BT[i] > 0) {
                flag = 0;
                break;
            }
        if (flag) break;
    }
    for (int i = 0; i < n; i++) {
        WT[i] = CT[i] - AT[i] - BT_copy[i];
        TAT[i] = BT_copy[i] + WT[i];
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum1 += TAT[i];
        sum2 += WT[i];
    }
    float average_tat = (float) sum1 / (float) n;
    float average_wt = (float) sum2 / (float) n;
    printf("P#\t AT\t BT\t WT\t TAT\t CT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i + 1, AT[i], BT_copy[i], WT[i], TAT[i], CT[i]);
    printf("The average turnaround time: %f\n", average_tat);
    printf("The average waiting time: %f\n", average_wt);
    free(AT);
    free(BT);
    free(BT_copy);
    free(WT);
    free(TAT);
    free(CT);
}
/*
 * FCFS - simple to implement, bad characteristics
 * RR - very good performance for interactive systems, better than FCFS, worse than SJN
 * SJN - very good performance for batch systems, better than RR and FCFS
 */