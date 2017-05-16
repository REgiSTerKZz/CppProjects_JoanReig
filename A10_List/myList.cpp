#include "myList.h"



myList::myList()
{
	first = new node{ {1}, {nullptr}, {nullptr} };
	last = first;
}

myList::myList(const myList & L)
{
	size_t tamaño = L.mida;
	node* aux, *nodaux;
	first = new node{ L.first->info , nullptr , nullptr };
	
	while (tamaño >= 0) {
		nodaux = first->next;
		aux = new node{ nodaux->info , nullptr , first->next };

		tamaño--;
	}
}


myList::~myList()
{
}
