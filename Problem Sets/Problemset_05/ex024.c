#include <stdio.h>

int n;

void swap(int* a, int* b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int gt_cmp(int a, int b) {
    int a_is_even = (a % 2 == 0);
    int b_is_even = (b % 2 == 0);

    if (a_is_even == b_is_even) {   // same parity
        if (a > b)
            return 1;
        else
            return 2;
    }
    else if (a_is_even && !b_is_even) {
        return 1;
    }
    return 2;
}

void insertion_search(int array[n]) {
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j > 0 && gt_cmp(array[j-1], array[j]) == 1) {
            swap(&array[j-1], &array[j]);
            j--;
        }
    }
}

int main() {
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    insertion_search(array);

    printf("%d", array[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", array[i]);
    }

    printf("\n");
    return 0;
}
