#include <stdio.h>
int main() {
int n, m, i, j, k, y, alloc[20][20], max[20][20], avail[50], ind = 0; printf("Enter the number of Processes: ");
scanf("%d", &n);
printf("Enter the number of Resources: ");
scanf("%d", &m);
// Input Allocation Matrix
printf("Enter the Allocation Matrix:\n");
for (i = 0; i < n; i++)
for (j = 0; j < m; j++)
scanf("%d", &alloc[i][j]);
// Input Maximum Requirement Matrix
printf("Enter the Max Matrix:\n");
for (i = 0; i < n; i++)
for (j = 0; j < m; j++)
scanf("%d", &max[i][j]);
// Input Available Resources
printf("Enter the Available Matrix:\n");
for (i = 0; i < m; i++)
scanf("%d", &avail[i]);
int finish[n], safesequence[n], work[m], need[n][m];
// Initialize finish array and work vector for (i = 0; i < n; i++) finish[i] = 0; for (i = 0; i < m; i++) work[i] = avail[i]; // Calculate NEED matrixprintf("\nNEED Matrix:\n");
for (i = 0; i < n; i++) {
for (j = 0; j < m; j++) {
need[i][j] = max[i][j] - alloc[i][j];
printf("%d ", need[i][j]);
}
printf("\n");
}
// ---------------------- DEADLOCK AVOIDANCE (Banker's Algorithm) ---------------------- int found;
for (k = 0; k < n; k++) {
found = 0;
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
if (found == 0) break;  // Stop if no process can be safely executed }
// Check if all processes finished (Safe State or Not) int safe = 1;
for (i = 0; i < n; i++) {
if (finish[i] == 0) {
safe = 0;  // Some processes remain unfinished break;
}
}
if (safe) {printf("\nSystem is in a SAFE state.\nSafe Sequence: ");
for (i = 0; i < ind; i++)
printf("P%d ", safesequence[i]);
printf("\n");
} else {
printf("\nSystem is NOT in a safe state. Possible DEADLOCK detected.\n");
// ---------------------- DEADLOCK DETECTION ----------------------
// Reset work and finish arrays for detection
for (i = 0; i < m; i++) work[i] = avail[i];
for (i = 0; i < n; i++) finish[i] = 0;
// Check for deadlock by seeing if any process can execute
int deadlocked = 1;
for (k = 0; k < n; k++) {
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
for (y = 0; y < m; y++)
work[y] += alloc[i][y];
finish[i] = 1;
deadlocked = 0;  // At least one process could execute
}
}
}
}
// If some processes remain unfinished, deadlock is confirmed if (deadlocked) {
printf("\nDEADLOCK DETECTED! The following processes are stuck: "); for (i = 0; i < n; i++) {
if (finish[i] == 0) printf("P%d ", i);
}
printf("\n"); } else {
printf("\nDeadlock was detected initially but resolved by process execution.\n");}
}
return 0;
}