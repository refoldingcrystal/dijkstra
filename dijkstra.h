#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"

void dijkstra(EdgeList *graph, int *dist, int *marked, int *par, int n);
void restore_path(int start, int finish, int *par, int *path, int *path_len);

void print_dist( int n, int *dist, int start);
void print_path(int n, int *par, int *dist, int start, int finish);

#endif
