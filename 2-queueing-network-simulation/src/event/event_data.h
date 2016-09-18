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
    double* enqueue_times, dequeue_times;

} Part;

typedef struct {
	double start_time;
	int station_id;
	void (*event_handler) ();

} Event;

#endif /* EVENT_EVENT_DATA_H_ */
