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

struct word {
    int position;
    char term[WORD_SIZE + 1];
};

void counting_sort(struct word sorted[], struct word words[], size_t size) {
    int buckets[POSITIONS];
    int i;

    // initialize buckets
    for (i = 0; i < POSITIONS; i++) {
        buckets[i] = 0;
    }

    // count positions
    for (i = 0; i < size; i++) {
        buckets[words[i].position]++;
    }

    // convert to running totals
    for (i = 1; i < POSITIONS; i++) {
        buckets[i] += buckets[i - 1];
    }

    // feed words into sorted array
    for (i = size - 1; i >= 0; i--) {
        sorted[--buckets[words[i].position]] = words[i];
    }
}

int main() {
    int n, i, max;
    char garbage[WORD_SIZE + 1];

    scanf("%d", &n);
    struct word words[n];
    struct word sorted[n];

    max = n / 2;
    for (i = 0; i < max; i++) {
        scanf("%d %10s", &words[i].position, garbage);
        strcpy(words[i].term, "-");
    }
    for (; i < n; i++) {
        scanf("%d %10s", &words[i].position, words[i].term);
    }
    counting_sort(sorted, words, n);
    for (i = 0; i < n; i++) {
        printf("%s ", sorted[i].term);
    }
    return 0;
}
