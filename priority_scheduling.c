
#include<stdio.h>
void main()
{
    int p[20], bt[20], pr[20], wt[20], tat[20], i, k, n, temp;
    float wavg, tavg;
    printf("Enter the number of processes --- ");
    scanf("%d", &n);
    
    for(i=0; i<n; i++)
    {
        p[i] = i + 1;
        printf("Enter the Burst Time & Priority of Process %d --- ", i + 1);
        scanf("%d %d", &bt[i], &pr[i]);
    }
    
    for(i=0; i<n; i++)
    {
        for(k=i+1; k<n; k++)
        {
            if(pr[i] > pr[k])
            {
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;

                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                temp = pr[i];
                pr[i] = pr[k];
                pr[k] = temp;
            }
        }
    }
    
    wt[0] = 0;
    wavg = wt[0];
    tat[0] = bt[0];
    tavg = tat[0];
    
    for(i=1; i<n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wavg = wavg + wt[i];
        tavg = tavg + tat[i];
    }
    
    printf("PROCESS		PRIORITY	BURST TIME	WAITING TIME	TURNAROUND TIME\n");
    for(i=0; i<n; i++)
        printf("%d		%d		%d		%d		%d\n", p[i], pr[i], bt[i], wt[i], tat[i]);
    
    printf("Average Waiting Time is --- %f\n", wavg / n);
    printf("Average Turnaround Time is --- %f\n", tavg / n);
}
