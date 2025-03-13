#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, tmp, min = 1000;
    scanf("%d", &n);

    int s1[n], s2[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &s1[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &s2[i]);
        if ((tmp = abs(s2[i] - s1[i])) < min)
            min = tmp;
    }

    printf("%d\n", min);

    return 0;
}
