#include"bnode.h"

#include<cstdlib>
#include<cstdio>

bnode::bnode(long x)
{
	core=x;
	_left=nullptr;
	_right=nullptr;
}

long bnode::data()
{
	return core;
}

bnode* bnode::left()
{
	return _left;
}

bnode* bnode::left(bnode *p)
{
	return _left= p;
}

bnode* bnode::right()
{
	return _right;
}

bnode* bnode::right(bnode *p)
{
	return _right= p;
}
