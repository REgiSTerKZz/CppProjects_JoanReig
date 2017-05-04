#include <iostream>
#include "Header.h"
#include <vector>
#include <iterator>
#include <algorithm>



int main() {
//	a
	std::stack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	std::stack<int> s2;
	s2.push(2);
	s2.push(4);
	s2.push(7);
	std::stack<int> s3;
//	s3 = superMerge(s1, s2);

//	b
	std::stack<std::string> s4;
	s4.push("String");
	std::stack < std::string > s5;
	s5.push("STRING");
	std::stack<std::string> s6;
	s6 = putHat(s4, s5);

//	c
	std::stack<int> s7;
	s7.push(4);
	s7.push(7);
	s7.push(17);
	std::queue<int> s8;
	s8 = transformToQ(s7);

//	d
	std::stack<int> s9;
	s7.push(4);
	s7.push(7);
	s7.push(11);
	std::stack<int> s10;
	s7.push(4);
	s7.push(7);
	s7.push(11);
	s7.push(16);
	
// e

// f
	std::stack<int> s11({5, 3, 6, 7, 1, 7});
	change(s11);

	return 0;
}


std::stack<int> superMerge(std::stack<int> A, std::stack<int> B) {
	std::stack<int> C;
	int cont = 0;
	size_t midaA = A.size();
	size_t midaB = B.size();
	while(cont <= midaA) {
		C.push(A.top());
		A.pop();
		cont++;
	}
	cont = 0;
	while (cont <= midaB) {
		C.push(B.top());
		B.pop();
		cont++;
	}
	std::vector<int> V;
	int i = 0;
	while (i <= C.size()) {
		V.push_back(C.top());
		C.pop();
		i++;
	}
	std::sort(V.begin(), V.end());
	std::stack<int> Result;
	for (auto it = V.begin(); it != V.end(); ++it) {
		Result.push(*it);
	}
	
	return Result;
}

std::stack<std::string> putHat(std::stack<std::string> A, std::stack<std::string> B) {
	int cont = 0;
	while (cont <= B.size())
	{
		A.push(B.top());
		B.pop();
		cont++;
	}
	return A;
}

std::queue<int> transformToQ(std::stack<int> A) {
	std::queue<int> Q;
	std::stack<int> B;
	int i = 0;
	size_t midaA = A.size();
	while (i < midaA)
	{
		B.push(A.top());
		A.pop();
		i++;
	}	
	i = 0;
	while (i < midaA) {
		Q.push(B.top());
		B.pop();
		i++;
	}	
	return Q;
}

bool isHat(std::stack<int> A, std::stack<int> B) {

	return false;
}

void change(std::stack<int>& A) {
	std::vector<int> Vec;
	size_t mida = A.size();
	int i = 0;
	while (i < mida) {
		Vec.insert(Vec.begin(), A.top());
		A.pop();
		i++;
	}
	int buf = Vec[0];
	Vec[0] = Vec.back();
	Vec.pop_back();
	Vec.push_back(buf);
	for (std::vector<int>::iterator i = Vec.begin(); i != Vec.end(); ++i) {
		A.push(*i);
	}
}