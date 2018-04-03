#include "ConnectionPlanner.h"

ConnectionPlanner::ConnectionPlanner(void) {}

ConnectionPlanner::~ConnectionPlanner(void) {}

void ConnectionPlanner::operation()
{
	File f;	//call File class
	
	char city[200];
	char con[1000];
	char bid[1000];
	
	////read files//////
	strcpy(city,f.read_cities());	
	strcpy(con,f.read_con());
	strcpy(bid,f.read_bid());

	int i = 0, j = 0;
	while(city[i]!=NULL)
	{
		if(city[i] == '\n')
			j++;

		i++;
	}
	j++;		//count number of cities
	
	Graph g(j);	//call Graph class
	g.creategraph(city,con);
	
	Bidder b;	//call Bidder class
	//b.Bid(bid);

	SpanningTree st(g.vHead,b.Bid(bid),j); 
	st.MST();	//make MST


}