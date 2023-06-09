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
		throw ERR_EMPTY;
	}

	int node_val = current->getData();
	if (node_val == value)
	{
		return node_val;
	}
	else if (node_val > value)
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
		throw NOT_FOUND;
	}

	if (p->getData() == value)
	{
		return p->getData();
	}
	else if (p->getData() > value)
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

void BSTree::remove(int n)
{
	Node *current = root;
	Node *trailer = nullptr;

	while (current != nullptr) // getting it to the proper location
	{
		int val = current->getData();
		if (n == val)
		{
			break;
		}
		else if (n < val)
		{
			trailer = current;
			current = current->getLeft();
		}
		else
		{
			trailer = current;
			current = current->getRight();
		}
	}

	if (current->getLeft() == nullptr && current->getRight() == nullptr) // case: leaf
	{
		if (trailer->getLeft()->getData() == n)
		{
			trailer->setLeft(nullptr);
		}
		else
		{
			trailer->setRight(nullptr);
		}
		delete current;
	}
	else if (current->getLeft() != nullptr && current->getRight() != nullptr) // case 3: two children
	{
		// finding largest node on left subtree
		Node *w = new Node;
		Node *t = new Node;
		w = current->getLeft();
		int large = w->getData(); // initial value so it isnt null
		while (w != nullptr)
		{
			if (w->getData() > large)
			{
				large = w->getData();
			}
			w = w->getLeft();
			t = w;
		}
		// replacing
		current->setData(large);
		current->setLeft(nullptr);
	}
	else // case 2: one child
	{
		if (current->getLeft() != nullptr)
		{
			trailer->setLeft(current->getLeft());
		}
		else
		{
			trailer->setRight(current->getRight());
		}
		free(current);
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

int BSTree::countLeaves()
{
	int total = 0;
	Node *n = new Node;
	n = root;

	if (n == nullptr)
	{
		return 0;
	}
	else if (n->getLeft() == nullptr && n->getRight() == nullptr) // head is a leaf
	{
		return 1;
	}
	else if (n->getLeft() == nullptr)
	{
		total = total + countLeaves(n->getRight(), total);
	}
	else if (n->getRight() == nullptr)
	{
		total = total + countLeaves(n->getLeft(), total);
	}
	else
	{
		total = total + countLeaves(n->getLeft(), total) + countLeaves(n->getRight(), total);
	}
	return total;
}

int BSTree::countLeaves(Node *n, int total) // helper function
{
	if (n->getLeft() == nullptr && n->getRight() == nullptr)
	{
		return total + 1;
	}
	else
	{
		total = total + countLeaves(n->getLeft(), total) + countLeaves(n->getRight(), total);
	}
	return total;
}

int BSTree::height()
{
	Node *n = new Node;
	n = root;
	int h = 0;

	if (n == nullptr)
	{
		return h;
	}
	else if (n->getLeft() == nullptr && n->getRight() == nullptr) // leaf
	{
		return h + 1;
	}

	int left = 0;
	int right = 0;
	if (n->getLeft() != nullptr)
	{
		left = height(n->getLeft(), h + 1);
	}

	if (n->getRight() != nullptr)
	{
		right = height(n->getRight(), h + 1);
	}

	if (left > right)
	{
		return left;
	}
	else
	{
		return right;
	}
}

int BSTree::height(Node *n, int h) // helper function
{
	if (n == nullptr)
	{
		return h;
	}

	int left = height(n->getLeft(), h + 1);
	int right = height(n->getRight(), h + 1);
	if (left > right)
	{
		return left;
	}
	else
	{
		return right;
	}
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