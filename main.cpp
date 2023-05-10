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
	std::cout << b->get_debug_string() << "\n";
	std::cout << "leaves: " << b->countLeaves() << "\n";
	std::cout << "height: " << b->height() << "\n";
	b->remove(15);
	std::cout << b->get_debug_string() << "\n";

	return 0;
}