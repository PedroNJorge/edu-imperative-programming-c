#include <stdio.h>

int n, m;

int count_lakes(char grid[][m]);
void dfs(char grid[][m], int i, int j);
void bulldoze(char grid[][m], char op, int dir);

int main() {
    scanf("%d %d", &n, &m);
    getchar();

    char grid[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = getchar();
        }
        getchar();
    }

    int q;
    scanf("%d", &q);
    getchar();
    
    printf("%d\n", count_lakes(grid));
    char op;
    int dir;
    for (int c = 0; c < q; c++) {
        op = getchar();
        scanf(" %d", &dir);
        getchar();
        bulldoze(grid, op, dir-1);
        printf("%d\n", count_lakes(grid));
    }

    return 0;
}

int count_lakes(char grid[][m]) {
    int num_lakes = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                num_lakes++;
                dfs(grid, i, j);
            }
        }
    }

    return num_lakes;
}

void dfs(char grid[][m], int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '.') return;
    grid[i][j] = 'S';

    dfs(grid, i+1, j);
    dfs(grid, i, j+1);
    dfs(grid, i, j-1);
    dfs(grid, i-1, j);
}

void bulldoze(char grid[][m], char op, int dir) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') grid[i][j] = '.';
        }
    }

    if (op == 'R') {
        for (int j = 0; j < m; j++) {
            grid[dir][j] = '.';
        }
    } else {
        for (int i = 0; i < n; i++) {
            grid[i][dir] = '.';
        }
    }
}
