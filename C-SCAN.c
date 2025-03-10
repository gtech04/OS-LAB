#include <stdio.h>

int main() {
    int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum = 0;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the position of the head: ");
    scanf("%d", &h);

    printf("Enter the total number of tracks: ");
    scanf("%d", &tot);

    // Initializing track values
    t[0] = 0;       // Beginning of the disk
    t[1] = h;       // Head position
    t[2] = tot - 1; // End of the disk

    printf("Enter the track positions: ");
    for (i = 3; i < n + 3; i++) {
        scanf("%d", &t[i]);
    }

    // Sorting the track numbers
    for (i = 0; i < n + 3; i++) {
        for (j = 0; j < (n + 2) - i; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Finding head position in sorted array
    for (i = 0; i < n + 3; i++) {
        if (t[i] == h) {
            j = i;
            break;
        }
    }

    p = 0;

    // Moving towards the right (towards `tot-1`)
    while (j < n + 3 && t[j] != tot - 1) {
        atr[p] = t[j];
        j++;
        p++;
    }
    atr[p] = t[j]; // Add `tot-1`
    p++;

    // Moving towards the left (back to `0`)
    i = 0;
    while (p < n + 3) {
        atr[p] = t[i];
        i++;
        p++;
    }

    // Printing traversal details
    printf("\nTracks Traversed   Difference between Tracks\n");
    printf("__________________________________________\n");

    for (j = 0; j < n + 2; j++) {
        d[j] = (atr[j] > atr[j + 1]) ? (atr[j] - atr[j + 1]) : (atr[j + 1] - atr[j]);
        sum += d[j];
        printf("%6d\t\t\t %6d\n", atr[j], d[j]);
    }

    printf("%6d\n", atr[j]);

    // Printing the average head movements
    printf("\nAverage head movements: %.2f\n", (float)sum / (n + 2));

    return 0;
}
