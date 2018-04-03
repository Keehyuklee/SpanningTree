#ifndef MaxPriorityQueue_H_
#define MaxPriorityQueue_H_

#include <iostream>
#include "Node.h"

using namespace std;


class MaxPriorityQueue
{
private:
	Node* mqHead;
	
public:
	MaxPriorityQueue(void);
	~MaxPriorityQueue(void);
	void Push(Node* n);
	Node* pop();
	Node* gethead(){return mqHead;}
	void printQueue();
};

#endif