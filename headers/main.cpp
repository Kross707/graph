#include "graph.h"
#include<iostream>

int main()
{
	graph<int, std::string> G;
	G.defineNode("A", 2);
	G.defineNode("B", 3);
	G.defineNode("C", 4);
	G.defineNode("C", 6);
	G.bindNode("A", "B");
	G.bindNode("B", "C");
	G.display();
	return 0;
}