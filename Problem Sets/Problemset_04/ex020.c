#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_STRING_LEN 7

int main() {
    char license[MAX_STRING_LEN];
    unsigned int num_cars = 0;
    size_t len;

    fgets(license, MAX_STRING_LEN, stdin);
    license[strcspn(license, "\n")] = '\0';

    len = strlen(license);
    for (int i = 0; i < len; i++) {
        num_cars += (license[i] - 'a' + 1) * pow(26, len - 1 -i);
    }

    printf("%d\n", num_cars);
    return 0;
}
