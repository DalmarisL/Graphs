#include<stdio.h>
#include<stdlib.h>


#define vertex int
#define UGraph Graph

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
    vertex c;
    link next;

};

static link NeWnode(vertex w, link next)
{
    link a = malloc(sizeof (struct node));
    a-> w = w;
    a->next = next;
    return a;
}


typedef struct
{
  vertex v, w;
  int c;
} edge;

static edge EDGE( vertex v, vertex w, int c)
{
    edge e;
    e.v = v, e.w = w, e.c = c;
    return e;
}

static void UGRAPHedges( UGraph G, edge e[])
{
   int i = 0;
   for (vertex v = 0; v < G->V; ++v)
      for (link a = G->adj[v]; a != NULL; a = a->next)
         if (v < a->w)
            e[i++] = EDGE( v, a->w, a->c);
}



void kruskal(UGraph G, edge  mst[])
{
   edge e[500000];

   UGRAPHedges( G, e);
   int E = G->A/2;
   sort( e, 0, E-1);

   UFinit( G->V);
   int k = 0;
   for (int i = 0; k < G->V-1; ++i) {
      vertex v0 = UFfind( e[i].v);
      vertex w0 = UFfind( e[i].w);
      if (v0 != w0) {
         UFunion( v0, w0);
         mst[k++] = e[i];
      }
   }
}


static vertex ch[1000];
static sz[1000];

void UFinit(int V)
{
    for(vertex v = 0; v < V; ++v)
    {
        ch[v] = v;
        sz[v] = 1;
    }
}

vertex UFfind(vertex v)
{
    vertex v0 = v;
    while(v0 != ch[v0])
        v0 = ch[v0];
    return v0;
}

void UFunion(vertex v0, vertex w0)
{
    if(sz[v0] < sz[w0])
    {
        ch[v0] = w0;
        sz[w0] += sz[v0];
    }
    else
    {
        ch[w0] = v0;
        sz[v0] += sz[w0];
    }
}
