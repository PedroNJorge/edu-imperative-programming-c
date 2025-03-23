#include <stdio.h>

// Binomial Coefficient
unsigned long long int C(int n, int k) {
    if (k > n-k)
        k = n-k;

    unsigned long long int result = 1;
    for (int i = 0; i < k; i++) {
        result *= (n-i);
        result /= (i+1);
    }

    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    --n;

    printf("1");
    for (int i = 1; i <= n; i++) {
        printf(" %llu", C(n, i));
    }

    printf("\n");

    return 0;
}
