#include <stdio.h>

int main() {
    int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum = 0;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the position of the head: ");
    scanf("%d", &h);

    t[0] = 0;  // Assuming the disk starts from 0
    t[1] = h;

    printf("Enter the tracks: ");
    for (i = 2; i < n + 2; i++) {
        scanf("%d", &t[i]);
    }

    // Sorting the track numbers
    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < (n + 2) - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Finding head position in sorted array
    for (i = 0; i < n + 2; i++) {
        if (t[i] == h) {
            j = i;
            k = i;
            break;
        }
    }

    p = 0;

    // Moving left towards zero
    while (j >= 0) {
        atr[p] = t[j];
        j--;
        p++;
    }

    // Moving right after reaching zero
    for (; k < n + 1; p++, k++) {
        atr[p] = t[k + 1];
    }

    // Printing the tracks traversed
    printf("\nTracks Traversed   Difference between Tracks\n");
    printf("__________________________________________\n");

    for (j = 0; j < n + 1; j++) {
        d[j] = (atr[j] > atr[j + 1]) ? (atr[j] - atr[j + 1]) : (atr[j + 1] - atr[j]);
        sum += d[j];
        printf("%6d\t\t\t %6d\n", atr[j], d[j]);
    }

    printf("%6d\n", atr[j]);

    // Printing the average head movements
    printf("\nAverage head movements: %.2f\n", (float)sum / (n + 1));

    return 0;
}
