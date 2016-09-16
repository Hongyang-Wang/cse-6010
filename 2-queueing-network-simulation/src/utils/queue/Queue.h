/*
 * Queue.h
 *
 *  Created on: Sep 16, 2016
 *      Author: Frank
 */

#ifndef UTILS_QUEUE_QUEUE_H_
#define UTILS_QUEUE_QUEUE_H_

typedef struct _queue {

} Queue;

void q_init(Queue *q);
int q_size(Queue *q);
int q_push(Queue *q, void *p);
void *q_pop(Queue *q);
void *q_peek(Queue *q);

#endif /* UTILS_QUEUE_QUEUE_H_ */
