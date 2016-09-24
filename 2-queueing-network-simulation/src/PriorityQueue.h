/*
 * PriorityQueue.h
 *
 *  Created on: Sep 22, 2016
 *      Author: YS
 */

#ifndef UTILS_PRIORITY_QUEUE_PRIORITYQUEUE_H_
#define UTILS_PRIORITY_QUEUE_PRIORITYQUEUE_H_

typedef struct _pq_node {
    Event *event;
    struct _pq_node *next;
} PQNode;


typedef struct _min_priority_queue {
    	PQNode *head, *tail, *compare;
} PriorityQueue;

void pq_init(PriorityQueue *q);
int pq_size(PriorityQueue *q);
void pq_push(PriorityQueue *q, Event *p);
void *pq_pop(PriorityQueue *q);
void *pq_peek(PriorityQueue *q);
void pq_clear(PriorityQueue *q, void (*free_data)());

#endif /* UTILS_PRIORITY_QUEUE_PRIORITYQUEUE_H_ */