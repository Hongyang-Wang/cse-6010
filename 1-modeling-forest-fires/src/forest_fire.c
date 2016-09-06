#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static double _gen_rand(void);
static void _dfs(bool *grid, int height, int width, int i, int j);

static const int NEIGHBORS[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // north, south, west, east

void run_growth_phase(bool *grid, int height, int width, double g) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (!*(grid + i * width + j) && _gen_rand() < g)
				*(grid + i * width + j) = true;
		}
	}
}

void run_fire_phase(bool *grid, int height, int width, double f) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (*(grid + i * width + j) && _gen_rand() < f)
				_dfs(grid, height, width, i, j);
		}
	}
}

int count_trees(bool *grid, int height, int width) {
	int count = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (*(grid + i * width + j))
				count++;
		}
	}
	return count;
}

void print_forest(bool *grid, int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (*(grid + i * width + j))
				printf(" Y ");
			else
				printf(" . ");
		}
		printf("\n");
	}
}

static double _gen_rand() {
	return (double)rand() / RAND_MAX;
}

static void _dfs(bool *grid, int height, int width, int i, int j) {
	if (i >= height || i < 0 || j >= width || j < 0 || !*(grid + i * width + j))
		return;
	*(grid + i * width + j) = false;
	for (int k = 0; k < 4; k++) {
		_dfs(grid, height, width, i + NEIGHBORS[k][0], j + NEIGHBORS[k][1]);
	}
}
