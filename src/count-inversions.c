#include <stdio.h>

/**
 * Solution to Insertion Sort Advanced Analysis on HackerRank
 * https://www.hackerrank.com/challenges/insertion-sort
 *
 * @author Marshall Farrier
 * @since 2014-02-23
 */

void merge(int values[], int scratch[], int first_ix, int mid_ix, int last_ix) {
    int diff = mid_ix - first_ix,
        i, j, k;

    // copy first half of section into scratch
    for (i = 0; i <= diff; ++i) {
        scratch[i] = values[first_ix + i];
    }
    i = 0;
    j = mid_ix + 1;
    k = first_ix;
    while (i <= diff && j <= last_ix) {
        if (values[j] < scratch[i]) {
            values[k] = values[j++];
        } else {
            values[k] = scratch[i++];
        }
        ++k;
    }
    while (i <= diff) {
        values[k++] = scratch[i++];
    }
}

void merge_sort(int values[], int scratch[], int first_ix, int last_ix) {
    int diff = last_ix - first_ix;
    // base case 
    if (diff <= 0) return;
    int mid_ix = first_ix + diff / 2;
    merge_sort(values, scratch, first_ix, mid_ix);
    merge_sort(values, scratch, mid_ix + 1, last_ix);
    merge(values, scratch, first_ix, mid_ix, last_ix);
}

int main() {
    int n, i;

    scanf("%d", &n);
    printf("%d\n", n);

    int arr1[] = { 5, 2, 4, 3, 0 };
    int scratch[3];
    int arr2[] = { 1, 6, 2, 4, 3, 5 };
    merge_sort(arr1, scratch, 0, 4);
    merge_sort(arr2, scratch, 0, 5);
    for (i = 0; i < 5; ++i) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    for (i = 0; i < 6; ++i) {
        printf("%d ", arr2[i]);
    }
    return 0;
}
