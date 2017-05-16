#include "myList.h"



myList::myList()
{
	first = new node{ {1}, {nullptr}, {nullptr} };
	last = first;
}

myList::myList(const myList & L)
{
	size_t tama�o = L.mida;
	node* aux, *nodaux;
	first = new node{ L.first->info , nullptr , nullptr };
	
	while (tama�o >= 0) {
		nodaux = first->next;
		aux = new node{ nodaux->info , nullptr , first->next };

		tama�o--;
	}
}


myList::~myList()
{
}
