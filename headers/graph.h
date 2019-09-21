#include "Node.h"

template<typename T, typename U = unsigned int, typename S = double> 
class graph
{
	std::vector<Node<T, U, S>> nodes;
public:
	graph() {}

	void add(U id, T data)
	{
		for (unsigned int i = 0; i < nodes.size(); ++i)
			if (nodes[i].getId() == id)
			{
				std::cout << "Cannot re-insert same id..." << std::endl;
				return;
			}
		nodes.emplace_back(id, data);
	}

	void connect(U id1, U id2, S connectionStrength = S(0))
	{
		unsigned int item1 = -1, item2 = -1;
		for (unsigned int i = 0; i < nodes.size(); ++i)
		{
			if (nodes[i].getId() == id1)
				item1 = i;
			if (nodes[i].getId() == id2)
				item2 = i;
			if (item1 != -1 && item2 != -1)
				break;
		}
		if (item1 == -1)
		{
			std::cout << id1 << " not found";
			return;
		}
		if (item2 == -1)
		{
			std::cout << id2 << " not found";
			return;
		}
		nodes[item1].connect(&nodes[item2], connectionStrength);
	}

	void display() const
	{
		for (unsigned int i = 0; i < nodes.size(); ++i)
			nodes[i].display();
	}
};