/*
 * event_data.h
 *
 *  Created on: Sep 16, 2016
 *      Author: Frank
 */

#ifndef EVENT_EVENT_DATA_H_
#define EVENT_EVENT_DATA_H_

typedef struct {
	int id;
	double create_time;
	double finish_time;
    double* service_times;
    double* enqueue_times, *dequeue_times;

} Part;

typedef struct {
	double start_time;
	int station_id;
	void (*event_handler) ();

} Event;

static int event_cmp(void *d1, void *d2) {
	Event *e1 = (Event *) d1, *e2 = (Event *) d2;
	if (e1->start_time < e2->start_time)
		return -1;
	else if (e1->start_time > e2->start_time)
		return 1;
	else
		return 0;
}

static void free_event(void *event) {
	Event *e = (Event *) event;
	free(e);
	e = NULL;
}

static void free_part(void *part) {
	Part *p = (Part *) part;
	free(p->service_times);
	free(p->enqueue_times);
	free(p->dequeue_times);
	free(p);
	p = NULL;
}

#endif /* EVENT_EVENT_DATA_H_ */
