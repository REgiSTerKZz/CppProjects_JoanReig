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
	node* S;			// Aquest atribut �s el que em permetr� poder accedir al primer node de la llista
	void pop();			// Eliminar� el primer element de la fila/pila/llista....
	void push(int l);	// Insertar� l'elements "l"
	int top();			// Retornar� el primer element de la fila
	int size();			// Retorna el nombre d'elemens de la fila
	bool isEmpty();		// Comprova si esta buit o no
	myStack();
	myStack(myStack& st);
	myStack(int size, int value);
	~myStack();
};

