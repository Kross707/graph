#include<vector>

template<typename T>
class Node
{
private:
	T data;
	std::vector<Node*> connections;
public:
	Node() = delete;
	Node(T data)
	{
		this->data = data;
	}

	void connect(Node* id) 
	{
		this->connections.push_back(id);
	}
	inline T getData() const { return this->data; }
	inline std::vector<Node*> getConnections() const { return this->connections; }
};

