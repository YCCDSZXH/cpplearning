#ifndef GRAPH_TEST_H_INCLUDED
#define GRAPH_TEST_H_INCLUDED
#define INFINITY 1000000
#include <queue>

#include "grlist.h"
class option {
 private:
  Graph* G;

 public:
  // Start with some implementations for the abstract functions
  option(Graph* g) { G = g; }

  void DFS(int v, void (*PreVisit)(int v), void (*PostVisit)(int v),
           void (*Visiting)(int v))  // Depth first search
  {
    PreVisit(v);
    Visiting(v);
    G->setMark(v, VISITED);
    for (int w = G->first(v); w < G->n(); w = G->next(v, w)) {
      if (G->getMark(w) == UNVISITED) DFS(w, PreVisit, PostVisit, Visiting);
    }
    PostVisit(v);
  }

  void BFS(int start, void (*PreVisit)(int v), void (*PostVisit)(int v),
           void (*Visiting)(int v)) {
    int i, j;
    queue<int> Q;
    Q.push(start);
    PreVisit(start);
    G->setMark(start, VISITED);
    while (Q.size()) {
      int s = Q.front();
      Q.pop();
      Visiting(s);
      for (int w = G->first(s); w < G->n(); w = G->next(s, w)) {
        if (G->getMark(w) == UNVISITED) {
          PreVisit(w);
          G->setMark(w, VISITED);
          Q.push(w);
        }
      }
      PostVisit(s);
    }
  }

  void Dijkstra1(int* D, int s) {
    for (int i = 0; i < G->n(); i++) {
      int min = minVertex(D);
      for (int w = G->first(min); w < G->n(); w = G->next(min, w)) {
        if (D[w] > G->weight(min, w) + D[min])
          D[w] = G->weight(min, w) + D[min];
      }
      G->setMark(min, VISITED);
    }
  }

  double* Dijkstra2(int* D, int s, int ss) {
    double* res = new double[G->n() + 1];
    for (int i = 0; i < G->n()+1; i++) {
      res[i] = 1;
    }
    res[0] = 0;
    // int index = 1;
    for (int i = 0; i < G->n(); i++) {
      int min = minVertex(D);
      // res[index++] = min;
      double tmp;
      for (int w = G->first(min); w < G->n(); w = G->next(min, w)) {
        tmp = (1-double(G->weight(min, w))/100)*res[w];
        if (res[w] > tmp)
          res[w] = tmp;
      }
      G->setMark(min, VISITED);
    }
    // res[0] = index;
    return res;
  }

  int minVertex(int* D)  // Find min cost vertex
  {
    int i, v = -1;
    // Initialize v to some unvisited vertex
    for (i = 0; i < G->n(); i++)
      if (G->getMark(i) == UNVISITED) {
        v = i;
        break;
      }
    for (i++; i < G->n(); i++)  // Now find smallest D value
      if ((G->getMark(i) == UNVISITED) && (D[i] < D[v])) v = i;
    return v;
  }

  void AddEdgetoMST(int v1, int v2) {
    cout << "Add edge " << v1 << " to " << v2 << "\n";
  }

  void Prim(int* D, int s)  // Prim's MST algorithm
  {
    int V[G->n()];
    for (int i = 0; i < G->n(); i++) {
      int min = minVertex(D);
      G->setMark(min, VISITED);
      if (D[min] == INFINITY) return;
      if (V[min] != min) AddEdgetoMST(V[min], min);
      for (int w = G->first(min); w < G->n(); w = G->next(min, w)) {
        if (D[w] > G->weight(min, w)) {
          D[w] = G->weight(min, w);
          V[w] = min;
        }
      }
    }
  }
};

#endif  // GRAPH_TEST_H_INCLUDED
