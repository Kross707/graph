#include <vector>
#include<iostream>

template <typename T, typename U, typename S>
class Node
{
	U id;
	T data;
	std::vector<Node<T, U, S>*> connections;
	std::vector<S> strength;
public:
	Node() = delete;
	Node(U id, T data) : id(id), data(data) {}

	void modify(U id, T data) { this->id = id; this->data = data; }
	void connect(Node<T, U, S>* pointer, S strength) { this->connections.push_back(pointer); this->strength.push_back(strength); }
	void display() const
	{
		std::cout << "id = " << this->id << ", data = " << this->data << std::endl;
		for (unsigned int i = 0; i < this->connections.size(); ++i)
			std::cout << "(" << this->id << ", " << this->connections[i]->getId() << ", " << this->strength[i] << ")";
		std::cout << std::endl;
	}

	inline T getData() const { return this->data; }
	inline U getId() const { return this->id; }
	inline std::vector<Node<T, U, S>*> getConnections() const { return this->connections; }
	inline std::vector<S> getStrength() const { return this->strength; }
};