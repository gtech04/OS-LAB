//FIFO

#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[20], n, head, i, seek = 0, diff;
    float avg;

    // Taking input for queue size
    printf("Enter the size of queue request: ");
    scanf("%d", &n);

    // Taking input for disk request queue
    printf("Enter the queue of disk positions to be read:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // Taking input for initial head position
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // Processing disk scheduling using FCFS
    printf("\nSeek Sequence:\n");
    printf("%d -> ", head); // Start from head position

    for (i = 0; i < n; i++) {
        diff = abs(queue[i] - head);
        seek += diff;
        printf("%d (%d) -> ", queue[i], diff);
        head = queue[i]; // Move head to next position
    }

    // Remove last arrow and print final results
    printf("END\n");
    printf("Total seek time: %d\n", seek);
    
    avg = (float)seek / n;
    printf("Average seek time: %.2f\n", avg);

    return 0;
}
