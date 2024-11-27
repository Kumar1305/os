#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Function to check if a page is in a frame
int isInFrame(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page)
            return i;
    }
    return -1;
}

// FIFO Algorithm
void fifo(int pages[], int n, int capacity) {
    int frames[capacity], front = 0, faults = 0;
    for (int i = 0; i < capacity; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) {
        if (isInFrame(frames, capacity, pages[i]) == -1) {
            frames[front] = pages[i];
            front = (front + 1) % capacity;
            faults++;
        }
    }
    printf("FIFO: Page Faults = %d\n", faults);
}

// LRU Algorithm
void lru(int pages[], int n, int capacity) {
    int frames[capacity], age[capacity], faults = 0;
    for (int i = 0; i < capacity; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int idx = isInFrame(frames, capacity, pages[i]);
        if (idx == -1) {
            int lruIdx = 0;
            for (int j = 1; j < capacity; j++) {
                if (age[j] < age[lruIdx]) lruIdx = j;
            }
            frames[lruIdx] = pages[i];
            faults++;
            idx = lruIdx;
        }
        age[idx] = i;
    }
    printf("LRU: Page Faults = %d\n", faults);
}

// Optimal Algorithm
void optimal(int pages[], int n, int capacity) {
    int frames[capacity], faults = 0;
    for (int i = 0; i < capacity; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) {
        if (isInFrame(frames, capacity, pages[i]) == -1) {
            int replaceIdx = -1, farthest = -1;
            for (int j = 0; j < capacity; j++) {
                if (frames[j] == -1) {
                    replaceIdx = j;
                    break;
                }
                int nextUse = INT_MAX;
                for (int k = i + 1; k < n; k++) {
                    if (pages[k] == frames[j]) {
                        nextUse = k;
                        break;
                    }
                }
                if (nextUse > farthest) {
                    farthest = nextUse;
                    replaceIdx = j;
                }
            }
            frames[replaceIdx] = pages[i];
            faults++;
        }
    }
    printf("Optimal: Page Faults = %d\n", faults);
}

// LFU Algorithm
void lfu(int pages[], int n, int capacity) {
    int frames[capacity], freq[capacity], faults = 0;
    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
        freq[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int idx = isInFrame(frames, capacity, pages[i]);
        if (idx == -1) {
            int lfuIdx = 0;
            for (int j = 1; j < capacity; j++) {
                if (freq[j] < freq[lfuIdx] || (freq[j] == freq[lfuIdx] && frames[j] == -1))
                    lfuIdx = j;
            }
            frames[lfuIdx] = pages[i];
            freq[lfuIdx] = 1;
            faults++;
        } else {
            freq[idx]++;
        }
    }
    printf("LFU: Page Faults = %d\n", faults);
}

// Second Chance Algorithm
void secondChance(int pages[], int n, int capacity) {
    int frames[capacity], reference[capacity], front = 0, faults = 0;
    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
        reference[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int idx = isInFrame(frames, capacity, pages[i]);
        if (idx == -1) {
            while (reference[front]) {
                reference[front] = 0;
                front = (front + 1) % capacity;
            }
            frames[front] = pages[i];
            reference[front] = 1;
            front = (front + 1) % capacity;
            faults++;
        } else {
            reference[idx] = 1;
        }
    }
    printf("Second Chance: Page Faults = %d\n", faults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 4;

    fifo(pages, n, capacity);
    lru(pages, n, capacity);
    optimal(pages, n, capacity);
    lfu(pages, n, capacity);
    secondChance(pages, n, capacity);

    return 0;
}
