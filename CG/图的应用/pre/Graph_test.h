#ifndef GRAPH_TEST_H_INCLUDED
#define GRAPH_TEST_H_INCLUDED
#define INFINITY 1000000
#include <queue>
#include<iostream>
#include "graph.h"
#include "grlist.h"

class option
{
private:
    Graph *G;
public:
// Start with some implementations for the abstract functions
    option(Graph *g)
    {
        G = g;
    }


    void DFS(int v, void (*PreVisit)(int v), void (*PostVisit)(int v), void (*Visiting)(int v))   // Depth first search
    {
		    PreVisit(v);           // Take appropriate action ǰ�����

			Visiting(v);

 			G->setMark(v, VISITED);

  			for (int w=G->first(v); w<G->n(); w = G->next(v,w))

    		if(G->getMark(w) == UNVISITED)
    			
    			DFS(w,(*PreVisit), (*PostVisit), (*Visiting));
    		
    		PostVisit(v);
    }

    void BFS(int start, void (*PreVisit)(int v), void (*PostVisit)(int v), void (*Visiting)(int v))
    {
		int v=0, w=0;
		
		queue<int> Q;
		
		 Q.push(start);         // Initialize Q ��ʼ������Q
		
		 G->setMark(start, VISITED);
		
		  while(Q.size() != 0) { //Process all vertices on Q  ����Q�����ж���
			
			v =Q.front();
			
			Q.pop();
			
			if(v==start) PreVisit(v);
		
			Visiting(v);
		
		
		    for(w=G->first(v); w<G->n(); w = G->next(v,w))
		
		      if(G->getMark(w) == UNVISITED) {
		      	
		      	PreVisit(w);  
		
		       G->setMark(w, VISITED);
		
		       Q.push(w);
		
		      }
		      PostVisit(v);
    }
}

    void Dijkstra1(int* D, int s)
    {

		  int i, v, w;
		
		  for (i=0;i<G->n(); i++) {      // Process the vertices ����ڵ�
		
		    v =minVertex(D);
		
		    if (D[v] ==INFINITY) return; //Unreachable vertices���ɴ�ڵ�
		
		   G->setMark(v, VISITED);
		
		    for (w=G->first(v); w<G->n(); w =G->next(v,w))
		
		      if (D[w]> (D[v] + G->weight(v, w)))
		
		        D[w] = D[v] + G->weight(v, w);
		
		  }
    }

    int minVertex(int* D)   // Find min cost vertex
    {
        int i, v = -1;
        // Initialize v to some unvisited vertex
        for (i = 0; i < G->n(); i++)
            if (G->getMark(i) == UNVISITED)
            {
                v = i;
                break;
            }
        for (i++; i < G->n(); i++) // Now find smallest D value
            if ((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
                v = i;
        return v;
    }

    void AddEdgetoMST(int v1, int v2)
    {
        cout << "Add edge " << v1 << " to " << v2 << "\n";
    }
    void Prim(int* D, int s)   // Prim's MST algorithm
    {
	  int V[G->n()];                     // Store closest vertex �洢����ڵ�
	
	  int i, w;
	
	  for (i=0;i<G->n(); i++) {         // Process the vertices ����ڵ�
	
	    int v =minVertex(D);
	
	   G->setMark(v, VISITED);
	
	    if (v != s)
	
	     AddEdgetoMST(V[v], v);         // Add edge to MST ��MST����ӱ�
	
	    if (D[v] ==INFINITY) return;    // Unreachable vertices ���ɴ�ڵ�
	
	    for(w=G->first(v); w<G->n(); w = G->next(v,w))
	
	      if (D[w]> G->weight(v,w)) {
	
	        D[w] =G->weight(v,w);       // Update distance ���¾���
	
	        V[w] =v;                    // Where it came from��¼�ڵ�
	
	      }
	
	  }
    }
};

#endif // GRAPH_TEST_H_INCLUDED
