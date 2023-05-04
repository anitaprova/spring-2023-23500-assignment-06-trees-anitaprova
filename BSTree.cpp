#include "Node.h"
#include "BSTree.h"

BSTree::BSTree()
{
	root = nullptr;
}

std::string BSTree::traverse(Node *n)
{
	std::string a, b, c;

	if (n == nullptr)
	{
		return "";
	}
	else
	{
		a = traverse(n->getLeft());
		b = std::to_string(n->getData());
		c = traverse(n->getRight());

		return a + ", " + b + ", " + c;
	}
}

std::string BSTree::get_debug_string()
{
	return traverse(root);
}

/*
	if the BST is full/balanced
	this will behave like a binary search - remove 1/2
	the data set each time through
	so O(lgn) preformance

	IF THE tree isn't full/balanced it degenerates
	into a linked list and you only get O(n)

*/
int BSTree::search(int n)
{
	Node *current = root;

	while (current != nullptr)
	{
		int node_val = current->getData();
		if (n == node_val)
		{
			return node_val;
		}
		else if (n < node_val)
		{
			current = current->getLeft();
		}
		else
		{
			current = current->getRight();
		}
	}
	throw 1; // returning a not found value would be better
}

int BSTree::searchr(int value)
{
	Node *current = root;
	if (current == nullptr)
	{
		return -1;
	}

	int node_val = current->getData();
	if (node_val == value)
	{
		return node_val;
	}
	else if (node_val < value)
	{
		node_val = searchr(value, current->getLeft());
	}
	else
	{
		node_val = searchr(value, current->getRight());
	}
	return node_val;
}

int BSTree::searchr(int value, Node *p)
{
	if (p == nullptr)
	{
		return -1;
	}

	if (p->getData() == value)
	{
		return -1;
	}
	else if (p->getData() < value)
	{
		return searchr(value, p->getLeft());
	}
	else
	{
		return searchr(value, p->getRight());
	}
}

void BSTree::insert(int n)
{
	Node *new_node = new Node(n);

	// special case if the tree is empty
	if (root == nullptr)
	{
		root = new_node;
		return;
	}

	// search for the insertion point
	Node *current = root;
	Node *trailer = nullptr;
	while (current != nullptr)
	{
		trailer = current; // catch the trailer up
		int val = current->getData();
		if (n == val)
		{
			// update the node with the additional stuff
			return;
		}
		else if (n < val)
		{
			current = current->getLeft();
		}
		else
		{
			current = current->getRight();
		}
	}
	// if we get here, trailer points to the
	// node above the new node's location
	if (n < trailer->getData())
	{
		trailer->setLeft(new_node);
	}
	else
	{
		trailer->setRight(new_node);
	}
}

int BSTree::treesum(Node *n)
{
	if (n == nullptr)
	{
		return 0;
	}
	else
	{
		int value = n->getData();
		return value + treesum(n->getLeft()) + treesum(n->getRight());
	}
}

int BSTree::treesum()
{
	return treesum(root);
}

int BSTree::countodds(Node *n)
{
	if (n == nullptr)
	{
		return 0;
	}
	else
	{
		int data = n->getData();
		int value;
		if (data % 2 == 0)
		{
			value = 0;
		}
		else
		{
			value = 1;
		}
		return value + countodds(n->getLeft()) + countodds(n->getRight());
	}
}

int BSTree::countodds()
{
	return countodds(root);
}

int BSTree::oddsum(Node *n)
{
	if (n == nullptr)
	{
		return 0;
	}
	else
	{
		int data = n->getData();
		int value;
		if (data % 2 == 0)
		{
			value = 0;
		}
		else
		{
			value = data;
		}
		return value + oddsum(n->getLeft()) + oddsum(n->getRight());
	}
}

int BSTree::oddsum()
{
	return oddsum(root);
}

void BSTree::setup()
{
	Node *n = new Node(10);
	root = n;
	n = new Node(20);
	root->setRight(n);
	Node *n2 = new Node(30);
	n->setRight(n2);
	n2 = new Node(15);
	n->setLeft(n2);
	n2 = new Node(5);
	root->setLeft(n2);
	n = new Node(3);
	n2->setLeft(n);
	n = new Node(8);
	n2->setRight(n);
}