// DynArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DynArray.hh"
// contrusctors
DynArray::DynArray() :			// declarar les variables amb aquesta llista es més eficient (aixi tenim el cos de la fnció sense res)
	m_capacity ( DYN_ARRAY_DEFAULT_SIZE),	m_data ( new int[m_capacity]),	m_size ( DYN_ARRAY_DEFAULT_SIZE)
{
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
	return m_data;
}

int * DynArray::end(void) const
{
	return m_data + m_size;
}

// metodos
void DynArray::fill(int * first, int * last, int value)
{

	while (first != last) {
		*first = value;
		++first;
	}
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

void DynArray::push(const int & val)
{
	if (m_size < m_capacity) {
		m_data[m_size] = val;
	}
	else {
		int *d_data = new int[m_size + 1];
		for (int i = 0; i < m_size; i++) {
			d_data[i] = m_data[i];
		}
		d_data[m_size] = val;
		delete[] m_data;
		m_data = d_data;
		m_capacity++;
		
	}
	m_size++;
}

void DynArray::pop(void)
{

}

void DynArray::erase(size_t position)
{

}

size_t DynArray::capacity(void) const
{
	return size_t();
}
