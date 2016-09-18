/*
 * event_handler.c
 *
 *  Created on: Sep 16, 2016
 *      Author: Frank
 */

#include <stdlib.h>
#include "event_data.h"
#include "utils/random/random.h"

extern double S, A;
extern int num_stations;

int event_cmp(void *d1, void *d2) {
	Event *e1 = (Event *) d1, *e2 = (Event *) d2;
	if (e1->start_time < e2->start_time)
		return -1;
	else if (e1->start_time > e2->start_time)
		return 1;
	else
		return 0;
}

void create_part() {
	double interval = get_exp_rand(A);


}
