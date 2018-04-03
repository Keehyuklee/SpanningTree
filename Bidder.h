#ifndef Bidder_H_
#define Bidder_H_

#include <iostream>
#include "Node.h"
#include "MaxPriorityQueue.h"

using namespace std;

class Bidder
{
public:
	Bidder(void);
	~Bidder(void);
	Node* Bid(char* bid);
};

#endif