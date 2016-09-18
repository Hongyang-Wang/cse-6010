/*
 ============================================================================
 Name        : queueing-model-simulation.c
 Author      : Hongyang Wang
 Version     :
 Copyright   : © Fall 2016 CSE 6010 Hongyang Wang
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utils/queue/Queue.h"
#include "utils/priority_queue/PriorityQueue.h"

// global variables
double S = 0, A = 0;
int num_stations = 0;
int part_counter = 0;
double simu_time;
Queue **q_list = NULL;
PriorityQueue *pq = NULL;

int main(int argc, char *argv[]) {
	// parse input arguments
	// .executable, avg_service_time, avg_interval, num_stations, total_simulation_time
	if (argc != 6) {
		printf("The program takes in 4 arguments: avg_service_time, avg_interval, \
				num_stations, total_simulation_time, debug");
		return -1;
	}
	S = atof(argv[1]);
	A = atof(argv[2]);
	num_stations = atoi(argv[3]);
	double simu_time = atof(argv[4]);
	int debug = atoi(argv[5]);

	// initialize
	part_counter = 0;
	q_list = (Queue **) malloc(num_stations * sizeof(Queue *));
	for (int i = 0; i < num_stations; i++) {
		q_list[i] = (Queue *) malloc(sizeof(Queue));
		q_init(q_list[i]);
	}
	pq = (PriorityQueue *) malloc(sizeof(PriorityQueue));
	pq_init(pq, &event_cmp);

	// simulation
	// add the first event
	schedule_next_event(0.0, -1, &create_part);
	// simulate
	while (pq_size(pq) > 0) {
		Event *event = pq_pop(pq);
		// do something

		(*(event->event_handler))(event);
	}

	// clean
	for (int i = 0; i < num_stations; i++) {
		q_clear(q_list[i], &free_part);
		free(q_list[i]);
		q_list[i] = NULL;
	}
	free(q_list);
	q_list = NULL;

	pq_clear(pq, &free_event);
	free(pq);
	pq = NULL;
}
