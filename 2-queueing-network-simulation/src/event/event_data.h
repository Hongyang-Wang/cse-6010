/*
 * event_data.h
 *
 *  Created on: Sep 16, 2016
 *      Author: Frank
 */

#ifndef EVENT_DATA_H_
#define EVENT_DATA_H_

typedef struct {
	int id;
	double create_time;
	double finish_time;
    double* service_times;
    double* waiting_times;
    int counter;

} Part;

typedef struct {
	double start_time;
	Part *part;
	void (*event_handler) ();

} Event;

#endif /* EVENT_DATA_H_ */
