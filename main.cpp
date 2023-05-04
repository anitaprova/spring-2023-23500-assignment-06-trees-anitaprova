#include <iostream>
#include <string>
#include "Node.h"
#include "BSTree.h"

int main()
{
	BSTree *b = new BSTree;
	b->setup();
	std::cout << b->searchr(10) << "\n";
	std::cout << b->searchr(20) << "\n";
	std::cout << b->searchr(30) << "\n";
	std::cout << b->searchr(69) << "\n"; //-1
	std::cout << b->searchr(8) << "\n";

	return 0;
}