#ifndef GRAPH_H
#define GRAPH_H

#define INF 1000000007

typedef struct {
  int dest, weight;
} Edge;

typedef struct {
  Edge *array;
  int size, capacity;
} EdgeList;

void init_edge_list(EdgeList *list, int capacity);
void add_edge(EdgeList *list, int dest, int weight);
void free_edge_list(EdgeList *list);

void read_graph(const char *filename, int *n, int *m, EdgeList **graph);
void free_graph(EdgeList *graph, int n);
void print_graph(EdgeList *graph, int n);

#endif
