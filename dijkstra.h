#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"

void dijkstra(EdgeList *graph, int *dist, int *marked, int *par, int n);
void restore_path(int start, int finish, int *par, int *path, int *path_len);

#endif
