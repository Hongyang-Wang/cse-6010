/*
 ============================================================================
 Name        : main.c
 Author      : Hongyang Wang
 Version     : 1.0.0
 Copyright   : © Fall 2016 CSE 6010 Hongyang Wang
 Description : Cellular automation for forest fires
 Date		 : Aug 25 - Sep 9, 2016
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "forest_fire.h"

int main(int argc, char *argv[]) {

	// 1. get input args
	if (argc != 6) {
		printf("The program takes in 5 arguments: height, width, g, f and iter_num");
		return -1;
	}

	int height = atoi(argv[1]), width = atoi(argv[2]), iter_num = atoi(argv[5]);
	double g = atof(argv[3]), f = atof(argv[4]);
//	printf("Running simulation: grid_size = %d x %d, g = %f, f = %f, iter_num = %d\n", \
//			height, width, g, f, iter_num);

	// 2. run the simulation
	// a. initiate variables
	int p[iter_num];  // store the P after each time step
	bool grid[height][width];  // initiate the forest grid
	memset(grid, false, sizeof(grid));

	// b. begin simulation
	for (int i = 0; i < iter_num; i++) {
		run_growth_phase(*grid, height, width, g);
		run_fire_phase(*grid, height, width, f);
		p[i] = count_trees(*grid, height, width);
	}

	// 3. print the result
	double avg_p = 0;
	for (int i = 0; i < iter_num; i++) {
		avg_p += p[i];
	}
	avg_p /= iter_num * height * width;
//	printf("Average P: %f\n", avg_p);

	printf("%f\t%f\t%f\n", f, g, avg_p);

	return 0;
}
