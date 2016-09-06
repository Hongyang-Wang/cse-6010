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
	if (argc != 7) {
		printf("The program takes in 6 arguments: height, width, g, f, iter_num and is_debug");
		return -1;
	}

	int height = atoi(argv[1]), width = atoi(argv[2]), iter_num = atoi(argv[5]);
	double g = atof(argv[3]), f = atof(argv[4]);
	bool is_debug = atoi(argv[6]);
	if (is_debug) {
		printf("Running simulation: grid_size = %d x %d, g = %f, f = %f, iter_num = %d\n", \
				height, width, g, f, iter_num);
		printf("----------------------------------------------------------------------------\n");
	}

	// 2. run the simulation
	// a. initiate variables
	int p[iter_num];  // store the P after each time step
	bool grid[height][width];  // initialize the forest grid
	memset(grid, false, sizeof(grid));
	srand(0);  // initialize the random seed

	// b. begin simulation
	for (int i = 0; i < iter_num; i++) {
		run_growth_phase(*grid, height, width, g);
		if (is_debug) {
			printf("t = %d, after growth phase:\n", i);
			print_forest(*grid, height, width);
		}
		run_fire_phase(*grid, height, width, f);
		if (is_debug) {
			printf("t = %d, after fire phase:\n", i);
			print_forest(*grid, height, width);
		}
		p[i] = count_trees(*grid, height, width);
		if (is_debug) {
			printf("Number of trees = %d\n", p[i]);
			printf("----------------------------------------------------------------------------\n");
		}
	}

	// 3. print the result
	double avg_p = 0;
	for (int i = 0; i < iter_num; i++) {
		avg_p += p[i];
	}
	avg_p /= iter_num * height * width;
	if (is_debug)
		printf("Simulation is over, average P (per cell): %f\n", avg_p);
	if (!is_debug)
		printf("%f\t%f\t%f\n", f, g, avg_p);

	return 0;
}
