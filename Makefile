OBJECTS = BSTree.o Node.o
CXXFLAGS = -g
LDFLAGS =
CXX=g++

main: main.o $(OBJECTS)
	$(CXX) -g -o main main.o $(OBJECTS)

tests: tests.o $(OBJECTS)
	g++ -g -o tests tests.o $(OBJECTS)

main.o: main.cpp BSTree.h Node.h

tests.o: tests.cpp doctest.h Node.h

BSTree.o: BSTree.cpp BSTree.h

Node.o: Node.cpp Node.h

clean: 
	rm -f main tests main.o tests.o $(OBJECTS)