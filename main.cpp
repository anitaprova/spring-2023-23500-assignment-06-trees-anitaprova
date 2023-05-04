#include <iostream>
#include <string>
#include "Node.h"
#include "BSTree.h"

int main()
{
	BSTree *b = new BSTree;
	b->setup();
	std::cout << b->searchr(10) << "\n";

	return 0;
}