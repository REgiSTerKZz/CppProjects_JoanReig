#pragma once
#include<list>

class myList
{
private:
	struct node
	{
		int info;
		node *next;
		node *previous;
	};
	node* first;
	node* last;
	size_t mida;
public:
	myList();
	myList::myList(const myList &L);
	~myList();
};

