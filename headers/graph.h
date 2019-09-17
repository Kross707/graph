#pragma once
#include "Node.h"
#include<map>

template<typename T, typename unique_identifier = unsigned int>
class graph
{
private:
	std::map<unique_identifier, Node<T, unique_identifier>*> elements;
public:
	graph()
	{
	}
	void defineNode(unique_identifier id, T data)
	{
		Node<T, unique_identifier>* temp;
		temp = new Node<T, unique_identifier>(id, data);

		auto ret = elements.insert(std::make_pair(id, temp));
		if (ret.second == false)
		{
			std::cout << "CANNOT REINSERT SAME ID" << std::endl;
			delete temp;
			return;
		}
	}
	void bindNode(unique_identifier id1, unique_identifier id2)
	{
		std::map<unique_identifier, Node<T, unique_identifier>*>::iterator is1 = elements.find(id1);
		if (is1 == elements.end())
		{
			std::cout << id1 << " Not found" << std::endl;
			return;
		}
		std::map<unique_identifier, Node<T, unique_identifier>*>::iterator is2 = elements.find(id2);
		if (is2 == elements.end())
		{
			std::cout << id2 << " Not found" << std::endl;
			return;
		}
		is1->second->connect(is2->second);
		is2->second->connect(is1->second);
	}
	void display()
	{
		for (auto &it : elements)
		{
			Node<T, unique_identifier>* t = it.second;
			std::cout << std::endl << "Node : [" << t->getId() << ", " << t->getData() << "]" << std::endl<<"Links : ";
			for (auto u : t->getConnections())
			{
				std::cout << "(" << t->getId() << ", " << u->getId() << ") ";
			}
			std::cout << std::endl;
		}
	}

	~graph()
	{
		std::map<unique_identifier, Node<T, unique_identifier>*>::iterator it;
		for (it = elements.begin(); it != elements.end(); ++it)
		{
			Node<T, unique_identifier>* temp = it->second;
			delete temp;
		}
	}
};