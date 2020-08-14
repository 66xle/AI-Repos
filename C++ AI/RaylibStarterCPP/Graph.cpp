#include "Graph.h"
#include <algorithm>

Graph::Graph()
{
	for (int x = 0; x < GRAPH_SIZE; x++)
	{
		for (int y = 0; y < GRAPH_SIZE; y++)
		{
			nodes[x][y].position = { (float)x * NODE_SPACING + NODE_SPACING * 0.5f, (float)y * NODE_SPACING + NODE_SPACING * 0.5f };

			for (int xOffset = -1; xOffset <= 1; xOffset++)
			{
				for (int yOffset = -1; yOffset <= 1; yOffset++)
				{
					ConnectNodesIfPossible(x, y, x + xOffset, y + yOffset);
				}
			}
		}
	}
}

std::vector<Node*> Graph::AStar(Node* startNode, Node* endNode)
{
	// If either nodes are blocked return empty path
	if (startNode->blocked || endNode->blocked)
	{
		return std::vector<Node*>();
	}

	// Create temp list for storing visited nodes
	std::vector<Node*> openList;
	std::vector<Node*> closedList;

	openList.push_back(startNode);

	// While openList is not empty
	while (openList.size() > 0)
	{
		// Sort openList by fScore
		std::sort(openList.begin(), openList.end(), [](const Node* first, const Node* second)
			{
				return first->fScore < second->fScore;
			});

		// Set first node in openList to currentNode
		Node* currentNode = openList[0];

		// Remove currentNode from openList
		openList.erase(openList.begin());


		// If Path is found
		if (currentNode == endNode)
		{
			std::vector<Node*> finalPath;
			finalPath.push_back(currentNode);

			while (currentNode->previous)
			{
				currentNode = currentNode->previous;
				finalPath.push_back(currentNode);
			}
			return finalPath;
		}

		currentNode->visited = true;

		closedList.push_back(currentNode); // Add currentNode to closedList

		// Loop through currentNode conncections 
		for (Node* connectedNode : currentNode->connections)
		{

			if (std::find(closedList.begin(), closedList.end(), connectedNode) != closedList.end())
			{
				continue;
			}


			float gScore = currentNode->gScore + NODE_SPACING;
			float hScore = Herustic(connectedNode, endNode);
			float fScore = gScore + hScore;

			// If in openList
			if (std::find(openList.begin(), openList.end(), connectedNode) != openList.end())
			{
				if (fScore < connectedNode->fScore)
				{
					connectedNode->gScore = gScore;
					connectedNode->fScore = fScore;
					connectedNode->previous = currentNode;
				}
			}
			else
			{
				connectedNode->gScore = gScore;
				connectedNode->fScore = fScore;
				connectedNode->previous = currentNode;
				openList.push_back(connectedNode);
			}
		}
	}

	return std::vector<Node*>();
}

float Graph::Herustic(Node* connectedNode, Node* endNode)
{
	float dx = abs(connectedNode->position.x - endNode->position.x);
	float dy = abs(connectedNode->position.y - endNode->position.y);

	return dx + dy;
}

void Graph::Draw() const
{
	for (int x = 0; x < GRAPH_SIZE; x++)
	{
		for (int y = 0; y < GRAPH_SIZE; y++)
		{
			if (!nodes[x][y].blocked)
			{
				for (auto thisConnectedNode : nodes[x][y].connections)
				{
					Vector2 halfwayPoint = { (nodes[x][y].position.x * 0.5f + thisConnectedNode->position.x * 0.5f),
						(nodes[x][y].position.y * 0.5f + thisConnectedNode->position.y * 0.5f) };
					DrawLineEx(nodes[x][y].position, halfwayPoint, 1.5, PURPLE);
				}
			}
		}
	}

	for (int x = 0; x < GRAPH_SIZE; x++)
	{
		for (int y = 0; y < GRAPH_SIZE; y++)
		{
			if (!nodes[x][y].blocked)
			{
				if (nodes[x][y].visited)
				{
					DrawCircleV(nodes[x][y].position, 2, YELLOW);
				}
				else
				{
					DrawCircleV(nodes[x][y].position, 2, RED);
				}
			}
		}
	}
}

void Graph::ResetNodes()
{
	for (int x = 0; x < GRAPH_SIZE; x++)
	{
		for (int y = 0; y < GRAPH_SIZE; y++)
		{
			nodes[x][y].visited = false;
		}
	}
}

void Graph::ClearPrevious()
{
	for (int x = 0; x < GRAPH_SIZE; x++)
	{
		for (int y = 0; y < GRAPH_SIZE; y++)
		{
			nodes[x][y].previous = nullptr;
		}
	}
}

void Graph::ConnectNodesIfPossible(int xCoord1, int yCoord1, int xCoord2, int yCoord2)
{
	if (xCoord1 == xCoord2 && yCoord1 == yCoord2)
	{
		return;
	}
	if (xCoord1 < 0 || xCoord2 < 0)
	{
		return;
	}
	if (xCoord1 >= GRAPH_SIZE || xCoord2 >= GRAPH_SIZE)
	{
		return;
	}
	if (yCoord1 < 0 || yCoord2 < 0)
	{
		return;
	}
	if (yCoord1 >= GRAPH_SIZE || yCoord2 >= GRAPH_SIZE)
	{
		return;
	}

	nodes[xCoord1][yCoord1].connections.push_back(&nodes[xCoord2][yCoord2]);
}
