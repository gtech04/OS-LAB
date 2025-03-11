// OPTIMAL

#include <stdio.h>
int fr[10], n, m;
void display() {
    int i;
    for (i = 0; i < m; i++) {
        if (fr[i] != -1)
            printf("%d\t", fr[i]);
        else
            printf("-\t");
    }
    printf("\n");
}
int main() {
    int i, j, page[20], lg[10];
    int max, found, index, k, pf = 0;
    float pr;
    printf("Enter length of the reference string: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        fr[i] = -1;
    }
    pf = 0;
    for (j = 0; j < n; j++) {
        int flag1 = 0, flag2 = 0;
        for (i = 0; i < m; i++) {
            if (fr[i] == page[j]) {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }
        if (flag1 == 0) {
            for (i = 0; i < m; i++) {
                if (fr[i] == -1) { 
                    fr[i] = page[j];
                    flag2 = 1;
                    pf++; 
                    break;
                }
            }
        }
        if (flag2 == 0) {
            for (i = 0; i < m; i++) {
                lg[i] = 0;
            }
            for (i = 0; i < m; i++) {
                lg[i] = 1000; 
                for (k = j + 1; k < n; k++) {
                    if (fr[i] == page[k]) {
                        lg[i] = k - j;
                        break;
                    }
                }
            }

            found = 0;
            for (i = 0; i < m; i++) {
                if (lg[i] == 1000) {
                    index = i;
                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                max = lg[0];
                index = 0;
                for (i = 1; i < m; i++) {
                    if (lg[i] > max) {
                        max = lg[i];
                        index = i;
                    }
                }
            }

            fr[index] = page[j]; 
            pf++;
        }

        display();
    }

    printf("Number of page faults: %d\n", pf);
    pr = ((float)pf / n) * 100;
    printf("Page fault rate = %.2f%%\n", pr);

    return 0;
}

//  SCAN

#include <stdio.h>
int main() {
    int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum = 0;
    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);
    printf("Enter the position of the head: ");
    scanf("%d", &h);
    t[0] = 0; 
    t[1] = h;
    printf("Enter the tracks: ");
    for (i = 2; i < n + 2; i++) {
        scanf("%d", &t[i]);
    }
    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < (n + 2) - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n + 2; i++) {
        if (t[i] == h) {
            j = i;
            k = i;
            break;
        }
    }
    p = 0;
    while (j >= 0) {
        atr[p] = t[j];
        j--;
        p++;
    }
    for (; k < n + 1; p++, k++) {
        atr[p] = t[k + 1];
    }
    printf("\nTracks Traversed   Difference between Tracks\n");
    printf("__________________________________________\n");
    for (j = 0; j < n + 1; j++) {
        d[j] = (atr[j] > atr[j + 1]) ? (atr[j] - atr[j + 1]) : (atr[j + 1] - atr[j]);
        sum += d[j];
        printf("%6d\t\t\t %6d\n", atr[j], d[j]);
    }
    printf("%6d\n", atr[j]);
    printf("\nAverage head movements: %.2f\n", (float)sum / (n + 1));
    return 0;
}

//C-SCAN

#include <stdio.h>
int main() {
    int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum = 0;
    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);
    printf("Enter the position of the head: ");
    scanf("%d", &h);
    printf("Enter the total number of tracks: ");
    scanf("%d", &tot);
    t[0] = 0;       
    t[1] = h;      
    t[2] = tot - 1;
    printf("Enter the track positions: ");
    for (i = 3; i < n + 3; i++) {
        scanf("%d", &t[i]);
    }
    for (i = 0; i < n + 3; i++) {
        for (j = 0; j < (n + 2) - i; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n + 3; i++) {
        if (t[i] == h) {
            j = i;
            break;
        }
    }
    p = 0;
    while (j < n + 3 && t[j] != tot - 1) {
        atr[p] = t[j];
        j++;
        p++;
    }
    atr[p] = t[j];
    p++;
    i = 0;
    while (p < n + 3) {
        atr[p] = t[i];
        i++;
        p++;
    }
    printf("\nTracks Traversed   Difference between Tracks\n");
    printf("__________________________________________\n");
    for (j = 0; j < n + 2; j++) {
        d[j] = (atr[j] > atr[j + 1]) ? (atr[j] - atr[j + 1]) : (atr[j + 1] - atr[j]);
        sum += d[j];
        printf("%6d\t\t\t %6d\n", atr[j], d[j]);
    }
    printf("%6d\n", atr[j]);

    printf("\nAverage head movements: %.2f\n", (float)sum / (n + 2));
    return 0;
}
