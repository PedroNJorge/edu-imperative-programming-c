#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int main() {
    int n;
    scanf("%d", &n);

    int heights[MAX_N];

    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    int cost = 0;
    for (int i = 0; i < n - 1; i++) {
        cost += abs(heights[i] - heights[i + 1]);
    }

    int min_cost = cost;
    int best_start = 0;

    for (int start = 1; start < n; start++) {
        cost = cost
            - abs(heights[start - 1] - heights[start])
            + abs(heights[(start + n - 2) % n] - heights[(start + n - 1) % n]);  // Nova transição

        if (cost < min_cost) {
            min_cost = cost;
            best_start = start;
        }
    }

    // Imprime a melhor sequência
    for (int i = 0; i < n; i++) {
        if (i<n-1) {printf("%d ", heights[(best_start + i) % n]);}
        else {printf("%d", heights[(best_start + i) % n]);}
    }
    printf("\n");

    return 0;
}
