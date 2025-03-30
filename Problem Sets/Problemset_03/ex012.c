#include <stdio.h>
#include <string.h>

#define MAX_WORD_SIZE 50

int LINS, COLS, num_words;

// if found return 1 else 0
int search_word(char board[LINS][COLS], int i, int j, char word[MAX_WORD_SIZE + 1], int marked[LINS][COLS]) {
    int len = strlen(word);
    int word_is_correct = 1;

    // Horizontal ->
    if (j + len <= COLS) {
        word_is_correct = 1;

        for (int k = 1; k < len; ++k) {
            if (board[i][j + k] != word[k]) {
                word_is_correct = 0;
                break;
            }
        }

        if (word_is_correct) {
            for (int k = 0; k < len; ++k) {
               marked[i][j + k] = 1; 
            }
            return 1;
        }
    }

    // Horizontal <-
    if (j - len + 1>= 0) {
        word_is_correct = 1;

        for (int k = 1; k < len; ++k) {
            if (board[i][j - k] != word[k]) {
                word_is_correct = 0;
                break;
            }
        }

        if (word_is_correct) {
            for (int k = 0; k < len; ++k) {
               marked[i][j - k] = 1; 
            }
            return 1;
        }
    }

    // Vertical (down)
    if (i + len <= LINS) {
        word_is_correct = 1;

        for (int k = 1; k < len; ++k) {
            if (board[i + k][j] != word[k]) {
                word_is_correct = 0;
                break;
            }
        }

        if (word_is_correct) {
            for (int k = 0; k < len; ++k) {
               marked[i + k][j] = 1; 
            }
            return 1;
        }
    }

    // Vertical (up)
    if (i - len + 1>= 0) {
        word_is_correct = 1;

        for (int k = 1; k < len; ++k) {
            if (board[i - k][j] != word[k]) {
                word_is_correct = 0;
                break;
            }
        }

        if (word_is_correct) {
            for (int k = 0; k < len; ++k) {
               marked[i - k][j] = 1; 
            }
            return 1;
        }
    }

    return 0;
}


int main() {
    int NUM = 1;
    char c;

    while (scanf("%d %d", &LINS, &COLS) == 2 && (LINS != 0 || COLS != 0)) {
        char board[LINS][COLS];
        int marked_board[LINS][COLS];
        getchar();
        
        // Read Board
        for (int i = 0; i < LINS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                board[i][j] = getchar();
                marked_board[i][j] = 0;
            }
            getchar();
        }

        scanf("%d", &num_words);
        getchar();

        char words[num_words][MAX_WORD_SIZE + 1];

        // Read words
        for (int i = 0; i < num_words; ++i) {
            int j = 0;
            while ((c = getchar()) != '\n') {
                words[i][j++] = c;
            }
            
            words[i][j] = '\0';
        }

        // Check words
        for (int i = 0; i < LINS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                c = board[i][j];
                for (int k = 0; k < num_words; ++k) {
                    if (c == words[k][0] && search_word(board, i, j, words[k], marked_board) == 1)
                        break;
                }
            }
        }

        // Print board
        printf("Input #%d\n", NUM);
        for (int i = 0; i < LINS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                printf("%c", marked_board[i][j] ? board[i][j] : '.');
            }
            printf("\n");
        }

        ++NUM;
    }

    return 0;
}
