#include <stdio.h>
#include <string.h>
#define MAX_WORD_LEN 11
#define MAX_GEN_WORD_LEN 10001

int main() {
    char str[MAX_GEN_WORD_LEN];
    int k;
    fgets(str, MAX_WORD_LEN, stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("%s\n", str);

    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        char buffer[MAX_GEN_WORD_LEN];
        char* pIN = buffer;
        char* pStr = str;

        while (*pStr != '\0') {
            if (*pStr == 'A') {
                strcpy(pIN, "AB");
                pIN += 2;
            } else if (*pStr == 'B') {
                *pIN = 'A';
                pIN++;
            }
            pStr++;
        }
        *pIN = '\0';
        strcpy(str, buffer);
        printf("%s\n", str);
    }
    return 0;
}
