#include <stdio.h>

// directions East, South, West, North
char directions[4] = {'E', 'S', 'O', 'N'};
int flag, LINS, COLS;
int N, M;

typedef struct Turtle {
    int x;
    int y;
    int pen_is_down;
    char direction;
} Turtle; 

Turtle turt = (Turtle){0, 0, 0, 'E'};

void rotate(char rotation) {
    int i;
    for (i = 0; i < 4; ++i) {
        if (directions[i] == turt.direction)
            break;
    }

    if (rotation == 'L') {
        turt.direction = directions[(i + 3) % 4];
    }
    else {
        turt.direction = directions[(i + 1) % 4];
    }
}

void walk(int n, char grid[LINS][COLS]) {
    int init_pos[2] = {turt.x, turt.y};
    int steps = 0;

    switch (turt.direction) {
        case 'N':
            if (turt.x - n < 0)
                turt.x = 0;
            else
                turt.x -= n;

            steps = init_pos[0] - turt.x;

            if (turt.pen_is_down) {
                for (int i = 1; i <= steps; ++i) {
                    grid[init_pos[0] - i][init_pos[1]] = '*';
                }
            }
            break;

        case 'S':
            if (turt.x + n > LINS - 1)
                turt.x = LINS - 1;
            else
                turt.x += n;

            steps = turt.x - init_pos[0];

            if (turt.pen_is_down) {
                for (int i = 1; i <= steps; ++i) {
                    grid[init_pos[0] + i][init_pos[1]] = '*';
                }
            }
            break;

        case 'O':
            if (turt.y - n < 0)
                turt.y = 0;
            else
                turt.y -= n;

            steps = init_pos[1] - turt.y;

            if (turt.pen_is_down) {
                for (int i = 1; i <= steps; ++i) {
                    grid[init_pos[0]][init_pos[1] - i] = '*';
                }
            }
            break;

        case 'E':
            if (turt.y + n > COLS - 1)
                turt.y = COLS - 1;
            else
                turt.y += n;

            steps = turt.y - init_pos[1];

            if (turt.pen_is_down) {
                for (int i = 1; i <= steps; ++i) {
                    grid[init_pos[0]][init_pos[1] + i] = '*';
                }
            }
    }
}

int check_pattern(char grid[LINS][COLS], char pattern[N][M]) {
    // Check if pattern exists in grid
    for (int i = 0; i <= LINS - N; i++) {
        for (int j = 0; j <= COLS - M; j++) {
            int match = 1;
            for (int k = 0; k < N && match; k++) {
                for (int l = 0; l < M && match; l++) {
                    if (pattern[k][l] != '.' && pattern[k][l] != grid[i + k][j + l])
                        match = 0;
                }
            }
            if (match) return 1;
        }
    }
    return 0;
}

int main() {
    int steps;
    int tiles_colored = 0, empty_rc = 0;
    int empty;
    
    scanf("%d", &flag);
    getchar();
    scanf("%d %d", &LINS, &COLS);
    getchar();

    char grid[LINS][COLS];
    for (int i = 0; i < LINS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            grid[i][j] = '.';
        }
    }

    // Read input
    char c;
    while ((c = getchar()) != 'e') {
        switch (c) {
            case 'U':
                turt.pen_is_down = 0;
                break;
            case 'D':
                turt.pen_is_down = 1;
                grid[turt.x][turt.y] = '*';
                break;
            case 'L':
                rotate('L');
                break;
            case 'R':
                rotate('R');
                break;
            case 'F':
                getchar();
                scanf("%d", &steps);
                walk(steps, grid);
        }
        getchar();
    }

    while (getchar() != '\n');

    scanf("%d %d", &N, &M);
    getchar();

    char pattern[N][M];

    // Read Pattern
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            pattern[i][j] = getchar();
            if (j < M - 1)
                getchar();
        }
        getchar();
    }

    // Handle flag
    switch (flag) {
        case 0:
            // Print grid
            for (int i = 0; i < LINS; ++i) {
                printf("%c", grid[i][0]);
                for (int j = 1; j < COLS; ++j) {
                    printf(" %c", grid[i][j]);
                }
                printf("\n");
            }
            break;

        case 1:
            // Calculate colored tiles
            for (int i = 0; i < LINS; ++i) {
                for (int j = 0; j < COLS; ++j) {
                    if (grid[i][j] == '*')
                        ++tiles_colored;
                }
            }

            // Check empty rows
            for (int i = 0; i < LINS; ++i) {
                empty = 1;
                for (int j = 0; j < COLS; ++j) {
                    if (grid[i][j] != '.') {
                        empty = 0;
                        break;
                    }
                }
                if (empty)
                    empty_rc++;
            }

            // Check empty columns
            for (int i = 0; i < LINS; ++i) {
                empty = 1;
                for (int j = 0; j < COLS; ++j) {
                    if (grid[j][i] != '.') {
                        empty = 0;
                        break;
                    }
                }
                if (empty)
                    empty_rc++;
            }

            float percentage = (float)tiles_colored * 100 / (LINS * COLS);
            printf("%.0f %d", percentage, empty_rc);
            break;

        case 2:
            if (check_pattern(grid, pattern))
                printf("Sim\n");
            else
                printf("Nao\n");
    }

    return 0;
}
