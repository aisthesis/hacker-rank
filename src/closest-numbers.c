#include <stdio.h>

/**
 * Solution to Closest Numbers on HackerRank
 * https://www.hackerrank.com/challenges/closest-numbers
 *
 * @author Marshall Farrier
 * @since 2014-02-28
 */

void swap(int values[], int i, int j) {
    int tmp = values[i];
    values[i] = values[j];
    values[j] = tmp;
}

int partition(int values[], int begin, int end) {
    int key = values[end],
        i = begin - 1,
        j;

    for (j = begin; j < end; ++j) {
        if (values[j] < key) {
            swap(values, ++i, j);
        }
    }
    swap(values, ++i, end);
    return i;
}

/**
 * @param end The last value in the second to be processed.
 * To sort an array of size n, we would call:
 * quick_sort(values, 0, n - 1);
 */
void quick_sort(int values[], int begin, int end) {
    if (begin >= end) return;
    int p = partition(values, begin, end);
    quick_sort(values, begin, p - 1);
    quick_sort(values, p + 1, end);
}

int main() {
    int values1[] = { 6, -1, 3, 5, 0 },
        values2[] = { 3, 2, 1, 0 },
        i;

    quick_sort(values1, 0, 4);
    quick_sort(values2, 0, 3);
    for (i = 0; i < 5; ++i) {
        printf("%d ", values1[i]);
    }
    printf("\n");
    for (i = 0; i < 4; ++i) {
        printf("%d ", values2[i]);
    }
    printf("\n");
    //int n;

    //scanf("%d", &n);
    return 0;
}
