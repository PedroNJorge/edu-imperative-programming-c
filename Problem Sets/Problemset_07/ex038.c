#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int m;
    scanf("%d", &m);

    int b[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    int i, j;
    bool a_isactive, b_isactive;
    
    i = j = 0;
    a_isactive = b_isactive = true;

    if (a_isactive && b_isactive) {
        if (a[i] <= b[j]) {
            printf("%d", a[i]);
            i++;
        } else {
            printf("%d", b[j]);
            j++;
        }
        
    } else if (a_isactive) {
        printf("%d", a[i]);
        i++;

    } else {
        printf("%d", b[j]);
        j++;
    }

    while ((a_isactive = (i < n)) | (b_isactive = (j < m))) {
        if (a_isactive && b_isactive) {
            if (a[i] <= b[j]) {
                printf(" %d", a[i]);
                i++;
            } else {
                printf(" %d", b[j]);
                j++;
            }
            
        } else if (a_isactive) {
            printf(" %d", a[i]);
            i++;

        } else {
            printf(" %d", b[j]);
            j++;
        }
    }

    printf("\n");
    return 0;
}
