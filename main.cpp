#include<cstdio>
#include<cstdlib>
#include<iostream>

#include"stack.h"
#include"queue.h"
#include"btree.h"
#include"graph.h"

using namespace std;

int main()
{	
	graph grafo(20);
	//agregar vertices//
	/*
	grafo.addedge(1,3);
	grafo.addedge(1,6);
	grafo.addedge(3,2);
	grafo.addedge(3,5);
	grafo.addedge(5,2);
	grafo.addedge(5,4);
	grafo.addedge(5,6);
	grafo.addedge(6,4);
	grafo.addedge(4,2);
	*/
	/////////////////////
	//*
	grafo.addedge(1,3);
	grafo.addedge(1,6);
	grafo.addedge(1,16);
	grafo.addedge(2,4);
	grafo.addedge(2,5);
	grafo.addedge(2,6);
	grafo.addedge(2,15);
	grafo.addedge(2,17);
	grafo.addedge(3,5);
	grafo.addedge(4,5);
	grafo.addedge(4,6);
	grafo.addedge(4,7);
	grafo.addedge(4,8);
	grafo.addedge(5,6);
	grafo.addedge(6,18);
	grafo.addedge(7,10);
	grafo.addedge(8,9);
	grafo.addedge(8,11);
	grafo.addedge(9,20);
	grafo.addedge(10,14);
	grafo.addedge(11,12);
	grafo.addedge(11,13);
	grafo.addedge(16,17);
	grafo.addedge(18,19);
	grafo.addedge(18,20);
	//*/
	grafo.printadjacency();
	
	int source, target;
	
	cout<<"INGRESE NODO SOURCE: ";
	cin>>source;
	cout<<"INGRESE NODO TARGET: ";
	cin>>target;
	
	stack pilasp;
	stack pilas;
	pilasp=grafo.sp(source,target);
	
	while(!pilasp.empty())
	{
		pilas.push(pilasp.pop());		
	}
	while(!pilas.empty())
	{
		cout<<"-"<<pilas.top()<<"-";
		pilas.pop();		
	}
		
	cout<<endl;
	system("pause");
	return 0;
}
