#include "Node.h"

Node Node::BlockNode()
{
	for (int i = 0; i < connections.size(); i++)
	{
		Node* connectedNode = connections[i];
		for (int j = 0; j < connectedNode->connections.size(); j++)
		{
			if (this == connectedNode->connections[j])
			{
				connectedNode->connections.erase(connectedNode->connections.begin() + j);
				break;
			}
		}
	}
	connections.clear();
	blocked = true;

	return *this;
}
