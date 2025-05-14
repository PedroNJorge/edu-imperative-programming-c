#include <stdio.h>

int find_love(int n) {
    int power = 1;
    while (power * 2 <= n) {
        power *= 2;
    }
    return 2 * (n - power) + 1;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", find_love(n));
    return 0;
}
