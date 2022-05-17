#include <iomanip>
#include <iostream>

#include "Graph_test.h"
#include "grmat.h"
using namespace std;

void PreVisit(int v) { cout << "PreVisit vertex " << v << "\n"; }

void PostVisit(int v) { cout << "PostVisit vertex " << v << "\n"; }

void Visiting(int v) { cout << "Visiting vertex " << v << "\n"; }

int main() {
  int m, n, fr_vert, to_vert, wt;
  cin >> m >> n;
  Graph* G;
  G = new Graphm(m);
  for (int i = 0; i < n; ++i) {
    cin >> fr_vert >> to_vert >> wt;
    G->setEdge(fr_vert - 1, to_vert - 1, wt);
  }
  cin >> fr_vert >> to_vert;
  option* it = new option(G);
  for (int v = 0; v < G->n(); v++) G->setMark(v, UNVISITED);
  // for (int v = 0; v < G->n(); v++)
  //   if (G->getMark(v) == UNVISITED) it->DFS(0, PreVisit, PostVisit,
  //   Visiting);
  int D[G->n()];
  for (int i = 0; i < G->n(); i++)  // Initialize
    D[i] = INFINITY;
  D[fr_vert - 1] = 0;

  double* res = it->Dijkstra2(D, fr_vert - 1, to_vert - 1);

  // for (int k = 0; k < G->n(); k++) {
  //   if (D[k] != INFINITY)
  //     cout << D[k] << " ";
  //   else
  //     cout << "Infinity"
  //          << " ";
  // }
  // cout << endl;
  // for (int i = 1; i < res[0]; i++) {
  //   cout << res[i];
  // }
  long double money = 100;
  // for (int j = res[0] - 1; j > 1; j--) {
  //   // cout << res[j - 1] << ' ' << res[j] << ' ' << G->weight(res[j - 1],
  //   // res[j])
  //   //      << endl;
  //   money /= (1 - double(G->weight(res[j - 1], res[j])) / 100);
  //   // printf("%.8f\n", money);
  //   // cout << money;
  // }
  for (int i = 0; i < G->n()+1; i++) {
      cout << res[i] << ' ';
    }
  cout << fixed << setprecision(8) << money/res[to_vert-1] << endl;
  // cout << fixed << setprecision(8) << money;
  // printf("%.8f\n", money);
}