#pragma once
#include <algorithm>
#include "Node.h"

#define GRAPH_SIZE 15
#define NODE_SPACING 32

class Graph
{
public:
	Node nodes[GRAPH_SIZE][GRAPH_SIZE];

	// Debug Variable
	std::vector<Node*> path;

	Graph();
	Graph(const Graph& other) = delete;
	const Graph& operator=(const Graph& other) = delete;

	std::vector<Node*> AStar(Node* start, Node* end);

	float Herustic(Node* currentNode, Node* endNode);

	void Draw() const;

	void ResetNodes();

	void ClearPrevious();

private:
	void ConnectNodesIfPossible(int xCoord1, int yCoord1, int xCoord2, int yCoord2);
};

