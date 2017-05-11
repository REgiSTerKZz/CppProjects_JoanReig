#pragma once
#include <list>

std::list<int> superMerge(std::list<int> A, std::list<int> B);
std::list<int> change(std::list<int> &A);
int getElementPos(std::list<int> A, int value);
std::list<int> removeDuplicates(std::list<int> &A);

bool palindrome(std::list<int> A);