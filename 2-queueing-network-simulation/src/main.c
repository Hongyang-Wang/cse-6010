/*
 ============================================================================
 Name        : queueing-model-simulation.c
 Author      : Hongyang Wang
 Version     :
 Copyright   : © Fall 2016 CSE 6010 Hongyang Wang
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utils/queue/Queue.h"

typedef struct {
	int id;

} student;

int main(void) {
	Queue q;
	q_init(&q);
	for (int i = 0; i < 5; i++) {
		student *p = (student *) malloc(sizeof(student));
		p->id = i;
		q_push(&q, p);
		printf("size=%d\n", q_size(&q));
	}
	for (int i = 0; i < 2; i++) {
		student *p = q_peek(&q);
		printf("id=%d\n", p->id);
		p = q_pop(&q);
		printf("id=%d\n", p->id);
		free(p);
		p = NULL;
	}
	printf("size=%d\n", q_size(&q));
	q_clear(&q);
	printf("size=%d\n", q_size(&q));
}
