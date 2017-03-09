#include "stdafx.h"
#include "DynArray.hh"

int main() {
	int *b, *d;
	const int valor = 10;
	DynArray ma;
	DynArray mb(5, valor);
	//mb.push(20);

	b=mb.begin();	
	d=mb.end();
	return 0;
}