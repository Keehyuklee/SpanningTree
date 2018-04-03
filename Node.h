#ifndef Node_H_
#define Node_H_

#include <iostream>

class Node
{
	friend class SpanningTree;
	friend class MaxPriorityQueue;
	friend class Bidder;
private:
	char *Name;
	double lease;
	Node* next;
public:
	Node(void);
	~Node(void);
	void setname(char* c);
	char* getname(){return Name;}
	double getlease(){return lease;}
};

#endif