#include "Edge.h"

Edge::Edge(void)
{
	name = NULL;
	cost = 0;
	channel = 0;
	adj = NULL;
	flag = 0;
}

void Edge::setedge(char* n, int c, int ch)	//set edge
{
	name = n;
	cost = c;
	channel = ch;
}


Edge::~Edge(void)
{
}
