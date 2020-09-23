#include <stdio.h>
#include <stdlib.h>

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
    int tmp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++)
            if (AT[j] > AT[j + 1]) {
                tmp = AT[j];
                AT[j] = AT[j + 1];
                AT[j + 1] = tmp;
                tmp = BT[j];
                BT[j] = BT[j + 1];
                BT[j + 1] = tmp;
            }
    }
    int *CT = (int *) malloc(sizeof(int) * n);
    int *TAT = (int *) malloc(sizeof(int) * n);
    int *WT = (int *) malloc(sizeof(int) * n);
    CT[0] = AT[0] + BT[0];
    WT[0] = 0;
    for (int i = 1; i < n; i++) {
        if (AT[i] <= CT[i - 1])
            CT[i] = BT[i] + CT[i - 1];
        else
            CT[i] = AT[i] + BT[i];
        if (CT[i - 1] > AT[i])
            WT[i] = CT[i - 1] - AT[i];
        else WT[i] = 0;
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
