#ifndef QUEUE_H
#define QUEUE_H

#include<cstdlib>
#include"node.h"

class queue
{
	//int n=NULL;	//capacity
	int s=NULL; //size
	
	node *init;
	node *eoqueue;
	
	public:
		
		queue();
		//queue(int);
		//~queue();
	
		//int *list=NULL;
		
		//int capacity();
		int size();
	
		//int clear();
		
		bool empty();
		//bool full();
		
		void enqueue(long);
		int dequeue();
		int front();
	
};

#endif
