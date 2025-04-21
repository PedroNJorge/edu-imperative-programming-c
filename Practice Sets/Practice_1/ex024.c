#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare_nums(const void* a, const void* b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    bool num1_is_even = (num1 % 2 == 0);
    bool num2_is_even = (num2 % 2 == 0);

    if (num1_is_even == num2_is_even) {
        return (num1 - num2);
    } else if (!num1_is_even) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    qsort(array, n, sizeof(int), compare_nums);

    printf("%d", array[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", array[i]);
    }
    printf("\n");

    return 0;
}
