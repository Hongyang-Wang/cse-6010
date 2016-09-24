/*
 * random.c
 *
 *  Created on: Sep 18, 2016
 *      Author: Frank
 */

#include <stdlib.h>
#include <math.h>
#include <time.h>

void rand_init() {
	srand(time(NULL));
}

double urand() {
	return (double)rand() / ((double)RAND_MAX + 1);
}

double randexp(double mean) {
	return -mean * (log(1.0 - urand()));
}
