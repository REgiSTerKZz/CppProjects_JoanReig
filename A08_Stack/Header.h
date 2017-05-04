#pragma once
#include <stack>
#include <string>
#include <queue>

std::stack<int> superMerge(std::stack<int> A, std::stack<int> B);
std::stack<std::string> putHat(std::stack<std::string> A, std::stack<std::string> B);
std::queue<int> transformToQ(std::stack<int> A);

void change(std::stack<int>& A);