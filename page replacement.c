//FIFO
#include<stdio.h>
void main()
{
int i,j,n,a[50],frame[10],no,k,avail,count=0; printf("\n ENTER THE NUMBER OF PAGES:\n");
scanf("%d",&n);
printf("\n ENTER THE PAGE NUMBER :\n");
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
printf("\n ENTER THE NUMBER OF FRAMES :");
scanf("%d",&no);
for(i=0;i<no;i++)
frame[i]= -1;
j=0;
printf("ref string\t page frames\n");
printf("______________________________ _____\n");
for(i=1;i<=n;i++)
{
printf("%d\t\t",a[i]);
avail=0;
for(k=0;k<no;k++)
if(frame[k]==a[i])
{
for(k=0;k<no;k++)
if(frame[k]!=-1)
printf("%d\t",frame[k]);
avail=1;
}
if (avail==0)
{
frame[j]=a[i];
j=(j+1)%no;
count++;
for(k=0;k<no;k++) if(frame[k]!=-1)
printf("%d\t",frame[k]);
}
printf("\n");
}
printf("Page Fault Is %d\n",count);
}

//LRU

#include <stdio.h>
#include <limits.h>

// Function to display the current frames
void display(int fr[], int frsize) {
    printf("\n");
    for (int i = 0; i < frsize; i++) {
        if (fr[i] != -1)
            printf("\t%d", fr[i]);
        else
            printf("\t-");
    }
}

// Function to find the least recently used (LRU) page
int find_LRU(int timestamps[], int size) {
    int min_time = INT_MAX, index = -1;
    for (int i = 0; i < size; i++) {
        if (timestamps[i] < min_time) {
            min_time = timestamps[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int n, frsize;
    
    // User input for number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    
    int p[n]; // Page reference string
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    
    // User input for number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &frsize);
    
    int fr[frsize]; // Frame array
    int timestamps[frsize];
    int time = 0, pf = 0;
    
    // Initialize frame array
    for (int i = 0; i < frsize; i++) {
        fr[i] = -1;
        timestamps[i] = 0;
    }
    
    for (int j = 0; j < n; j++) {
        int flag1 = 0;
        
        // Check if the page is already in the frame
        for (int i = 0; i < frsize; i++) {
            if (fr[i] == p[j]) {
                flag1 = 1;
                timestamps[i] = ++time; // Update timestamp since it's used recently
                break;
            }
        }
        
        // If not found, page fault occurs
        if (flag1 == 0) {
            int replace_index = -1;
            
            // Look for an empty slot first
            for (int i = 0; i < frsize; i++) {
                if (fr[i] == -1) { // Empty slot found
                    replace_index = i;
                    break;
                }
            }
            
            // If no empty slot, replace the LRU page
            if (replace_index == -1) {
                replace_index = find_LRU(timestamps, frsize);
            }
            
            fr[replace_index] = p[j];  // Replace page
            timestamps[replace_index] = ++time;
            pf++; // Increment page fault count
        }
        
        display(fr, frsize);
    }
    
    printf("\nTotal Page Faults: %d\n", pf);
    return 0;
}


// Optimal

#include <stdio.h>

int fr[10], n, m; // Frame array and size

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

    // Initialize frames to -1 (empty)
    for (i = 0; i < m; i++) {
        fr[i] = -1;
    }

    pf = 0; // Page fault counter

    // Implement Optimal Page Replacement Algorithm
    for (j = 0; j < n; j++) {
        int flag1 = 0, flag2 = 0;

        // Check if the page is already in frames
        for (i = 0; i < m; i++) {
            if (fr[i] == page[j]) {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        // If the page is not in memory
        if (flag1 == 0) {
            for (i = 0; i < m; i++) {
                if (fr[i] == -1) { // Empty frame found
                    fr[i] = page[j];
                    flag2 = 1;
                    pf++; // Page fault
                    break;
                }
            }
        }

        // If no empty frame, perform page replacement
        if (flag2 == 0) {
            for (i = 0; i < m; i++) {
                lg[i] = 0;
            }

            // Look ahead in the future page references
            for (i = 0; i < m; i++) {
                lg[i] = 1000; // Default high value for future lookup
                for (k = j + 1; k < n; k++) {
                    if (fr[i] == page[k]) {
                        lg[i] = k - j;
                        break;
                    }
                }
            }

            found = 0;
            for (i = 0; i < m; i++) {
                if (lg[i] == 1000) { // If a page is not found in the future
                    index = i;
                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                // Replace the page with the farthest future reference
                max = lg[0];
                index = 0;
                for (i = 1; i < m; i++) {
                    if (lg[i] > max) {
                        max = lg[i];
                        index = i;
                    }
                }
            }

            fr[index] = page[j]; // Replace page
            pf++; // Increment page fault count
        }

        display(); // Display frame content after each step
    }

    printf("Number of page faults: %d\n", pf);
    pr = ((float)pf / n) * 100;
    printf("Page fault rate = %.2f%%\n", pr);

    return 0;
}
