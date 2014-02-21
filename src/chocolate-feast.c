#include <stdio.h>

/**
 * Solution to Chocolate Feast problem on HackerRank
 * https://www.hackerrank.com/challenges/chocolate-feast
 *
 * @author Marshall Farrier
 * @since 2014-02-20
 */

int main() {
    int test_cases, n, c, m, i, chocolates, wrappers, extra_wrappers;

    scanf("%d", &test_cases);
    for (i = 0; i < test_cases; i++) {
        scanf("%d %d %d", &n, &c, &m);
        chocolates = n / c;
        wrappers = chocolates;
        extra_wrappers = wrappers % m;
        while (wrappers >= m) {
            chocolates += wrappers / m;
            wrappers = extra_wrappers + wrappers / m;
            extra_wrappers = wrappers % m;
        }

        printf("%d\n", chocolates);
    }
    return 0;
}
