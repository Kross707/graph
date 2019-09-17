#pragma once
#include<vector>

template<typename T, typename unique_identifier = unsigned int>
class Node
{
private:
	T data;
	unique_identifier id;
	std::vector<Node*> connections;
public:
	Node() = delete;
	Node(unique_identifier id, T data)
	{
		this->data = data;
		this->id = id;
	}

	void connect(Node<T, unique_identifier>* N)
	{
		this->connections.push_back(N);
	}
	inline T getData() const { return this->data; }
	inline unique_identifier getId() const { return this->id; }
	inline std::vector<Node<T, unique_identifier>*> getConnections() const { return this->connections; }
};

