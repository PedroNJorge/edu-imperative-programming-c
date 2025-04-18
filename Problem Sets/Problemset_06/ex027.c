#include <stdio.h>

void combinations(int n, char* str, int curr_index) {
    if (curr_index == n) {
        str[n] = '\0';
        printf("%s\n", str);
        return;
    }

    str[curr_index] = '0';
    combinations(n, str, curr_index+1);

    str[curr_index] = '1';
    combinations(n, str, curr_index+1);
}

int main() {
    int n;
    scanf("%d", &n);

    char str[n+1];
    combinations(n, str, 0); 
    return 0;
}
