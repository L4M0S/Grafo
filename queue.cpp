#include"queue.h"
#include"node.h"

#include<cstdlib>
#include<cstdio>

//////////////////////////////////////////////////////////////////////

queue::queue()//(int c)
{
	//n=c;
	s=0;
	init=nullptr;
	eoqueue=nullptr;
}

/*
int queue::capacity()
{
	return n;
}
*/

int queue::size()
{
	return s;
}

bool queue::empty()
{
	return s==0;
}

/*
bool queue::full()
{
	return s==n;
}
*/

void queue::enqueue(long x)
{
	/*
	if(full())
	{
		printf("LLENO");
		return;
	}
	*/
	if(empty()) {init=eoqueue=new node(x); s++;}
	/*{
		node aux=new node(x);
		init=aux;
		eoqueue=aux;
	}*/
	else
	{
		eoqueue->next(new node(x));
		eoqueue=eoqueue->next();
		s++;
	}
	/*	
	node *p=new node(x);
	p->next(init);
	init=p;
	s++;*/
}

int queue::front()
{
	if(empty())
	{
		//printf("VACIA");
		return 0;
	}
	
	return init->data();
}

int  queue::dequeue()
{
	if(empty())
	{
		//printf("VACIA");
		return 0;
	}
	
	long x=init->data();
	node *p=init;
	init=p->next();
	delete p;
	s--;
	return x;
}
