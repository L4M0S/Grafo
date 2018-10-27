#include"node.h"

#include<cstdlib>
#include<cstdio>

node::node(long x)
{
	_data=x;
	_next=nullptr;
}

long node::data()
{
	return _data;
}

node* node::next()
{
	return _next;
}

node* node::next(node *p)
{
	return _next= p;
}

