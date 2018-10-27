#ifndef BTREE_H
#define BTREE_H

#include"bnode.h"
#include"queue.h"

class btree
{
	bnode *root;
	//long n;
	long s;
	
	public:
		
		btree();
		//btree(long);
		
		bool ins(long);
		void print();
		void print(bnode *);
		bool empty();
		//bool full();
		long size();
		//long capacity();
		bool search(long);
		
		queue rnode();
		queue rnode(bnode *);
};

#endif
