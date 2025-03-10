#include <stdio.h>

int main() {
    int n = 0;

    scanf("%d", &n);

    for (int i = 0; i < n*n; i++)
    {
        if (i % n == 0 && i > 0)
            printf("\n");

        if ((i % n + i/n) % 2 == 0)
        {
            printf("#");
        }
        else
        {
            printf("_");
        }
    }
    printf("\n");
    return 0;
}

