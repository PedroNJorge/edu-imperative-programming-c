#include <stdio.h>

long long int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n*factorial(n-1);
}

// Binomial Coefficient
long long int C(int n, int k) {
    return factorial(n) / (factorial(k)*factorial(n-k));    
}

int main() {
    int n;
    scanf("%d", &n);

    printf("1");
    for (int i = 1; i <= n; i++) {
        
    }

    return 0;
}
