#ifndef STACK_H
#define STACK_H

#include<cstdlib>
#include"node.h"


//////////////////////////////////////////////////////////////////////

class stack
{
	//int n=NULL;	//capacity
	int s=NULL; //size
	
	node *init;
	
	public:
		
		stack();
		//stack(int);
		//~stack();
	
		//int *list=NULL;
		
		//int capacity();
		int size();
	
		//int clear();
		
		bool empty();
		//bool full();
		
		void push(long);
		int pop();
		int top();
	
};

#endif
