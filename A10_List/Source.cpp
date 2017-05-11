#include <iostream>
#include "Header.h"
#include <vector>
#include <algorithm>

int main() {

//	superMerge

	std::list<int> l1 = { 1, 2, 3, 4 };
	std::list<int> l2 = { 2, 3, 5 };
	std::list<int> l3 = superMerge(l1, l2);

//	change

	std::list<int> l4 = { 1, 2, 3, 4, 5 };
	change(l4);

//	getElementPos

	int a = getElementPos(l4, 2);

//	RemoveDuplicates

	std::list<int> l5 = { 1, 1, 2, 3, 6, 1, 4, 1, 5, 4 };
	removeDuplicates(l5);

//	removeElement



//	palindrome

	std::list<int> l9 = { 1, 2, 3, 4, 4, 3, 2, 1 };
	bool pal = palindrome(l9);
	return 0;
}

std::list<int> superMerge(std::list<int> A, std::list<int> B) {
	std::vector<int> DEC (A.begin(), A.end());
	std::list<int> Result;
	int i = 0;
	size_t mida;
	size_t midaB = B.size();
	for (auto it = 0; it < midaB; ++it) {
		DEC.push_back(B.front());
		B.pop_front();
	}
	std::sort(DEC.begin(), DEC.end());
	mida = DEC.size();
	i = 0;
	for (auto it = DEC.begin(); it != DEC.end(); ++it) {
		Result.push_front(*it);
	}
	return Result;
}

std::list<int> change(std::list<int> &A) {
	int aux = A.front();
	A.pop_front();
	A.push_front(A.back());
	A.pop_back();
	A.push_back(aux);
	return A;
}

int getElementPos(std::list<int> A, int value) {
	int res;
	int i = 0;
	while (i <= value){
		res = A.front();
		A.pop_front();
		i++;
	}
	return res;
}

std::list<int> removeDuplicates(std::list<int> &A) {
	return A;
}

bool palindrome(std::list<int> A) {
	if (A.size() % 2 != 0) {
		auto it1 = A.begin();auto it2 = A.end();
		it2--;
		bool Res = true;

		while (it1 != it2) {
			if (*it1 != *it2)
				Res = false;			
			it1++;it2--;			
		}
		return Res;
	}
	else {
		auto it1 = A.begin();auto it2 = A.end();
		it2--;
		bool Res = true;

		for (int i = 0; i < (A.size() / 2); i++) {
			if (*it1 != *it2)
				Res = false;
			it1++;it2--;
		}
		return Res;
	}
}