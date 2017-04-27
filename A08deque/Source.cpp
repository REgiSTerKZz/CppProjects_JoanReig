#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include "Header.h"


int main() {
	//DEQUE

	std::deque<float> prices(10, 10.50);
	prices[9] = 32.43;
	prices.erase(prices.begin());
	std::deque<float> newprices(prices);
	newprices.insert(newprices.begin(), 5.64);
	newprices.insert(newprices.begin(), 20.31);
	newprices.insert(newprices.begin() + 1, 10);
	for (auto ite = prices.rbegin(); ite != prices.rend(); ++ite) {
		std::cout << *ite << std::endl;
	}
	std::cout << std::endl;
	for (auto ite = newprices.begin(); ite != newprices.end(); ++ite) {
		std::cout << *ite << std::endl;
	}
	std::cout << std::endl;

	// VECTOR

	std::vector<float> vprices(10, 10.50);
	vprices[9] = 32.43;
	vprices.erase(vprices.begin());
	vprices.erase(vprices.begin());
	std::vector<float> newvprices(vprices);
	newvprices.insert(newvprices.begin(), 5.64);
	newvprices.insert(newvprices.begin(), 20.31);
	newvprices.insert(newvprices.begin() + 1, 10);
	for (auto ite = newvprices.rbegin(); ite != newvprices.rend(); ++ite) {
		std::cout << *ite << std::endl;
	}
	std::cout << std::endl;
	for (auto ite = newvprices.begin(); ite != newvprices.end(); ++ite) {
		std::cout << *ite << std::endl;
	}
	std::cout << std::endl;

	// FUNCTIONS

	std::priority_queue<int> un(5, 10);
	std::priority_queue<int> dos(5, 20);
	std::priority_queue<int> merge = superMergeP(un, dos);

	std::queue<std::string> sun({"HOLA"});
	std::queue<std::string> sdos({"hola"});
	std::queue<std::string> resul = concatQueue(sun,sdos);


	system("pause");
	return 0;
}

std::priority_queue<int> superMergeP(std::priority_queue<int> A, std::priority_queue<int> B) {
	while (!B.empty()) {
		A.push(B.top());
		B.pop();
	}
	return A;
}

std::queue<std::string> concatQueue(std::queue<std::string> A, std::queue<std::string> B) {
	for (int it = 0; it < B.size(); it++) {
		A.push(B.front());
		B.pop();
	}
		
	return A;
}

std::queue<int> shiftRight(std::queue<int> A) {
	for (int it = A.size(); it >= 0; it++) {

	}
	return A;
}

std::queue<int> rotateLeft(std::queue<int> A) {
	return A;
}

std::deque<int> eraseElements(std::deque<int> A, int value) {
	for (auto i = 0; i != A.size(); ++i) {
		if (A[i] == value) {
			A.erase(A.begin() + (i-1));
		}
	}
	return A;
}

std::deque<int> eraseRepeated(std::deque<int> A) {
	for (auto i = A.begin(); i != A.end(); ++i) {
		for (auto j =i+1; j != A.end(); ++j) {
			if (*i == *j) {
				A.erase(i);
			}
		}
	}
	return A;
}