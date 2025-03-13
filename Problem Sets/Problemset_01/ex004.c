#include <stdio.h>

void horizontal(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2*n - 1; j++)
        {
            if (j < n-i-1 || j > n+i-1)
            {
                printf("_");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

void vertical(int n)
{
    for (int i = 0; i < 2*n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((j >= i +1 && i < n) || (j >= n-1 - i % n && i >= n))
            {
                printf("_");
            }
            else
            {
            printf("#");
            }
        }
        printf("\n");
    }
}

int main()
{
    int n, k = 0;

    scanf("%d %d", &n, &k);

    k ? vertical(n) : horizontal(n);
}
