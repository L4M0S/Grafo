#include"btree.h"
#include"queue.h"

#include<cstdlib>
#include<cstdio>

btree::btree()
{
	root=nullptr;
	//n=c;
	s=0;
}

bool btree::empty()
{
	return s==0;
}

/*
bool btree::full()
{
	return s==n;
}
*/

long btree::size()
{
	return s;
}

/*
long btree::capacity()
{
	return n;
}
*/

bool btree::ins(long x)
{
	if(empty())
	{
		root=new bnode(x);
		s++;
		return true;
	}
	else
	{
		bnode *p=root;
		bnode *q=nullptr;
		while(p&&p->data()!=x)
		{
			q=p;
			p=x<p->data()?p->left():p->right();
		}
		
		if(!p)
		{
			if(x<q->data())q->left(new bnode(x));
			else q->right(new bnode(x));
			s++;
			return true;
		}
	}
	return false;
}

void btree::print()
{
	print(root);
}

void btree::print(bnode *p)
{
	if(!p) return;
	print(p->left());
	printf("%i",p->data());
	print(p->right());
}



queue btree::rnode()
{
	return rnode(root);
}

queue btree::rnode(bnode *root)
{
	queue rqueue;
	if(!root) return rqueue;
	
	
	
	rnode(root->left());
	rqueue.enqueue(root->data());
	rnode(root->right());
	
	return rqueue;
}

bool btree::search(long x)
{
	bnode *p;
	p=root;
	
	while (p!=nullptr && p->data()!=x)
	{
		if(x<p->data()) p=p->left();
		else p=p->right();
	}
	if(p!=nullptr) return true;
	else return false;
}
