/*
 * event_data.h
 *
 *  Created on: Sep 16, 2016
 *      Author: Frank
 */

#ifndef EVENT_DATA_H_
#define EVENT_DATA_H_

typedef struct _part {
	int id;
	double create_time;
	double finish_time;
	int LEN;
    double *service_times;
    double *waiting_times;
    int counter;

} Part;

typedef struct _event {
	double start_time;
	Part part;
	void (*event_handler) (Part p);

} Event;

#endif /* EVENT_DATA_H_ */
