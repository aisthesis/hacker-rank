#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Solution to Full Counting Sort problem
 * https://www.hackerrank.com/challenges/countingsort4
 *
 * @author Marshall Farrier
 * @since 2014-02-21
 */

#define CSTRING_SIZE 11
#define POSITIONS 100

void sort(char *sorted_one[], char *sorted_two[], int dash_positions[], 
        int word_positions[], char *words[], char dash[], size_t size) {
    int buckets[POSITIONS];
    int i;

    // initialize buckets
    for (i = 0; i < POSITIONS; i++) {
        buckets[i] = 0;
    }

    // count positions
    for (i = 0; i < size; i++) {
        buckets[dash_positions[i]]++;
        buckets[word_positions[i]]++;
    }

    // convert to running totals
    for (i = 1; i < POSITIONS; i++) {
        buckets[i] += buckets[i - 1];
    }

    // feed words into sorted arrays
    // word positions
    for (i = size - 1; i >= 0; i--) {
        if (--buckets[word_positions[i]] >= size) {
            sorted_two[buckets[word_positions[i]] - size] = words[i];
        } else {
            sorted_one[buckets[word_positions[i]]] = words[i];
        }
    }
    // dash positions
    for (i = size - 1; i >= 0; i--) {
        if (--buckets[dash_positions[i]] >= size) {
            sorted_two[buckets[dash_positions[i]] - size] = dash;
        } else {
            sorted_one[buckets[dash_positions[i]]] = dash;
        }
    }
}

int main() {
    int n, i, max;
    // int trash;
    char garbage[CSTRING_SIZE];
    char dash[] = "-";

    scanf("%d", &n);
    max = n / 2;
    // arrays have to be divided up for test case where n = 1M
    int word_positions[max], dash_positions[max];

    char *words[max];
    for (i = 0; i < max; i++) {
        words[i] = (char*) malloc(CSTRING_SIZE);
    }
    char **sorted_one = (char**) malloc(max * sizeof(char*));
    char **sorted_two = (char**) malloc(max * sizeof(char*));
    for (i = 0; i < max; i++) {
        scanf("%d %10s", &dash_positions[i], garbage);
    }
    for (i = 0; i < max; i++) {
        scanf("%d %10s", &word_positions[i], words[i]);
    }
    sort(sorted_one, sorted_two, dash_positions, word_positions, words, dash, max);
    for (i = 0; i < max; i++) {
        printf("%s ", sorted_one[i]);
    }
    for (i = 0; i < max; i++) {
        printf("%s ", sorted_two[i]);
    }
    for (i = 0; i < max; i++) {
        free(words[i]);
    }
    free(sorted_one);
    free(sorted_two);
    return 0;
}
