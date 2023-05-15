#pragma once
#include <iostream>
#include <stdio.h>
#include "Node.h"

#define ERR_EMPTY 1
#define NOT_FOUND 2
#define ERR_OTHER 4

class BSTree
{
private:
	Node *root;
	std::string traverse(Node *n);

public:
	BSTree();
	void setup();
	std::string get_debug_string();
	int search(int value);
	void insert(int value);
	int treesum();
	int treesum(Node *n);
	int countodds();
	int countodds(Node *n);
	int oddsum();
	int oddsum(Node *n);

	int searchr(int value);
	int searchr(int value, Node *n);
	void remove(int n);
	int countLeaves();
	int countLeaves(Node *n, int total); //helper function 
	int height();
	int height(Node *n, int height); //helper function
};