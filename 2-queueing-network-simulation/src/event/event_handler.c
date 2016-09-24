/*
 * event_handler.c
 *
 *  Created on: Sep 16, 2016
 *      Author: Frank
 */

#include <stdio.h>
#include <stdlib.h>
#include "event_data.h"
#include "event_handler.h"
#include "../utils/random/random.h"
#include "../utils/queue/Queue.h"
#include "../utils/priority_queue/PriorityQueue.h"

extern double S, A;
extern int num_stations;
extern int part_counter;
extern double simu_time;
extern Queue **q_list;
extern PriorityQueue *pq;
extern int debug;

int event_cmp(void *d1, void *d2) {
	Event *e1 = (Event *) d1, *e2 = (Event *) d2;
	if (e1->start_time < e2->start_time)
		return -1;
	else if (e1->start_time > e2->start_time)
		return 1;
	else
		return 0;
}

void free_event(void *event) {
	Event *e = (Event *) event;
	free(e);
	e = NULL;
}

void free_part(void *part) {
	Part *p = (Part *) part;
	free(p->service_times);
	free(p->enqueue_times);
	free(p->dequeue_times);
	free(p);
	p = NULL;
}

void schedule_next_event(double start_time, double station_id, void (*event_handler)()) {
	if (start_time >= simu_time)
		return;
	Event *next_event = (Event *) malloc(sizeof(Event));
	next_event->start_time = start_time;
	next_event->station_id = station_id;
	next_event->event_handler = event_handler;
	pq_push(pq, next_event);
}

void leave(Event *event) {
	Part *part = q_pop(q_list[event->station_id]);
	printf("pop part_id=%d from queue %c\n", part->id, 'A' + event->station_id);
	// schedule next service event for the next part in the queue of this station
	if (q_size(q_list[event->station_id]) > 0) {
		schedule_next_event(event->start_time, event->station_id, &start_service);
	}
	// ----
	if (debug) {
		printf("Service done\tcur_time=%f\tpart_id=%d\tstation_id=%c\n", \
				event->start_time, part->id, 'A' + event->station_id);
	}
	// ----
	// done if this is the last station
	if (event->station_id == num_stations - 1) {
		part->finish_time = event->start_time;
		// do some statistics

		// ----
		if (debug) {
			printf("Part finished\tpart_id=%d\tcreate_time=%f\tfinish_time=%f\n", \
					part->id, part->create_time, part->finish_time);
		}
		// ----
		// free this part
		free_part(part);
	}
	else {  // enqueue the current part into next station's queue
		q_push(q_list[event->station_id + 1], part);
		printf("push part_id=%d to queue %c\n", part->id, 'A' + event->station_id + 1);
		part->enqueue_times[event->station_id + 1] = event->start_time;
		// schedule the service event for the next station if it's free
		if (q_size(q_list[event->station_id + 1]) == 1) {
			schedule_next_event(event->start_time, event->station_id + 1, &start_service);
		}
	}
	// free current event
	free_event(event);
}

void start_service(Event *event) {
	// get the part for this event
	Part *part = q_peek(q_list[event->station_id]);
	part->dequeue_times[event->station_id] = event->start_time;
	// schedule dequeue event for this part
	double next_start_time = event->start_time + part->service_times[event->station_id];
	schedule_next_event(next_start_time, event->station_id, &leave);
	// ----
	if (debug) {
		printf("Start service\tcur_time=%f\tpart_id=%d\tstation_id=%c\n", \
				event->start_time, part->id, 'A' + event->station_id);
	}
	// ----
	// free this event
	free_event(event);
}

void create_part(Event *event) {
	// create part for this event
	part_counter++;
	Part *part = (Part *) malloc(sizeof(Part));
	part->create_time = event->start_time;
	part->id = part_counter;
	part->service_times = (double *) malloc(num_stations * sizeof(double));
	for (int i = 0; i < num_stations; i++) {
		part->service_times[i] = randexp(S);
	}
	part->enqueue_times = (double *) malloc(num_stations * sizeof(double));
	part->dequeue_times = (double *) malloc(num_stations * sizeof(double));
	part->finish_time = -1;
	// ----
	if (debug) {
		printf("Part created\tcur_time=%f\tpart_id=%d\n", event->start_time, part_counter);
	}
	// ----
	// schedule next create event
	double interval = randexp(A);
	schedule_next_event(event->start_time + interval, -1, &create_part);
	// send this part to the first station
	q_push(q_list[0], part);
	printf("push part_id=%d to queue %c\n", part->id, 'A' + event->station_id + 1);
	part->enqueue_times[0] = event->start_time;
	// schedule the service event if the first station is available
	if (q_size(q_list[0]) == 1) {
		schedule_next_event(event->start_time, 0, &start_service);
	}
	// free this event
	free_event(event);
}

