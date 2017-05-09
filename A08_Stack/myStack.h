#pragma once
class myStack
{
	struct node
	{
		int info;
		node* next;
	};
public:
	myStack();
	node* S;			// Aquest atribut és el que em permetrà poder accedir al primer node de la llista
	void pop();			// Eliminarà el primer element de la fila/pila/llista....
	void push(int l);	// Insertarà l'elements "l"
	int top();			// Retornarà el primer element de la fila
	int size();			// Retorna el nombre d'elemens de la fila
	bool isEmpty();		// Comprova si esta buit o no
	myStack();
	myStack(myStack& st);
	myStack(int size, int value);
	~myStack();
};

