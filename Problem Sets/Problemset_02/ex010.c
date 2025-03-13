#include <stddef.h>
#include <stdio.h>

int isInArray(int* array, size_t len, int n) {
    for (size_t i = 0; i < len; i++) {
        if (array[i] == n)
            return 1;
    }
    return 0;
}

int main() {
    int n, tmp;
    scanf("%d", &n);
    
    int uniq[n];
    size_t j = 0;

    // Get sequence and create array with the unique elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (!isInArray(uniq, j, tmp)) {
            uniq[j] = tmp;
            j++;
        }
    }

    // Print the unique elements
    for (size_t i = 0; i < j; i++) {
        printf("%d ", uniq[i]);
    }
    printf("\n");

    return 0;
}
