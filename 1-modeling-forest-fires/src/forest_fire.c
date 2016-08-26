#include <stdlib.h>
#include <stdbool.h>



void run_growth_phase(bool grid[][], int height, int width, double g) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (!grid[i][j] && _gen_rand() < g)
				grid[i][j] = true;
		}
	}
}

void run_fire_phase(bool grid[][], int height, int width, double f) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (grid[i][j] && _gen_rand() < f)
				_dfs(grid, height, width, i, j);
		}
	}
}

int count_trees(bool grid[][], int height, int width) {
	int count = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (grid[i][j])
				count++;
		}
	}
	return count;
}

static double _gen_rand() {
	return (double)rand() / RAND_MAX;
}

static void _dfs(bool grid[][], int height, int width, int i, int j) {
	if (i >= height || i < 0 || j >= width || j < 0 || !grid[i][j])
		return;
	grid[i][j] = false;
	int orientation[][] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
	for (int k = 0; k < 4; k++) {
		_dfs(grid, height, width, i + orientation[k][0], j + orientation[k][0]);
	}
}
