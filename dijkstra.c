#include "dijkstra.h"
#include "graph.h"

void dijkstra(EdgeList *graph, int *dist, int *marked, int *par, int n) {
  for (int i = 1; i <= n; i++) {
    int v = -1;
    for (int j = 1; j <= n; j++) {
      if (!marked[j] && (v == -1 || dist[j] < dist[v])) {
        v = j;
      }
    }
    if (dist[v] == INF)
      break;
    marked[v] = 1;
    for (int j = 0; j < graph[v].size; j++) {
      int dest = graph[v].array[j].dest;
      int weight = graph[v].array[j].weight;
      if (dist[v] + weight < dist[dest]) {
        dist[dest] = dist[v] + weight;
        par[dest] = v;
      }
    }
  }
}

void restore_path(int start, int finish, int *par, int *path, int *path_len) {
  int tmp[1000];
  int tmp_len = 0;
  int v = finish;

  while (v != start) {
    if (par[v] == v){
      *path_len = 0;
      return;
    }
    tmp[tmp_len] = v;
    v = par[v];
    tmp_len++;
  }
  tmp[tmp_len] = start;
  tmp_len++;

  for (int i = 0; i < tmp_len; i++) {
    path[i] = tmp[tmp_len - i - 1];
  }
  *path_len = tmp_len;
}

void print_dist( int n, int *dist, int start) {
  printf("\e[94modleglosci od startu (%d):\e[0m\n", start);
  for (int i = 1; i <= n; i++) {
    if (i == start) continue;
    printf("%d: ", i);
    if (dist[i] == INF){
      printf("INF (sciezka nie istnieje)\n");
    } else {
      printf("%d\n", dist[i]);
    }
  }
}

void print_path(int n, int *par, int *dist, int start, int finish) {
  int path[n + 1];
  int path_len = n;
  restore_path(start, finish, par, path, &path_len);
  if (path_len) {
    printf("\e[92msciezka %d -> %d (dlugosc %d):\e[0m\n", start, finish, dist[finish]);
    for (int i = 0; i < path_len; i++) {
      printf("%d ", path[i]);
    }
    printf("\n");
  } else {
    printf("\e[92msciezka %d -> %d nie istnieje\e[0m\n", start, finish);
  }
}
