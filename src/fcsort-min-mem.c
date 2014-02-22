#include <stdio.h>
#include <string.h>

/**
 * Solution to Full Counting Sort problem
 * https://www.hackerrank.com/challenges/countingsort4
 *
 * @author Marshall Farrier
 * @since 2014-02-21
 */

#define WORD_SIZE 10
#define POSITIONS 100

void sort(char *sorted[], int positions[], char words[][WORD_SIZE + 1], char dash[], size_t size) {
    int buckets[POSITIONS];
    int i;
    int word_count = size / 2;

    // initialize buckets
    for (i = 0; i < POSITIONS; i++) {
        buckets[i] = 0;
    }

    // count positions
    for (i = 0; i < size; i++) {
        buckets[positions[i]]++;
    }

    // convert to running totals
    for (i = 1; i < POSITIONS; i++) {
        buckets[i] += buckets[i - 1];
    }

    // feed words into sorted array
    for (i = word_count - 1; i >= 0; i--) {
        sorted[--buckets[positions[i + word_count]]] = words[i];
    }
    for (i = word_count - 1; i >= 0; i--) {
        sorted[--buckets[positions[i]]] = dash;
    }
}

int main() {
    int n, i, max;
    char garbage[WORD_SIZE + 1];
    char dash[] = "-";

    scanf("%d", &n);
    max = n / 2;
    int positions[n];
    char words[max][WORD_SIZE + 1];
    char *sorted[n];

    for (i = 0; i < max; i++) {
        scanf("%d %10s", &positions[i], garbage);
    }
    for (i = 0; i < max; i++) {
        scanf("%d %10s", &positions[i + max], words[i]);
    }
    sort(sorted, positions, words, dash, n);
    for (i = 0; i < n; i++) {
        printf("%s ", sorted[i]);
    }
    return 0;
}
