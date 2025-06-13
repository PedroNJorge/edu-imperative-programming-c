#include <stdio.h>

int r, c;

int biggest_col(char grid[][c]);
void dfs(char grid[][c], int i, int j, int* col_size);

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    for (int gen = 0; gen < n; gen++) {
        scanf("%d %d", &r, &c);
        getchar();

        char grid[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                grid[i][j] = getchar();
            }
            getchar();
        }
        printf("%d\n", biggest_col(grid));
    }
    return 0;
}

int biggest_col(char grid[][c]) {
    int max = 0, temp;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '#') {
                temp = 0;
                dfs(grid, i, j, &temp);
                if (temp > max) max = temp;
            }
        }
    }

    return max;
}

void dfs(char grid[][c], int i, int j, int* col_size) {
    if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] != '#') return;
    (*col_size)++;

    grid[i][j] = 'S';
    dfs(grid, i+1, j, col_size);
    dfs(grid, i+1, j+1, col_size);
    dfs(grid, i+1, j-1, col_size);
    dfs(grid, i, j+1, col_size);
    dfs(grid, i, j-1, col_size);
    dfs(grid, i-1, j, col_size);
    dfs(grid, i-1, j+1, col_size);
    dfs(grid, i-1, j-1, col_size);
}
