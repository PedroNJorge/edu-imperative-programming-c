#include <stdio.h>
#include <stdbool.h>

void perm(int n, int transitions[n][n], bool* used, int current_index, int* array, int* current_best) {
    if (current_index == n) {
        int count = 0;
        for (int i = 0; i < n-1; i++) {
            count += transitions[array[i]][array[i+1]];
        }

        if (count < *current_best)
            *current_best = count;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            array[current_index] = i;
            perm(n, transitions, used, current_index + 1, array, current_best);
            used[i] = false;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int transitions[n][n];
    bool used[n];
    int array[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &transitions[i][j]);
        }
    }

    int current_best = 10000000;
    perm(n, transitions, used, 0, array, &current_best);

    printf("%d\n", current_best);

    return 0;
}
