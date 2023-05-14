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

	BSTree *b2 = new BSTree;
	b2->insert(50);
	std::cout << "leaves: " << b2->countLeaves() << "\n";
	std::cout << "b2height: " << b2->height() << "\n";
	std::cout << b2->get_debug_string() << "\n";
	b2->insert(100);
	std::cout << "leaves: " << b2->countLeaves() << "\n";
	std::cout << "b2height: " << b2->height() << "\n";
	std::cout << b2->get_debug_string() << "\n";

	b->remove(15); // leaf
	b->remove(20); // one child
	b->remove(5);	 // two child
	std::cout << b->get_debug_string() << "\n";

	return 0;
}