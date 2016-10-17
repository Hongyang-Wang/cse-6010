/*
 * graph_utils.h
 *
 *  Created on: Oct 15, 2016
 *      Author: Frank
 */

#ifndef SRC_GRAPH_UTILS_H_
#define SRC_GRAPH_UTILS_H_

typedef struct _node {
	int id;
	struct _node *next;

} Node;

Node **load_graph(const char *filename, int *siz);
void print_graph(Node **graph, int N);
int *bfs(Node **graph, int N, int node);

#endif /* SRC_GRAPH_UTILS_H_ */
