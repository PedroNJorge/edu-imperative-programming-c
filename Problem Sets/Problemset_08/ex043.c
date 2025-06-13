#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXLEN 30

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    int result = 0;
    int last_seen;
    int mult = false;
    char c;
    while ((c = getchar()) != '\n') {
        if (c == ' ') continue;
        else if (c == '+') result += last_seen;
        else if (c == '*') mult = true;
        else if (mult == true) {
            last_seen *= atoi(&c);
            mult = false;
        }
        else last_seen = atoi(&c);
    }

    printf("%d\n", result + last_seen);

    return 0;
}
