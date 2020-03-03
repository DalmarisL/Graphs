#include<stdio.h>
#include<stdlib.h>


#define vertex int
#define INT_MAX 9999
#define Dag Graph


enum boolean
{
    true = 1, false =0
};
typedef  enum boolean  bool;

typedef struct node *link;

struct graph ///grafo
{
  int V; ///vertices
  int A; /// n° de arcos
  link *adj;
};

typedef struct graph *Graph;

struct node
{
    vertex w;
    int c;
    link next;

};


static link NeWnode(vertex w, link next)
{
    link a = malloc(sizeof (struct node));
    a-> w = w;
    a->next = next;
    return a;
}

void DagA(Dag G, vertex *vv, vertex s, vertex *pa, int *dist)
{
    for (vertex v = 0; v < G->V; ++v)
      pa[v] = -1, dist[v] = INT_MAX;

   pa[s] = s, dist[s] = 0;
   for (int j = 0; j < G->V; ++j) {
      vertex v = vv[j];
      if (dist[v] == INT_MAX) continue;
      for (link a = G->adj[v]; a != NULL; a = a->next) {
         if (dist[v] + a->c < dist[a->w]) {
            dist[a->w] = dist[v] + a->c;
            pa[a->w] = v;
         }
      }
   }
}
