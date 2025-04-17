#include <stdio.h>

int n;

int binary_search(const int array[], int target) {
    int L, R, M;
    L = 0;
    R = n-1;
    while (L < R) {
        M = (L + R) / 2;
        if (target == array[M])
            return array[M];
        else if (target < array[M])
            R = M - 1;
        else
            L = M + 1;
    }
    if (L == 0 && target < array[L])
        return 0;
    return array[L];
}

int main() {
    scanf("%d", &n);

    int cars[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i]);
    }

    int m;
    scanf("%d", &m);

    int drivers[m];

    scanf("%d", &drivers[0]);
    printf("%d", binary_search(cars, drivers[0]));
    for (int i = 1; i < m; i++) {
        scanf("%d", &drivers[i]);
        printf(" %d", binary_search(cars, drivers[i]));
    }

    printf("\n");
    return 0;
}
