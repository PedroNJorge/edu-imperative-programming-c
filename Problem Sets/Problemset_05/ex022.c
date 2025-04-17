#include <stdio.h>

int n;

void swap(int* a, int* b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
void bubble_sort(int array[n]) {
    for (int i = 0; i < n; i++) {
        int swapped = 0;

        for (int j = 0; j < n-1; j++) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}

void insertion_sort(int array[n]) {
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j > 0 && array[j-1] > array[j]) {
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

    // bubble_sort(array);
    insertion_sort(array);

    printf("%d", array[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", array[i]);
    }

    printf("\n");
    return 0;
}
