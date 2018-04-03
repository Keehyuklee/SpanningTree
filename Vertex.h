#ifndef Vertex_H_
#define Vertex_H_

#include <iostream>
#include "Edge.h"

class Vertex
{
	friend class SpanningTree;
	friend class Graph;
	friend class Edge;
private:
	char name[15];
	Vertex* vNext;
	Edge* adj;
	

public:
	Vertex(void);
	~Vertex(void);
	void setname(char* c);
};

#endif