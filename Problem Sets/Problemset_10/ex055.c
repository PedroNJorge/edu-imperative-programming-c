#include <stdio.h>

int n, m;

void dfs(char grid[][m], int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '.') return;
	grid[i][j] = 'S';
	dfs(grid, i+1, j);
	dfs(grid, i, j+1);
	dfs(grid, i-1, j);
	dfs(grid, i, j-1);
}

int count_lakes(char grid[][m]) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '.') {
				dfs(grid, i, j);
				count++;
			}
		}
	}

	return count;
}

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

	printf("%d\n", count_lakes(grid));
	return 0;
}
