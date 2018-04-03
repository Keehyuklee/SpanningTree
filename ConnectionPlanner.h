#ifndef ConnectionPlanner_H_
#define ConnectionPlanner_H_

#include <iostream>
#include "Graph.h"
#include "File.h"
#include "Bidder.h"
#include "SpanningTree.h"

using namespace std;

class ConnectionPlanner
{
public:
	ConnectionPlanner(void);
	~ConnectionPlanner(void);
	void operation();
};

#endif