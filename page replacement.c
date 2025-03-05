//FIFO

#include <stdio.h>
void main()
{
int i,j,n,a[50],frame[10],no,k,avail,count=0;
printf("\n ENTER THE NUMBER OF PAGES:\n"); scanf("%d",&n);
printf("\n ENTER THE PAGE NUMBER :\n"); for(i=1;i<=n;i++)
scanf("%d",&a[i]);
printf("\n ENTER THE NUMBER OF FRAMES :"); scanf("%d",&no);
for(i=0;i<no;i++) frame[i]= -1;
j=0;printf("ref string\t page frames\n");
printf("___________________________________\n");
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
for(k=0;k<no;k++)
if(frame[k]!=-1)
printf("%d\t",frame[k]);
}
printf("\n");
}
printf("Page Fault Is %d\n",count);
}

//LRU

#include <stdio.h>

int fr[10]; // Frame array

void display(int frsize) {
    printf("\nFrames: ");
    for (int i = 0; i < frsize; i++) {
        if (fr[i] != -1)
            printf("%d ", fr[i]);
        else
            printf("- ");
    }
    printf("\n");
}

int main() {
    int n, frsize, i, j, index, min, pf = 0;
    
    printf("Enter the number of page references: ");
    scanf("%d", &n);
    
    int p[n]; // Page reference string
    printf("Enter the page reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    
    printf("Enter the number of frames: ");
    scanf("%d", &frsize);

    // Initialize frames to -1 (empty)
    for (i = 0; i < frsize; i++) {
        fr[i] = -1;
    }

    int recent[10]; // Tracks the last used time of each page

    for (j = 0; j < n; j++) {
        int flag1 = 0, flag2 = 0;

        // Check if the page is already in frames
        for (i = 0; i < frsize; i++) {
            if (fr[i] == p[j]) {
                flag1 = 1;
                flag2 = 1;
                recent[i] = j; // Update recent usage
                break;
            }
        }

        // If the page is NOT in memory
        if (flag1 == 0) {
            for (i = 0; i < frsize; i++) {
                if (fr[i] == -1) { // Empty slot found
                    fr[i] = p[j];
                    recent[i] = j;
                    flag2 = 1;
                    pf++; // Page fault
                    break;
                }
            }
        }

        // If no empty frame, find LRU page and replace it
        if (flag2 == 0) {
            min = recent[0];
            index = 0;

            for (i = 1; i < frsize; i++) {
                if (recent[i] < min) {
                    min = recent[i];
                    index = i;
                }
            }

            fr[index] = p[j];
            recent[index] = j;
            pf++; // Page fault
        }

        display(frsize);
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
