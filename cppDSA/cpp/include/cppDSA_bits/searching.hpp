#ifndef SEARCHING_H
#define SEARCHING_H
#include "node.hpp"
#include <vector>
#include <cmath>

int LinearSearch(std::vector<int> &u, int startIndex, int endIndex, int val);
int BinarySearch(std::vector<int> &u, int startIndex, int endIndex, int val);
int TernarySearch(std::vector<int> &u, int startIndex, int endIndex, int val);
int InterpolationSearch(std::vector<int> &u, int lowIndex, int highIndex, int val);
int JumpSearch(std::vector<int> &u, int lowIndex, int highIndex, int val);
int ExponentialSearch(std::vector<int> &u, int lowIndex, int highIndex, int val);
bool CompareAllMatchedElements(Node<int> *ptr1, Node<int> *ptr2);
bool SubListSearch(Node<int> *firstList, Node<int> *secondList);

#endif