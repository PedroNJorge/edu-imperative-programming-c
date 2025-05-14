#include <stdio.h>

// print an array of size n (assume size >= 1)
void print_array(int a[], int n) {
  printf("[%d", a[0]);
  for (int i=1; i<n; i++)
    printf(",%d", a[i]);
  printf("]\n");
}

// Forward declaration of function to implement
void shift(int array[], int n, int k) {
    int buffer[n];
    int tmp;

    for (int i = 0; i < n; i++) {
        tmp = (i - k) % n;
        if (tmp < 0) tmp += n;
        buffer[i] = array[tmp];
    }

    for (int i = 0; i < n; i++) {
        array[i] = buffer[i];
    }
}

int main(void) {

  // Read array of n integers
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i=0; i<n; i++)
    scanf("%d", &a[i]);

  // Read integer, shift the array and print before and after
  int k;
  scanf("%d", &k);
  print_array(a, n);
  shift(a, n, k);
  printf("After shift(a,%d,%d):\n", n, k);
  print_array(a, n);

  return 0;
}
