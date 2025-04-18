#include <stdio.h>

void hanoi(int n, int source, int target, int auxiliary) {
    if (n == 1) {
        printf("%d -> %d\n", source, target);
    }
    else {
        hanoi(n - 1, source, auxiliary, target);
        printf("%d -> %d\n", source, target);
        hanoi(n - 1, auxiliary, target, source);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    hanoi(n, 1, 3, 2);
    return 0;
}
