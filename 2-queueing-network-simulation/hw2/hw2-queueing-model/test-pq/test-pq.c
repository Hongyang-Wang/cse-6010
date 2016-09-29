/*
 * measure_pq.c
 *
 *  Created on: Sep 24, 2016
 *      Author: Frank
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "../src/event/event_data.h"
#include "../src/utils/random/random.h"
#include "../src/utils/priority_queue/PriorityQueue.h"

int main(int argc, char *argv[]) {
	// parse input
	if (argc != 3) {
		printf("The program takes in 2 arguments: N, num_iters\n");
		return -1;
	}
	int N = atoi(argv[1]);
	int num_iters = atoi(argv[2]);

	// create events
	rand_init(6010);
	Event *events = (Event *) malloc((N + num_iters) * sizeof(Event));
	for (int i = 0; i < N + num_iters; i++) {
		events[i].start_time = urand();
		events[i].station_id = -1;
		events[i].event_handler = NULL;
	}

	// init pq
	PriorityQueue pq;
	pq_init(&pq, &event_cmp);
	for (int i = 0; i < N; i++) {
		pq_push(&pq, events + i);
	}

	// measure the performance
	double avg_time = 0.0;
	struct timeval start_time, end_time;
	gettimeofday(&start_time, NULL);
	for (int i = N; i < N + num_iters; i++) {
		pq_push(&pq, events + i);
		pq_pop(&pq);
	}
	gettimeofday(&end_time, NULL);
	double elapsed_time = 1000000 * (end_time.tv_sec - start_time.tv_sec) + end_time.tv_usec - start_time.tv_usec;
	printf("N=%d. Each iteration takes %.3f us\n", N, elapsed_time / num_iters);

	// clean
	while (pq_size(&pq) > 0) {
		pq_pop(&pq);
	}
	pq_clear(&pq, &free_event);
	free(events);
	events = NULL;
}
