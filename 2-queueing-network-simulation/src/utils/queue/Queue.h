/*
 * Queue.h
 *
 *  Created on: Sep 16, 2016
 *      Author: Frank
 */

#ifndef UTILS_QUEUE_QUEUE_H_
#define UTILS_QUEUE_QUEUE_H_

typedef struct _q_node {
	void *data;
	struct _q_node *next;
} QNode;

typedef struct {
	QNode *head, *tail;
	int size;
} Queue;

void q_init(Queue *q);
int q_size(Queue *q);
void q_push(Queue *q, void *p);
void *q_peek(Queue *q);
void *q_pop(Queue *q);
void q_clear(Queue *q);

#endif /* UTILS_QUEUE_QUEUE_H_ */
