#ifndef GRAPH_H
#define GRAPH_H

#include"stack.h"
#include"queue.h"
#include"btree.h"

class graph
{
	int n; //vertex
	int s; //size
	
	bool *e;
	bool *ARREGLO;
	
	public:
		graph(int);
		
		btree adjacentes(int,btree);
		queue adjacentes(int,queue);
		bool askedge(int,int);
		int indexingarray(int,int);
		void printadjacency();
		void addedge(int,int);
		void deledge(int,int);
		
		stack dfs(int,int);//deep-first search
		bool bfs(int,int);//breadth-first search
		stack sp(int,int);//shortest data
};

#endif
