#include "grlist.h"
#include "grmat.h"
#include "Graph_test.h"

//Graph *createGraph(int graph_type, int vert_num);
Graph *createGraph(int graph_type, int vert_num)
{
    Graph *g;
    g = new Graphl(vert_num);
    return g;
}


int main()
{
    Graph* G;
    int vert_num=0,enu=0;                     // 图的顶点数，编号从0开始
    cin >> vert_num>>enu;
    G = createGraph(1, vert_num);
    int fr_vert=0, to_vert=0;
	double wt=0;
    while(enu>0)
    {
    	double wt1=0;
    	cin >> fr_vert >> to_vert >> wt;
    	wt1=double((100-wt)/100);
        G->setEdge(fr_vert-1, to_vert-1, wt1);
        G->setEdge(to_vert-1, fr_vert-1, wt1);
        enu--;
    }
	int ae=0,be=0;
	cin>>ae>>be;

    option *it = new option(G);
    for (int v = 0; v < G->n(); v++)
        G->setMark(v, UNVISITED);  // Initialize mark bits

    double D[G->n()];
	for (int i = 0; i < G->n(); i++) // Initialize
        D[i] = INFINITY;
    it->Dijkstral_(D, ae-1,be-1);
    printf("%.8f\n", 100/D[be-1] - 0.000000005);
    
    return 0;
}

