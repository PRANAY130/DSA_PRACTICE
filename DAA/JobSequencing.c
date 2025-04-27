#include <stdio.h>
#include <stdlib.h>

#define N 5 // Number of jobs

int job_id[N] = {1, 2, 3, 4, 5};
int deadline[N] = {2, 1, 2, 1, 3};
int profit[N] = {100, 19, 27, 25, 15};

// Swap two jobs (helper function)
void swap(int i, int j) {
    int temp;

    temp = profit[i];
    profit[i] = profit[j];
    profit[j] = temp;

    temp = deadline[i];
    deadline[i] = deadline[j];
    deadline[j] = temp;

    temp = job_id[i];
    job_id[i] = job_id[j];
    job_id[j] = temp;
}

// Sort jobs by profit (descending order)
void sortJobs() {
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-i-1; j++) {
            if (profit[j] < profit[j+1])
                swap(j, j+1);
        }
    }
}

void jobSequencing() {
    sortJobs();

    int maxDeadline = 0;
    for (int i = 0; i < N; i++) {
        if (deadline[i] > maxDeadline)
            maxDeadline = deadline[i];
    }

    int slot[maxDeadline+1]; // slot[0] unused
    for (int i = 0; i <= maxDeadline; i++)
        slot[i] = -1; // Initially all slots are free

    int totalProfit = 0;

    printf("Selected Jobs: ");
    for (int i = 0; i < N; i++) {
        // Find a free slot for this job (starting from its deadline)
        for (int j = deadline[i]; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i; // Assign job to slot
                totalProfit += profit[i];
                printf("%d ", job_id[i]);
                break;
            }
        }
    }

    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    jobSequencing();
    return 0;
}
