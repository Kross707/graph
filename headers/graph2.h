#pragma once
#include "Node.h"
#include<map>
#include<string>

template<typename T, typename unique_identifier = std::string>
class graph
{
private:
	std::map<unique_identifier, Node<T>*> elements;
public:
	graph()
	{
	}
	void defineNode(unique_identifier id, T data)
	{
		Node<T>* temp;
		temp = new Node<T>(data);
		auto ptr = elements.insert(std::make_pair(id, temp));
		if (!ptr.second)
			std::cout << "CANNOT REINSERT SAME ID" << std::endl;
	}
	void bindNode(unique_identifier id1, unique_identifier id2)
	{
		std::map<unique_identifier, Node<T>*>::iterator it1 = elements.find(id1);
		std::map<unique_identifier, Node<T>*>::iterator it2 = elements.find(id2);
		if (it1 == elements.end())
		{
			std::cout << id1 << " Not found" << std::endl;
		}
		else if (it2 == elements.end())
		{
			std::cout << id2 << " Not found" << std::endl;
		}
		else
		{
			it1->second->connect(it2->second);
			it2->second->connect(it1->second);
		}
	}
	void display()
	{
		for (auto it : elements)
		{
			std::cout << it.first << " " << it.second->getData();
			std::cout << "\nNodes Currently Bound to " << it.first << ": -" << std::endl;
			for (auto t : it.second->getConnections())
			{
				std::cout << t->getData() << "\n";
			}
			std::cout << "\n";
		}
	}

	~graph()
	{
		for (auto it : elements)
		{
			Node<T> *temp; 
			temp = it.second;
			delete temp;
		}
	}
};