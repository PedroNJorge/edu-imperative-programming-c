#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 100000

int main() {
    char str[MAX_STRING_LEN + 1];
    int num_diff_char = 0;
    size_t len;
    int i, j;

    fgets(str, MAX_STRING_LEN, stdin);
    str[strcspn(str, "\n")] = '\0';

    len = strlen(str);
    i = 0;
    j = len - 1;

    while (i < j) {
        if (str[i++] != str[j--])
            num_diff_char++;
    }

    if (num_diff_char == 0)
        printf("Inspection passed\n");
    else
        printf("Oh boy, this needs a fix. You have to change at least %d characters\n", num_diff_char);

    return 0;
}
