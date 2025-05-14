#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int piles[n];
    for (int i = 0; i < n; i++) {
        piles[i] = 0;
    }

    int x, s;
    for (int truck = 0; truck < m; truck++) {
        scanf("%d %d", &x, &s);
        x--;

        int i = x-1; int j = x+1;
        int k = 1;
        piles[x] += s;
        while ((i >= 0 || j < n) && s - k > 0) {
            if (i >= 0) piles[i] += s - k;
            if (j < n) piles[j] += s - k;

            i--;
            j++;
            k++;
        }
    }

    printf("%d", piles[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", piles[i]);
    }
    printf("\n");

    return 0;
}
