#include"stack.h"
#include"node.h"

#include<cstdlib>
#include<cstdio>

//////////////////////////////////////////////////////////////////////

stack::stack()//(int c)
{
	//n=c;
	s=0;
	init=nullptr;
}

/*
int stack::capacity()
{
	return n;
}
*/

int stack::size()
{
	return s;
}

bool stack::empty()
{
	return s==0;
}

/*
bool stack::full()
{
	return s==n;
}
*/

void stack::push(long x)
{
	/*
	if(full())
	{
		printf("LLENO");
		return;
	}
	*/
	
	node *p=new node(x);
	p->next(init);
	init=p;
	s++;
}

int stack::top()
{
	if(empty())
	{
		//printf("VACIA");
		return 0;
	}
	
	return init->data();
}

int  stack::pop()
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
