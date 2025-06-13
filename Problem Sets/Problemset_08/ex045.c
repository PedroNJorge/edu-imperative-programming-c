#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 7

bool run_sim(char board[][COLS], int gen, bool ply1);
int** get_moves(char board[][COLS]);
bool check_ply1_win(char board[][COLS]);

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    
    for (int game = 0; game < t; game++) {
        char board[ROWS][COLS] = {'.'};
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                board[i][j] = getchar();
            }
            getchar();
        }

        printf("%d\n", check_ply1_win(board));
        /*
        if (run_sim(board, 0, true)) printf("Yes\n");
        else printf("No\n");
        */
    }

    return 0;
}

bool run_sim(char board[][COLS], int gen, bool ply1) {
    if (gen == 4) return false;
    if (check_ply1_win(board)) return true;
    int** valid_moves = get_moves(board);
    size_t len = valid_moves[0][0];

    bool ply1_wins = false;
    int x, y;
    for (int i = 1; i < len; i++) {
        x = valid_moves[i][0];
        y = valid_moves[i][1];

        if (ply1) board[x][y] = 'A';
        else board[x][y] = 'B';

        if(run_sim(board, gen+1, !ply1)) return true;
    }

    return false;
}

int** get_moves(char board[][COLS]) {
    int** valid_moves = (int **)malloc(COLS+1 * sizeof(int *));
    for (int i = 0; i < COLS+1; i++) {
        valid_moves[i] = (int *)malloc(2 * sizeof(int));
    }
    int k = 1;
    for (int i = ROWS-1; i >= 0; i--) {
        for (int j = 0; j < COLS; j++) {
            if (i == ROWS-1 && board[i][j] == '.') {
                valid_moves[k][0] = i;
                valid_moves[k][1] = j;
                k++;
            } else {
                if (board[i][j] == '.' && board[i+1][j] != '.') {
                    valid_moves[k][0] = i;
                    valid_moves[k][1] = j;
                    k++;
                }
            }
        }
    }
    valid_moves[0][0] = k;

    return valid_moves;
}

bool check_ply1_win(char board[][COLS]) {
    int directions[5][2] = {{0,1}, {0,-1}, {-1,0}, {-1,1}, {-1,-1}};
    int count = 0;
    bool seen;
    for (int i = ROWS-1; i >= 0; i--) {
        seen = false;
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 'B') seen = true;
            else if (board[i][j] == 'A') {
                seen = true;
                count = 1;
                for (int k = 0; k < 5; k++) {
                    int x = directions[k][0], y = directions[k][1];
                    int a = 0;
                    while (board[i+x][j+y] == 'A' && a < 5) {
                        printf("(%d,%d) -> %c\n", i+x, j+y, board[i+x][j+y]);
                        count++;
                        a++;
                        printf("######\n");
                    }
                    if (count == 4) return true;
                    else count = 1;
                }
            }
        }
        if (!seen) return false;
    }
    return false;
}
