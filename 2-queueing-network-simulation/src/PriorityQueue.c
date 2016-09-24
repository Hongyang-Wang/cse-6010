/*
 * PriorityQueue.c
 *
 *  Created on: Sep 22, 2016
 *      Author: YS
 */

#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"

//
// 改动：
// 传入data就是Event型指针，
// 没有了pq_size函数，
// 完成了从头开始比较然后插入的过程（push函数）
// 没有了，周末愉快，有需要我做的事情请开心地微信我。
//

void pq_init(PriorityQueue *q) {
    q->head = q->tail = q->compare = NULL;
}

/*
int pq_size(PriorityQueue *q) {
	return 0;
}
 */

void pq_push(PriorityQueue *q, Event *p) {
    PQNode *new_node = (PQNode *) malloc(sizeof(PQNode));
    new_node->event = p;
    if (q->tail == NULL)
        q->head = q->tail = q->compare = new_node;
    else {
        if (new_node->event->start_time >= q->compare->event->start_time){
            PQNode *temp = q->compare;
            while (new_node->event->start_time >= q->compare->event->start_time) {
                temp = q->compare;
                q->compare = temp->next;
            }
            new_node->next = q->compare;
            temp->next = new_node;
            free(temp);
            q->compare = q->head;
        }
        else{
            PQNode *temp = q->head;
            new_node->next = temp;
            q->head = new_node;
            free(temp);
            q->compare = q->head;
        }

    }
}

void *pq_pop(PriorityQueue *q) {
    Event *ret = NULL;
    if (q->head == NULL) {
        printf("The Queue is empty\n");
        return ret;
    }
    PQNode *temp = q->head;
    ret = temp->event;
    q->head = temp->next;
    free(temp);
    return ret;
}

void *pq_peek(PriorityQueue *q) {
    Event *ret = NULL;
    if (q->head == NULL) {
        printf("The Queue is empty\n");
        return ret;
    }
    return q->head->event;
}

void pq_clear(PriorityQueue *q, void (*free_data)()) {
    while (q->head != NULL) {
        PQNode *temp = q->head;
        q->head = temp->next;
        free_data(temp->event);
        free(temp);
    }
    q->head = q->tail = NULL;
}


