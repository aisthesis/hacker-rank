#include <stdio.h>
#include <stdlib.h>

/**
 * Solution to Insertion Sort Advanced Analysis on HackerRank
 * https://www.hackerrank.com/challenges/insertion-sort
 *
 * @author Marshall Farrier
 * @since 2014-02-23
 */

unsigned long merge(int values[], int scratch[], int first_ix, int mid_ix, int last_ix) {
    int diff = mid_ix - first_ix,
        i, j, k;
    unsigned long inversions = 0L;

    // copy first half of section into scratch
    for (i = 0; i <= diff; ++i) {
        scratch[i] = values[first_ix + i];
    }
    i = 0;
    j = mid_ix + 1;

    k = first_ix;
    while (i <= diff && j <= last_ix) {
        if (values[j] < scratch[i]) {
            inversions += j - k ;
            values[k] = values[j++];
        } else {
            values[k] = scratch[i++];
        }
        ++k;
    }
    while (i <= diff) {
        values[k++] = scratch[i++];
    }
    return inversions;
}

unsigned long  merge_sort(int values[], int scratch[], int first_ix, int last_ix) {
    int diff = last_ix - first_ix;
    // base case 
    if (diff <= 0) return 0L;
    int mid_ix = first_ix + diff / 2;
    unsigned long first_half_inversions, second_half_inversions, merge_inversions;

    first_half_inversions = merge_sort(values, scratch, first_ix, mid_ix);
    second_half_inversions = merge_sort(values, scratch, mid_ix + 1, last_ix);
    merge_inversions = merge(values, scratch, first_ix, mid_ix, last_ix);
    return first_half_inversions + second_half_inversions + merge_inversions;
}

int main() {
    int t, n, i, j, *values, *scratch;

    scanf("%d", &t);
    unsigned long answers[t];
    
    for (i = 0; i < t; ++i) {
        scanf("%d", &n);
        values = (int*) malloc(n * sizeof(int));
        scratch = (int*) malloc((n / 2 + 1) * sizeof(int));
        for (j = 0; j < n; ++j) {
            scanf("%d", &values[j]);
        }
            
        answers[i] = merge_sort(values, scratch, 0, n - 1);
        free(scratch);
        free(values);
    }
    for (i = 0; i < t; ++i) {
        printf("%lu\n", answers[i]);
    }
    return 0;
}
