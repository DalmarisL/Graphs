#include<stdio.h>
#include<stdlib.h>


#define vertex int
#define INFINITY 9999

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

void Dijkstra(Graph G, vertex s, vertex *pa, int *dist)
{
    bool tree[1000];
   for (vertex v = 0; v < G->V; ++v)
      pa[v] = -1, tree[v] = false, dist[v] = INFINITY;
   pa[s] = s, tree[s] = true, dist[s] = 0;
   for (link a = G->adj[s]; a != NULL; a = a->next)
      pa[a->w] = s, dist[a->w] = a->c;

   while (true) {
      int min = INFINITY;
      vertex y;
      for (vertex z = 0; z < G->V; ++z) {
         if (tree[z]) continue;
         if (dist[z] < min)
            min = dist[z], y = z;
      }
      if (min == INFINITY) break;
      tree[y] = true;
      for (link a = G->adj[y]; a != NULL; a = a->next) {
         if (tree[a->w]) continue;
         if (dist[y] + a->c < dist[a->w]) {
            dist[a->w] = dist[y] + a->c;
            pa[a->w] = y;
         }
      }
   }

}
