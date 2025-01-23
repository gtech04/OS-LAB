#include<stdio.h>

void main() {
    int n, i;
    int bt[20], wt[20], tat[20];
    float wavg = 0, tavg = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0; // Waiting time for the first process is 0

    // Calculate waiting time for each process
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        wavg += wt[i];
    }

    // Calculate turnaround time for each process
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        tavg += tat[i];
    }

    wavg /= n; // Average waiting time
    tavg /= n; // Average turnaround time

    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", wavg);
    printf("Average Turnaround Time: %.2f\n", tavg);
}
