/*
 * event.h
 *
 *  Created on: Sep 16, 2016
 *      Author: Frank
 */

#ifndef EVENT_EVENT_H_
#define EVENT_EVENT_H_

#include "event_data.h"

void schedule_next_event(double start_time, double station_id, void (*event_handler)());
void leave(Event *event);
void start_service(Event *event);
void create_part(Event *event);

#endif /* EVENT_EVENT_H_ */
