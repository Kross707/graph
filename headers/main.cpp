#include "graph2.h"
#include<iostream>
#include<vld.h>

int main()
{
	graph<int> G;
	G.defineNode("A", 2);
	G.defineNode("B", 3);
	G.defineNode("C", 4);
	G.bindNode("A", "B");
	G.bindNode("B", "C");
	G.display();
	std::cin.get();
	return 0;
}