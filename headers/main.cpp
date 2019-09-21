#include "graph.h"

int main()
{
	graph<int> G;
	G.add(0, 4);
	G.add(1, 2);
	G.add(2, 5);
	G.add(3, 87);
	G.connect(0, 1, 3);
	G.connect(1, 0, 4);
	G.connect(3, 2);
	G.display();
	return 0;
}