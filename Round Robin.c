#include<stdio.h>

void main() {
    int i, j, n, bu[10], wa[10], tat[10], max, temp[10];
    float awt = 0, att = 0;
    printf("Enter the number of processes -- ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the Burst Time for process %d -- ", i + 1);
        scanf("%d", &bu[i]);
        temp[i] = bu[i];
    }

    printf("Enter the size of time slice -- ");
    scanf("%d", &max);

    for (i = 0; i < n; i++) {
        wa[i] = 0;
    }

    int t = 0;
    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (temp[i] > 0) {
                done = 0; // There is a pending process
                if (temp[i] > max) {
                    t += max;
                    temp[i] -= max;
                } else {
                    t += temp[i];
                    wa[i] = t - bu[i];
                    temp[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }

    for (i = 0; i < n; i++) {
        tat[i] = bu[i] + wa[i];
        awt += wa[i];
        att += tat[i];
    }

    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bu[i], wa[i], tat[i]);
    }

    printf("\nThe Average Turnaround Time is -- %.2f\n", att / n);
    printf("The Average Waiting Time is -- %.2f\n", awt / n);
}
