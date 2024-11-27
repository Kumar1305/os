/* Round Robin Scheduling */

#include <stdio.h>

void RoundRobin(int processes[], int n, int burst[], int quantum) {
    int remaining[n], wait[n], turnaround[n], total_wait = 0, total_turnaround = 0, time = 0;

    for (int i = 0; i < n; i++) {
        remaining[i] = burst[i];
        wait[i] = 0;
    }

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                done = 0;
                if (remaining[i] > quantum) {
                    time += quantum;
                    remaining[i] -= quantum;
                } else {
                    time += remaining[i];
                    wait[i] = time - burst[i];
                    remaining[i] = 0;
                }
            }
        }
        if (done) break;
    }

    for (int i = 0; i < n; i++) {
        turnaround[i] = burst[i] + wait[i];
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
    int burst[] = {24, 3, 3};
    int quantum = 4;

    RoundRobin(processes, n, burst, quantum);
    return 0;
}

/* gcc -o roundrobin roundrobin.c and then ./roundrobin */
