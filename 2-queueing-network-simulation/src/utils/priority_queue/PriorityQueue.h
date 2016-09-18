/*
 * PriorityQueue.h
 *
 *  Created on: Sep 16, 2016
 *      Author: Frank
 */

#ifndef UTILS_PRIORITY_QUEUE_PRIORITYQUEUE_H_
#define UTILS_PRIORITY_QUEUE_PRIORITYQUEUE_H_

typedef struct _min_priority_queue {

} PriorityQueue;

void pq_init(PriorityQueue *q, int (*cmp) (void *o1, void *o2));
int pq_size(PriorityQueue *q);
void pq_push(PriorityQueue *q, void *p);
void *pq_pop(PriorityQueue *q);
void *pq_peek(PriorityQueue *q);
void pq_clear(PriorityQueue *q, void (*free_data)());

#endif /* UTILS_PRIORITY_QUEUE_PRIORITYQUEUE_H_ */
