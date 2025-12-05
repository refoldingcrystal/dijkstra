#include "dijkstra.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("nie podano pliku z grafem\n");
    printf("uzycie: ./dijkstra <plik_z_grafem> [start] [koniec]\n");
    exit(EXIT_FAILURE);
  }
  char *filename = argv[1];
  FILE *file = fopen(filename, "r");
  if (!file) {
    printf("nie mozna otworzyc pliku '%s'\n", filename);
    exit(EXIT_FAILURE);
  }
  int start, finish, single_path = 1;
  if (argc < 3) {
    start = 1;
    printf("nie podano wiercholka poczatkowego\n");
  } else {
    start = atoi(argv[2]);
  }
  if (argc < 4) {
    single_path = 0;
    printf("nie podano wiercholka koncowego\n");
    printf("wyswietlam wszystkie trasy z %d\n", start);
  } else {
    finish = atoi(argv[3]);
    printf("wyswietlam trase %d -> %d\n", start, finish);
  }

  int n, m;
  EdgeList *graph;
  read_graph(file, &n, &m, &graph);

  printf("graf:\n");
  print_graph(graph, n);

  int dist[n + 1], marked[n + 1], par[n + 1];
  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
    marked[i] = 0;
    par[i] = i;
  }
  dist[start] = 0;

  dijkstra(graph, dist, marked, par, n);

  int path[n + 1];
  int path_len = n;
  if (single_path) {
    restore_path(start, finish, par, path, &path_len);
    printf("sciezka z %d do %d:\n", start, finish);
    for (int i = 0; i < path_len; i++) {
      printf("%d ", path[i]);
    }
    printf("\n");
  } else {
    printf("odleglosci od %d:\n", start);
    for (int i = 1; i <= n; i++) {
      printf("%d : %d\n", i, dist[i]);
    }
  }

  free_graph(graph, n);

  return 0;
}
