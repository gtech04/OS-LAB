#include <stdio.h>
#include <stdlib.h>
void bestFit(int size[], int m, int process[], int n) {
    int alloc[n];

    for (int i = 0; i < n; i++)
        alloc[i] = -1;
    for (int i = 0; i < n; i++) {
        int best = -1;

        for (int j = 0; j < m; j++) {
            if (size[j] >= process[i]) {
                if (best == -1 || size[best] > size[j]) {
                    best = j;
                }
            }
        }

        if (best != -1) {
            alloc[i] = best;
            size[best] -= process[i]; 
        }
    }
    printf("\nBest Fit Allocation:\n");
    printf("Pro.No\tPro.Size\tBlock.No\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, process[i]);

        if (alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not allocated\n");
    }
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600}; 
    int processSize[] = {212, 417, 112, 426};     
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    bestFit(blockSize, m, processSize, n);

    return 0;
}
