#include <stdio.h>
#include <stdbool.h>

void perm(int n, int* array, bool* used, int curr_index) {
    if (curr_index == n) {
        printf("%d", array[0]);
        for (int i = 1; i < n; i++) {
            printf(" %d", array[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;
            array[curr_index] = i;
            perm(n, array, used, curr_index + 1);
            used[i] = false;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int array[n];
    bool used[n];
    perm(n, array, used, 0);
    return 0;
}
