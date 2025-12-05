#include "dijkstra.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("\e[91mnie podano pliku z grafem\e[0m\n");
    printf("uzycie: ./dijkstra <plik_z_grafem> [start] [koniec]\n");
    exit(EXIT_FAILURE);
  }
  char *filename = argv[1];
  FILE *file = fopen(filename, "r");
  if (!file) {
    printf("\e[91mnie mozna otworzyc pliku '%s'\e[0m\n", filename);
    exit(EXIT_FAILURE);
  }
  int start, finish;
  if (argc < 3) {
    start = 1;
    printf("\e[93mnie podano wiercholka poczatkowego, uzywam 1 jako start\e[0m\n");
  } else {
    start = atoi(argv[2]);
  }
  if (argc < 4) {
    printf("\e[93mnie podano wiercholka koncowego\e[0m\n");
    finish = -1;
  } else {
    finish = atoi(argv[3]);
    printf("wyswietlam trase %d -> %d\n", start, finish);
  }
  printf("\e[90m----------\e[0m\n");

  int n, m;
  EdgeList *graph;
  read_graph(file, &n, &m, &graph);

  print_graph(graph, n);
  printf("\e[90m----------\e[0m\n");

  int dist[n + 1], marked[n + 1], par[n + 1];
  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
    marked[i] = 0;
    par[i] = i;
  }
  dist[start] = 0;

  dijkstra(graph, dist, marked, par, n);

  print_dist(n, dist, start);

  if (finish != -1) {
    printf("\e[90m----------\e[0m\n");
    print_path(n, par, dist, start, finish);
  }

  free_graph(graph, n);

  return 0;
}
