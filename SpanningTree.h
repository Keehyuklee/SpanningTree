#ifndef SpanningTree_H_
#define SpanningTree_H_

#include <iostream>
#include <fstream>
#include "Vertex.h"
#include "Edge.h"
#include "MinPriorityQueue.h"
#include "Node.h"
#include "MaxPriorityQueue.h"

using namespace std;

class SpanningTree
{
private:
	
	Vertex* vHead;
	Vertex* tmpHead;
	Node* qHead;
	int tree;

public:
	SpanningTree(void);
	SpanningTree(Vertex* v,Node* q, int n);
	~SpanningTree(void);
	void MST();
	bool isCycle(char* c);
	bool isDone(Vertex* v);
};

#endif