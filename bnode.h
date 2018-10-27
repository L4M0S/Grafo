#ifndef BNODE_H
#define BNODE_H

class bnode
{
	long core;
	bnode *_left;
	bnode *_right;
	
	public:
		
		bnode(long);
		long data();
		bnode *left();
		bnode *left(bnode *);
		bnode *right();
		bnode *right(bnode *);
};

#endif
