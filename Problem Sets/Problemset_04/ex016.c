#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_SIZE 5000

const char* binaryMorseCodes[] = {
    /* A */ "10111",         // .-
    /* B */ "111010101",     // -...
    /* C */ "11101011101",   // -.-.
    /* D */ "1110101",       // -..
    /* E */ "1",             // .
    /* F */ "101011101",     // ..-.
    /* G */ "111011101",     // --.
    /* H */ "1010101",       // ....
    /* I */ "101",           // ..
    /* J */ "1011101110111", // .---
    /* K */ "111010111",     // -.-
    /* L */ "101110101",     // .-..
    /* M */ "1110111",       // --
    /* N */ "11101",         // -.
    /* O */ "11101110111",   // ---
    /* P */ "10111011101",   // .--.
    /* Q */ "1110111010111", // --.-
    /* R */ "1011101",       // .-.
    /* S */ "10101",         // ...
    /* T */ "111",           // -
    /* U */ "1010111",       // ..-
    /* V */ "101010111",     // ...-
    /* W */ "101110111",     // .--
    /* X */ "11101010111",   // -..-
    /* Y */ "1110101110111", // -.--
    /* Z */ "11101110101",   // --..
    /* 0 */ "1110111011101110111", // -----
    /* 1 */ "10111011101110111",   // .----
    /* 2 */ "101011101110111",     // ..---
    /* 3 */ "1010101110111",       // ...--
    /* 4 */ "10101010111",         // ....-
    /* 5 */ "101010101",           // .....
    /* 6 */ "11101010101",         // -....
    /* 7 */ "1110111010101",       // --...
    /* 8 */ "111011101110101",     // ---..
    /* 9 */ "11101110111011101"    // ----.
};

char translated[MAX_MESSAGE_SIZE + 1] = {'\0'};
char tmp_morse_str[MAX_MESSAGE_SIZE + 1];
int j = 0, k = 0;

void translate() {
    for (int idx = 0; idx < 36; idx++) {
        if (strcmp(binaryMorseCodes[idx], tmp_morse_str) == 0) {
            if (idx < 26)
                translated[k++] = 'A' + idx;
            else
                translated[k++] = '0' + idx - 26;

            break;
        }
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE + 1];
    int len;
    int space_size = 0;

    fgets(message, sizeof(message), stdin);
    
    message[strcspn(message, "\n")] = '\0';
    len = strlen(message);
    
    char c;
    for (int i = 0; i < len; ++i) {
        c = message[i];

        if (c == '1') {
            if (space_size == 3) {
                tmp_morse_str[--j] = '\0';
                j = 0;

                translate();
            }
            else if (space_size == 7) {
                tmp_morse_str[--j] = '\0';
                j = 0;

                translate();
                translated[k++] = ' ';
            }

            space_size = 0;
            tmp_morse_str[j++] = c;
        }
        else {
            space_size++;
            if (space_size == 1)
                tmp_morse_str[j++] = c;
        }
    }

    if (j > 0) {
        tmp_morse_str[j] = '\0';
        translate();
    }

    printf("%s\n", translated);
    return 0;
}
