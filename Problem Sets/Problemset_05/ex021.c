#include <stdio.h>

int n;

int binary_search(const int* array, int target) {
    int L, R, M; 
    int M_value;
    L = 0;
    R = n - 1;

    while (L <= R) {
        M = (L + R) / 2;
        M_value = array[M];

        if (target == M_value)
            return M;
        else if (target > M_value)
            L = M + 1;
        else
            R = M - 1;
    }

    return -1;
}

int main() {
    int m;
    scanf("%d", &n);
    
    int array[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    scanf("%d", &m);

    int val;
    scanf("%d", &val);

    if (binary_search(array, val) != -1)
        printf("yes");
    else
        printf("no");

    for (int i = 1; i < m; i++) {
        int val;
        scanf("%d", &val);

        if (binary_search(array, val) != -1)
            printf(" yes");
        else
            printf(" no");
    }

    printf("\n");
    return 0;
}
