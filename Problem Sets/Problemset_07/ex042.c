#include <stdio.h>
#include <stdbool.h>

int r, c;

bool pathfind(char grid[][c], bool visited[][c], int pos[]) {
    if (grid[pos[0]][pos[1]] == 'P') return true;
    if (pos[0] < 0 || pos[0] >= r || pos[1] < 0 || pos[1] >= c) return false;
    if (grid[pos[0]][pos[1]] == '#') return false;

    int dir[4][2] = {{-1,0},
                     {1,0},
                     {0,1},
                     {0,-1}};

    int next_x, next_y;
    int next_pos[2];
    for (int i = 0; i < 4; i++) {
        next_x = pos[0] + dir[i][0];
        next_y = pos[1] + dir[i][1];
        if (next_x < 0 || next_x >= r || next_y < 0 || next_y >= c) continue;
        if (!visited[next_x][next_y]) {
            visited[next_x][next_y] = true;
            next_pos[0] = next_x;
            next_pos[1] = next_y;
            if (pathfind(grid, visited, next_pos)) return true;
        }
    }

    

    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    int pos[2];
    for (int gen = 0; gen < n; gen++) {
        scanf("%d %d", &r, &c);
        getchar();

        char grid[r][c];
        bool visited[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                grid[i][j] = getchar();
                visited[i][j] = false;

                if (grid[i][j] == 'J') {
                    visited[i][j] = true;
                    pos[0] = i;
                    pos[1] = j;
                }
            }
            getchar();
        }

        if (pathfind(grid, visited, pos)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
