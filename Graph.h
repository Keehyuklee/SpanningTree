#ifndef Graph_H_
#define Graph_H_

#include <iostream>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

class Graph
{
	friend class ConnectionPlanner;
private:
	int vertices;
	Vertex* vHead;

public:
	Graph(void);
	Graph(int v);
	~Graph(void);
	void creategraph(char* city,char* con);
};

#endif