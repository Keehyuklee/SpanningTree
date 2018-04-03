#ifndef Edge_H_
#define Edge_H_

#include <iostream>

class Edge
{
	friend class SpanningTree;
	friend class Vertex;
	friend class Graph;
private:
	char* name;
	int cost;
	int channel;
	int flag;
	Edge* adj;

public:
	Edge(void);
	void setedge(char* n, int c, int ch);
	~Edge(void);
};

#endif