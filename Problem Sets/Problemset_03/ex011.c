#include <stdio.h>

int n;

int mainDiag(char board[n][n], char* c) {
    *c = board[0][0];
    if (*c == '.')
        return 0;

    for (int i = 1; i < n; ++i) {
        if (board[i][i] != *c)
            return 0;
    }
    return 1;
}

int secDiag(char board[n][n], char* c) {
    *c = board[0][n-1];
    if (*c == '.')
        return 0;

    for (int i = 1; i < n; ++i) {
        if (board[i][n-1-i] != *c)
            return 0;
    }
    return 1;
}

int row(char line[n], char* c) {
    *c = line[0];
    if (*c == '.')
        return 0;

    for (int i = 1; i < n; ++i) {
        if (line[i] != *c)
            return 0;
    }
    return 1;
}

int column(char board[n][n], int j, char* c) {
    *c = board[0][j];
    if (*c == '.')
        return 0;

    for (int i = 1; i < n; ++i) {
        if (board[i][j] != *c)
            return 0;
    }
    return 1;
}

int main() {
    scanf("%d", &n);
    getchar();

    char board[n][n];
    char c;

    // Read Board
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {   
            board[i][j] = getchar();
        }
        getchar();
    }

    // Check Main Diagonal
    if (mainDiag(board, &c)) {
        printf("Ganhou o %c\n", c);
        return 0;
    }

    // Check Sec Diagonal
    if (secDiag(board, &c)) {
        printf("Ganhou o %c\n", c);
        return 0;
    }


    // Check Rows & Columns
    for (int i = 0; i < n; ++i) {
        if (row(board[i], &c) || column(board, i, &c)) {
            printf("Ganhou o %c\n", c);
            return 0;
        }
    }

    // Check for '.'
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '.') {
                printf("Jogo incompleto\n");
                return 0;
            }
        }
    }
    
    printf("Empate\n");
    return 0;
}
