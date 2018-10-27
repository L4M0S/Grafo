#include"graph.h"
#include"stack.h"
#include"queue.h"
#include"btree.h"

#include<cstdlib>
#include<cstdio>

#include<iostream>

using namespace std;

graph::graph(int vertex)
{
	n=vertex;
	
	e=new bool[(n*(n-1)/2)];
	for(int i=0;i<(n*(n-1)/2);i++)
	{
		e[i]=0;
	}
	
	ARREGLO=new bool[(n*(n-1)/2)];
	for(int i=0;i<(n*(n-1)/2);i++)
	{
		ARREGLO[i]=0;
	}
}

void graph::printadjacency()
{
	int x=1;
	int y=2;
	int a=0;
	for(int i=2;i<=n;i++)
	{
		if(i<10)cout<<i<<":  ";
		else cout<<i<<": ";
		
		for(int j=0;j<x;j++)
		{
			cout<<e[a]<<"  ";
			a++;
		}
		x++;
		cout<<endl;		
	}
	
	cout<<"    ";
	for(int i=1;i<n;i++)
	{
		if(i<10)cout<<i<<"  ";
		else cout<<i<<" ";
	}
	cout<<endl;
	/*
	for(int i=0;i<(n*(n-1)/2);i++)
	{
		
		cout<<e[i]<<" ";
		//cout<<endl;
	}
	cout<<endl;
	*/
}

int graph::indexingarray(int i,int j)
{
	if(i<j) 
	{
		int aux =i;
		i=j;
		j=aux;
	}
	if(i==j) return 0;
	
	return ((i-1)*(i-2)/2)+(j-1);
}

bool graph::askedge(int i, int j)
{
	if(i<j) 
	{
		int aux =i;
		i=j;
		j=aux;
	}
	return e[indexingarray(i,j)];
}

void graph::addedge(int i,int j)
{
	if(i<j) 
	{
		int aux =i;
		i=j;
		j=aux;
	}
	e[indexingarray(i,j)]=1;
}

void graph::deledge(int i,int j)
{
	if(i<j) 
	{
		int aux =i;
		i=j;
		j=aux;
	}
	e[indexingarray(i,j)]=0;
}

btree graph::adjacentes(int i,btree N)
{
	for(int j=1;j<=n;j++)
	{
		if(e[indexingarray(i,j)]) /*cout<<j;*/N.ins(j);
	}
	return N;
}

queue graph::adjacentes(int i,queue Vecindad)
{
	for(int j=1;j<=n;j++)
	{
		if(e[indexingarray(i,j)]) /*cout<<j;/*/Vecindad.enqueue(j);
	}
	return Vecindad;
}

stack graph::dfs(int source,int target)//deep-first search
{
	btree M;//Marcados
	
	stack Stack;
	
	int u;
	int v;//vertice adjacente
	
	Stack.push(source);
	
	while(!Stack.empty())
	{
		u=Stack.top();
		
		M.ins(u);
		btree N;//adjacentes a u
		N=adjacentes(u,N);
		
		for(int i=1;i<=n;i++)
		{
			if(N.search(i)&&!M.search(i))
			{
				v=i;
				i=n+1;
			}		
		}
		
		if(N.search(v)&&!M.search(v))
		{
			Stack.push(v);
			
			if(v==target) return Stack;
		}
		else Stack.pop();
	}
	return Stack;
}

bool graph::bfs(int source,int target)//breadth-first search
{
	btree M;//conjunto de vertices-conjunto de marcado
	
	queue Queue;
	
	int u,v;
	
	Queue.enqueue(source);
	M.ins(source);
				
	
	while(!Queue.empty())
	{
		u=Queue.dequeue();
		btree N;//adjacentes a u
		N=adjacentes(u,N);
		
		for(int i=1;i<=n;i++)
		{
			if(N.search(i)&&!M.search(i))
			{
				v=i;
				M.ins(v);				
				ARREGLO[indexingarray(u,v)]=1;
				
				if(v==target) 
				{
					for(int i=0;i<(n*(n-1)/2);i++)
				{
					e[i]=ARREGLO[i];
				}
					return true;
				}
				Queue.enqueue(v);
			}		
		}
	}
	return false;
}

stack graph::sp(int source,int target)//shortest path
{
	btree M;//conjunto de vertices-conjunto de marcado
	btree N;//conjunto de vertices adjacentes
	queue Queue;
	stack StackVacia;
	int u,v;
	
	int profundida=bfs(source,target);
	
	if(profundida==false) return StackVacia;
	
	Queue.enqueue(source);
	M.ins(source);
	
	while(!Queue.empty())
	{
		u=Queue.dequeue();
		btree N;//adjacentes a u
		N=adjacentes(u,N);
		
		for(int i=1;i<=n;i++)
		{
			if(N.search(i)&&!M.search(i))
			{
				v=i;
				if(v==target) return dfs(source,target);
				Queue.enqueue(v);
			}
		}
	}
	
	return StackVacia;//secuencia vacia
}
