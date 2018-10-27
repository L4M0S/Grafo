#ifndef NODE_H
#define NODE_H

#include<cstdlib>

class node
{
	long _data;
	node *_next;
	
	public:
		
		node(long);
		long data();
		node *next();
		node *next(node *);
};

#endif
