// DynArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DynArray.hh"
// contrusctors
DynArray::DynArray(void)
{
	m_data = new int[DYN_ARRAY_DEFAULT_SIZE];
	m_size = DYN_ARRAY_DEFAULT_SIZE;
}

DynArray::DynArray(size_t size, const int & value)
{
	m_data = new int[size];
	for (int i = 0; i < size; i++) {
		m_data[i] = value;
	}

}

DynArray::~DynArray() {
	delete[]m_data;
	m_data = nullptr;
}
int * DynArray::begin(void) const
{
	return &m_data[0];
}
int * DynArray::end(void) const
{
	return&m_data[m_size-1];
}
// metodos
void DynArray::fill(int * first, int * last, int value)
{
	int *p = first;
	do {
		*p = value;
		p++;
	} while (p != last);
}

int & DynArray::operator[](size_t n) const
{
	return m_data[n];
}

bool operator==(const DynArray & lhs, const DynArray & rhs)
{
	if (lhs.m_size != rhs.m_size) {
		return false;
	}
	else if (lhs.m_size == rhs.m_size) {
		int i = 0;
		while (i == lhs.m_size)
		{
			if (rhs[i] == lhs[i]) {
				return true;
				i++;
			}
			else if (rhs[i] == lhs[i]) {
				return false;
				break;
			}
		}
	}
}
