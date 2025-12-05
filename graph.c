#include "graph.h"
#include <stdio.h>

void init_edge_list(EdgeList *list, int capacity) {
  list->size = 0;
  list->capacity = capacity;
  list->array = (Edge *)malloc(list->capacity * sizeof(Edge));
  if (list->array == NULL) {
    perror("nie udalo sie alokowac pamieci");
    exit(EXIT_FAILURE);
  }
}

void add_edge(EdgeList *list, int dest, int weight) {
  if (list->size >= list->capacity) {
    list->capacity *= 2;
    list->array = (Edge *)realloc(list->array, list->capacity * sizeof(Edge));
    if (list->array == NULL) {
      perror("nie udalo sie realokowac pamieci");
      exit(EXIT_FAILURE);
    }
  }
  list->array[list->size].dest = dest;
  list->array[list->size].weight = weight;
  list->size++;
}

void free_edge_list(EdgeList *list) {
  free(list->array);
  list->array = NULL;
  list->size = 0;
  list->capacity = 0;
}

void read_graph(FILE *file, int *n, int *m, EdgeList **graph) {
  fscanf(file, "%d %d", n, m);

  *graph = (EdgeList *)malloc((*n + 1) * sizeof(EdgeList));
  if (*graph == NULL) {
    perror("nie udalo sie alokowac pamieci dla grafu");
    exit(EXIT_FAILURE);
  }

  int init_capacity = (*m / *n) + 1;
  for (int i = 1; i <= *n; i++) {
    init_edge_list(&(*graph)[i], init_capacity);
  }

  for (int i = 0; i < *m; i++) {
    int a, b, w;
    fscanf(file, "%d %d %d", &a, &b, &w);
    add_edge(&(*graph)[a], b, w);
    add_edge(&(*graph)[b], a, w);
  }

  fclose(file);
}

void free_graph(EdgeList *graph, int n) {
  for (int i = 1; i <= n; i++) {
    free_edge_list(&graph[i]);
  }
  free(graph);
}

void print_graph(EdgeList *graph, int n) {
  printf("\e[94mgraf:\e[0m\n");
  for (int i = 1; i <= n; i++) {
    printf("%d: ", i);
    for (int j = 0; j < graph[i].size; j++) {
      printf("%d(%d) ", graph[i].array[j].dest, graph[i].array[j].weight);
    }
    printf("\n");
  }
}
