#include<stdio.h>
#include<stdlib.h>


#define vertex int
#define INT_MAX 9999
#define UGraph Graph


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


int GRAPHcptBF1( Graph G, vertex s, vertex *pa, int *dist)
{
   const int INF = INT_MAX;
   QUEUEinit( G->A);
   bool onqueue[1000];
   for (vertex u = 0; u < G->V; ++u)
      pa[u] = -1, dist[u] = INF, onqueue[u] = false;
   pa[s] = s, dist[s] = 0;
   QUEUEput( s);
   onqueue[s] = true;
   vertex V = G->V;
   QUEUEput( V);
   int k = 0;

   while (true) {
      vertex v = QUEUEget( );
      if (v < V) {
         for (link a = G->adj[v]; a != NULL; a = a->next) {
            if (dist[v] + a->c < dist[a->w]) {
               dist[a->w] = dist[v] + a->c;
               pa[a->w] = v;
               if (onqueue[a->w] == false) {
                  QUEUEput( a->w);
                  onqueue[a->w] = true;
               }
            }
         }
      } else {
         if (QUEUEempty( )) return -1;
         if (++k >= G->V) return +1;
         QUEUEput( V);
         for (vertex u = 0; u < G->V; ++u)
            onqueue[u] = false;
      }
   }
}

int main (void) {
   FILE *entrada;
   entrada = fopen ("dados.txt", "r");
   if (entrada == NULL) {
      printf ("\nNão encontrei o arquivo!\n");
      exit (EXIT_FAILURE);
   }
}

