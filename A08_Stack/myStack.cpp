#include "myStack.h"



myStack::myStack()
{

}

myStack::myStack(myStack & st)
{
	
}

myStack::myStack(int size, int value)
{

}

void myStack::pop()
{
	node * pointer = S;
	S = S->next;
	delete pointer;
}

void myStack::push(int l)
{
	node * pointer = new node{ {l}, {S} };
	S = pointer;
}

int myStack::top()
{
	return S->info;
}

int myStack::size()
{
	int siz = 0;
	node * contador = S;
	if (contador->next) {
		return 0;
	}
	else
	{
		siz = 1;
		while (contador->next != nullptr){
			++siz;
			contador = contador->next;
		}
	}
	return 0;
}

bool myStack::isEmpty()
{
	if (S == nullptr) {
		return true;
	}
	else {
		return false;	
	}
}


myStack::~myStack()
{
}
