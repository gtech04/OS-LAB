#include <stdio.h>
int main() {
int n, m, i, j, k, y, alloc[20][20], max[20][20], avail[20], ind = 0;
printf("Enter the number of Processes: ");
scanf("%d", &n);
printf("Enter the number of Resources: ");
scanf("%d", &m);  
printf("Enter the Allocation Matrix:\n");
for (i = 0; i < n; i++)
for (j = 0; j < m; j++)
scanf("%d", &alloc[i][j]);
printf("Enter the Max Matrix:\n");
for (i = 0; i < n; i++)
for (j = 0; j < m; j++)
scanf("%d", &max[i][j]);
printf("Enter the Available Resources:\n");
for (i = 0; i < m; i++)
scanf("%d", &avail[i]);
int finish[20] = {0}, safesequence[20], work[20], need[20][20];
for (i = 0; i < n; i++) {
for (j = 0; j < m; j++) {
need[i][j] = max[i][j] - alloc[i][j];
}
}
for (i = 0; i < m; i++) {
work[i] = avail[i];
}
for (k = 0; k < n; k++) {
int found = 0;
for (i = 0; i < n; i++) {
if (finish[i] == 0) {
int flag = 0;
for (j = 0; j < m; j++) {
if (need[i][j] > work[j]) {
flag = 1;
break;
}
}
if (flag == 0) {
safesequence[ind++] = i;
for (y = 0; y < m; y++)
work[y] += alloc[i][y];
finish[i] = 1;
found = 1;
}
}
}
if (found == 0) break;
    }
int safe = 1;
for (i = 0; i < n; i++) {
if (finish[i] == 0) {
safe = 0;  
 break;
}
}
if (safe) {
printf("\nSystem is in a SAFE state.\nSafe Sequence: ");
for (i = 0; i < ind; i++)
printf("P%d ", safesequence[i]);
printf("\n");
} else {
printf("\nSystem is NOT in a safe state. Possible DEADLOCK detected.\n");
printf("The following processes are stuck: ");
for (i = 0; i < n; i++) {
if (finish[i] == 0) {
 printf("P%d ", i);
}
}
printf("\n");
}
 return 0;
}\