#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a: b;
}

void draw(int t) {
    int i, j, k;

    for (i = 0; i < t; i++) {
        printf("#");
    }
    printf("\n");
    for (i = 1; i < t-1; i++) {
        for (j = 0; j < min(t - i - 1, i); j++) {
            printf(".");
        }
        printf("#");
        for (k = 1; k < abs(t - 2*i - 1); k++) {
            printf(".");
        }
        if (i != t/2)
            printf("#");
        for (k = t - j; k < t; k++) {
            printf(".");
        }
        printf("\n");
    }
    for (i = 0; i < t; i++) {
        printf("#");
    }
    printf("\n");
}

int main() {
    int n, t;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        draw(t);
    }

    return 0;
}
