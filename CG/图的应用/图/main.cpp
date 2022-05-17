#include "Graph_test.h"
#include "grlist.h"
#include "grmat.h"

Graph *createGraph(int graph_type, int vert_num);

int main() {
  int VertexNum, EdgeNum;
  cin >> VertexNum >> EdgeNum;  //µ„ ˝°¢±ﬂ ˝
  Graph *G;
  G = createGraph(0, VertexNum);

  int fr_vert, to_vert, wt;
  for (int i = 0; i < EdgeNum; i++) {
    cin >> fr_vert >> to_vert >> wt;
    G->setEdge(fr_vert, to_vert, wt);
    G->setEdge(to_vert, fr_vert, wt);
  }

  option *it = new option(G);
  for (int v = 0; v < G->n(); v++) {
    G->setMark(v, UNVISITED);
  }

  int D[G->n()];
  for (int i = 0; i < G->n(); i++) {
    D[i] = INFINITY;
  }
  D[0] = 0;

  int start, end;
  cin >> start >> end;
  it->Dijkstra1(D, start);
  double result;
  result = 0;
  cout << result;
}

Graph *createGraph(int graph_type, int vert_num) {
  Graph *g;
  if (graph_type)
    g = new Graphl(vert_num);
  else
    g = new Graphm(vert_num);

  return g;
}
