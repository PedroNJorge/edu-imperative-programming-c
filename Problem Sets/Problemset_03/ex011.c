#include <stdio.h>

int check_win(char c, int piece_count, int n) {
    if (piece_count == n-1) {
        printf("Ganhou o %c\n", c);
        return 1;
    }
    return 0;
}



void check_free_space(char c, int* free_space) {
    if (c == '.')
        *free_space = 1;
}

int main() {
    int n, piece_count = 0, free_space = 0, won = 0;
    scanf("%d", &n);

    // Get the \n from the scanf
    getchar();

    char board[n][n];
    char c;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {   
            board[i][j] = getchar();
        }
        // Get the \n from the line entered
        getchar();
    }

    // Check Diagonals
    c = board[0][0];
    for (int i = 0; i < n; ++i) {
        if (board[i][i] != c) {
            piece_count = 0;
            check_free_space(board[i][i], &free_space);
            break;
        }
        else {
            ++piece_count;
        }
    }

    if (check_win(c, piece_count, n))
        return 0;

    piece_count = 0;
    // Check Lines and Columns
    for (int i = 0; i < n; ++i) {
            c = board[i][0];

            if (c == '.') {
                free_space = 1;
            }
            else {
                for (int j = 1; j < n; ++j) {
                    if (board[i][j] != c) {
                        piece_count = 0;
                        check_free_space(board[i][j], &free_space);
                        break;
                    }
                    else {
                        ++piece_count;
                    }
                }

                if (check_win(c, piece_count, n))
                    return 0;
            }

            c = board[0][i];

            if (c == '.') {
                free_space = 1;
            }
            else {
                for (int j = 1; j < n; ++j) {
                    if (board[j][i] != c) {
                        piece_count = 0;
                        check_free_space(board[j][i], &free_space);
                        break;
                    }
                    else {
                        ++piece_count;
                    }
                }

                if (check_win(c, piece_count, n))
                    return 0;
            }
    }

    if (free_space)
        printf("Jogo incompleto\n");
    else
        printf("Empate\n");

    return 0;
}
