#include <stdio.h>

void FCFS(int processes[], int n, int burst[]) {
    int wait[n], turnaround[n], total_wait = 0, total_turnaround = 0;

    wait[0] = 0; // Waiting time for the first process is 0

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
    int burst[] = {5, 8, 12};

    FCFS(processes, n, burst);
    return 0;
}
#gcc -o fcfs fcfs.c
#./fcfs
