#include <stdio.h>

int L, C, I;

int count_alive(char board[L][C], int i, int j) {
    int n_alive = 0;

    // check ^
    if (i > 0)
        n_alive += (board[i-1][j] == 'O');

    // check <-
    if (j > 0)
        n_alive += (board[i][j-1] == 'O');

    // check <- and ^
    if (i > 0 && j > 0)
        n_alive += (board[i-1][j-1] == 'O');

    // check v
    if (i < L - 1)
        n_alive += (board[i+1][j] == 'O');

    // check <- and v
    if (i < L - 1 && j > 0)
        n_alive += (board[i+1][j-1] == 'O');

    // check ->
    if (j < C - 1)
        n_alive += (board[i][j+1] == 'O');

    // check -> and ^
    if (i > 0 && j < C - 1)
        n_alive += (board[i-1][j+1] == 'O');

    // check -> and v
    if (i < L - 1 && j < C - 1)
        n_alive += (board[i+1][j+1] == 'O');


    return n_alive;
}

int main() {
    int gen = 1, alive_neighbours = 0, is_alive = 0;

    scanf("%d %d %d", &L, &C, &I);
    getchar();

    char board[L][C];
    char copy[L][C];
    char c;

    // Read board
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            c = getchar();
            board[i][j] = copy[i][j] = c;
        }
        getchar();
    }

    while (gen <= I) {
        // Calculate which cells lives
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < C; ++j) {
                is_alive = (board[i][j] == 'O');
                alive_neighbours = count_alive(board, i, j);
                
                if (is_alive) {
                    if (alive_neighbours <= 1 || alive_neighbours >= 4)
                        copy[i][j] = '.';
                }
                else {
                    if (alive_neighbours == 3)
                        copy[i][j] = 'O';
                }
            }
        }

        // Refresh board
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < C; ++j) {
                board[i][j] = copy[i][j];
            }
        }
        ++gen;
    }

    // Print board
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
