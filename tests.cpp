#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BSTree.h"

TEST_CASE("rsearch")
{
	BSTree *d = new BSTree;
	d->setup();
	CHECK(d->searchr(200) == -1);
	CHECK(d->searchr(3) == 3);
	CHECK(d->searchr(10) == 10);
	CHECK(d->searchr(30) == 30);
}

TEST_CASE("delete") 
{
	BSTree *d = new BSTree;
	d->setup();
}

TEST_CASE("countLeaves")
{
	BSTree *d = new BSTree;
	d->setup();
	CHECK(d->countLeaves() == 4);
}

TEST_CASE("height"){
	BSTree *d = new BSTree;
	d->setup();
	CHECK(d->height() == 3);
}