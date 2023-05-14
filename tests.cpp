#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BSTree.h"

TEST_CASE("rsearch")
{
	BSTree *d = new BSTree;
	d->setup();
	CHECK(d->searchr(200) == -1);
	CHECK(d->searchr(32) == -1);
	CHECK(d->searchr(3) == 3);
	CHECK(d->searchr(10) == 10);
	CHECK(d->searchr(30) == 30);

	d->insert(50);
	CHECK(d->searchr(50) == 50);
}

TEST_CASE("delete") 
{
	BSTree *d = new BSTree;
	d->setup();
	d->remove(15); //leaf case
	CHECK(d->get_debug_string() == ", 3, , 5, , 8, , 10, , 20, , 30, ");

	d->remove(20); //one child case
	CHECK(d->get_debug_string() == ", 3, , 5, , 8, , 10, , 30, ");
	
	d->remove(5); //two child case 
	CHECK(d->get_debug_string() == ", 3, , 8, , 10, , 30, ");
}

TEST_CASE("countLeaves")
{
	BSTree *d = new BSTree;
	d->setup();
	CHECK(d->countLeaves() == 4);

	BSTree *d2 = new BSTree;
	CHECK(d2->countLeaves() == 0);
	d2->insert(50);
	CHECK(d2->countLeaves() == 1);
	d2->insert(25);
	CHECK(d2->countLeaves() == 1); //still would be 1
}

TEST_CASE("height"){
	BSTree *d = new BSTree;
	d->setup();
	CHECK(d->height() == 3);

	BSTree *d2 = new BSTree;
	CHECK(d2->height() == 0);
	d2->insert(60);
	CHECK(d2->height() == 1);
}