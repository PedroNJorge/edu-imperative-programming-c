#include <stdio.h>

int min(int a, int b) {
    if (a > b)
        return b;
    else
        return a;
}

int main() {
    int n, m, nIsActive, mIsActive;
    int i, j, k;
    scanf("%d %d", &n, &m);
    
    int a[n], b[m], c[n+m];

    // Get sequences
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (j = 0; j < m; j++) {
        scanf("%d", &b[j]);
    }
    i = j = k = 0; 
    // Merge the sequences a, b into c with two pointers i, j
    c[0] = min(a[0], b[0]);
    printf("%d", c[0]);
        if (a[i] == c[k])
            i++;
        else
            j++;
    ++k;
    
    while ((nIsActive = i < n) | (mIsActive = j < m)) {
        if (nIsActive && mIsActive) {
            c[k] = min(a[i], b[j]);
            printf(" %d", c[k]);

            if (a[i] == c[k])
                i++;
            else
                j++;
        }
        else if (nIsActive) {
            c[k] = a[i];
            printf(" %d", c[k]);
            i++;
        }
        else {
            c[k] = b[j];
            printf(" %d", c[k]);
            j++;
        }
        ++k;
    }

    //printf("\b");
    printf("\n");
    
    return 0;
}
