#include "dijkstra.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc < 4) {
    printf("podano za malo argumentow\n");
    exit(EXIT_FAILURE);
  } else if (argc > 4) {
    printf("podano za duzo argumentow\n");
    exit(EXIT_FAILURE);
  }

  char *filename = argv[1];
  int start = atoi(argv[2]);
  int finish = atoi(argv[3]);
  printf("start: %d, finish: %d\n", start, finish);

  int n, m;
  EdgeList *graph;
  read_graph(filename, &n, &m, &graph);

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

  printf("odleglosci od %d:\n", start);
  for (int i = 1; i <= n; i++) {
    printf("%d : %d\n", i, dist[i]);
  }

  int path[n + 1];
  int path_len = n;
  restore_path(start, finish, par, path, &path_len);

  printf("sciezka z %d do %d:\n", start, finish);
  for (int i = 0; i < path_len; i++) {
    printf("%d ", path[i]);
  }
  printf("\n");

  free_graph(graph, n);

  return 0;
}
