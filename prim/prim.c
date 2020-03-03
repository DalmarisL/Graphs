#include<stdio.h>
#include<stdlib.h>


#define vertex int
#define INFINITY 9999
#define UGraph Graph


enum boolean
{
    true = 1, false =0
};
typedef  enum boolean  bool;

typedef struct node *link;


    int V;
    int A;


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



void Prim(UGraph G, vertex *pa)
{
    bool tree[1000];
   int preco[1000];
   for (vertex v = 0; v < G->V; ++v)
      pa[v] = -1, tree[v] = false, preco[v] = INFINITY;
   pa[0] = 0, tree[0] = true;
   for (link a = G->adj[0]; a != NULL; a = a->next)
      pa[a->w] = 0, preco[a->w] = a->c;

   while (true) {
      int min = INFINITY;
      vertex y;
      for (vertex w = 0; w < G->V; ++w) {
         if (!tree[w] && preco[w] < min)
            min = preco[w], y = w;
      }
      if (min == INFINITY) break;
      tree[y] = true;
      for (link a = G->adj[y]; a != NULL; a = a->next) {
         if (!tree[a->w] && a->c < preco[a->w]) {
            preco[a->w] = a->c;
            pa[a->w] = y;
         }
      }
   }
}


