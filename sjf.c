#include <stdio.h>

void SJF(int processes[], int n, int burst[]) {
    int wait[n], turnaround[n], total_wait = 0, total_turnaround = 0;
    int temp;

    // Sort burst times and processes
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (burst[i] > burst[j]) {
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    wait[0] = 0;

    for (int i = 1; i < n; i++) {
        wait[i] = wait[i - 1] + burst[i - 1];
    }

    for (int i = 0; i < n; i++) {
        turnaround[i] = wait[i] + burst[i];
        total_wait += wait[i];
        total_turnaround += turnaround[i];
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", processes[i], burst[i], wait[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_wait / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround / n);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst[] = {6, 8, 7};

    SJF(processes, n, burst);
    return 0;
}

/* gcc -o sjf sfj.c and then ./sjf */
