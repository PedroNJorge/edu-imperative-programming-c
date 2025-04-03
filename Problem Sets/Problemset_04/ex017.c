#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 10000


void replace(char* str, const char* old, const char* new) {
    char buffer[MAX_STRING_LEN];
    char *pBuffer = buffer;
    const char *pStr = str;
    const char *pFound = strstr(str, old);
    
    if (pFound == NULL) {
        // No occurrence found, do nothing
        return;
    }

    // Copy the part before the found substring into buffer
    size_t len_before = pFound - pStr;
    strncpy(pBuffer, pStr, len_before);
    pBuffer += len_before;
    
    // Copy the new substring
    strcpy(pBuffer, new);
    pBuffer += strlen(new);
    
    // Copy the rest of the string after the found substring
    pStr = pFound + strlen(old);
    strcpy(pBuffer, pStr);
    
    // Copy the result back to the original string
    strcpy(str, buffer);
}

int main() {
    char original_str[MAX_STRING_LEN];
    char s[MAX_STRING_LEN], t[MAX_STRING_LEN];
    int c;

    fgets(original_str, MAX_STRING_LEN, stdin);
    original_str[strcspn(original_str, "\n")] = '\0';

    scanf("%d", &c);
    getchar();

    for (int i = 0; i < c; i++) {
        fgets(s, MAX_STRING_LEN, stdin);
        s[strcspn(s, "\n")] = '\0';        
        
        fgets(t, MAX_STRING_LEN, stdin); 
        t[strcspn(t, "\n")] = '\0';

        replace(original_str, s, t);
    }

    printf("%s\n", original_str);
    return 0;
}
