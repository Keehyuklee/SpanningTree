#include "Node.h"

Node::Node(void)
{
	next=NULL;
}

Node::~Node(void)
{
}

void Node::setname(char *c)
{
	Name = c;
}
