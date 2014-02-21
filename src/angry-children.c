#include <stdio.h>

/**
 * Solution to Angry Children problem
 * https://www.hackerrank.com/challenges/angry-children
 *
 * @author Marshall Farrier
 * @since 2014-02-20
 */

void insertion_sort(int values[], size_t size) {
    int i, j, key;

    for (j = 1; j < size; j++) {
        key = values[j];
        i = j - 1;
        while (i >= 0 && values[i] > key) {
            values[i + 1] = values[i];
            i--;
        }
        values[i + 1] = key;
    }
}

void swap(int values[], int i, int j) {
    int tmp = values[i];
    values[i] = values[j];
    values[j] = tmp;
}

int partition(int values[], int first, int last) {
    int x = values[last];
    int i = first;
    for (int j = first; j < last; j++) {
        if (values[j] < x) {
            swap(values, i++, j);
        }
    }
    swap(values, i, last);
    return i;
}

void quick_sort(int values[], int first, int last) {
    if (first < last) {
        int p = partition(values, first, last);
        quick_sort(values, first, p - 1);
        quick_sort(values, p + 1, last);
    }
}

void sort(int values[], size_t size) {
    quick_sort(values, 0, size - 1);
}

int main() {
    int n, k, i, unfairness_min;

    scanf("%d", &n);
    scanf("%d", &k);

    int packet_sizes[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &packet_sizes[i]);
    }
    sort(packet_sizes, n);
    unfairness_min = packet_sizes[k - 1] - packet_sizes[0];
    for (i = k; i < n; i++) {
        if (packet_sizes[i] - packet_sizes[i - k + 1] < unfairness_min) {
            unfairness_min = packet_sizes[i] - packet_sizes[i - k + 1];
        }
    }
    printf("%d\n", unfairness_min);
    return 0;
}
