#include "Graph.h"

Graph::Graph(void)
{
	vertices = 0;
	vHead = nullptr;
}

Graph::Graph(int v)
{
	vertices = v;

}

Graph::~Graph(void)
{
}

int a_to_i(char* arr)
{
	int result=0;
	int i,j=1,temp=0;
	for(i=0 ; arr[i]!= NULL ; i++)
		temp++;
	for(i=1 ; i<temp ; i++)
		j = j*10;
	for(i=0 ; i<temp ; i++)
	{
		result = result + (arr[i]-'0')*j;
		j=j/10;
	}

	return result;
}

int mystrcmp(char *a, char *b)		//string compare function
{
	while(*a++ == *b++)
		if(*a == '\0')
			return 0;

	if(*(--a) > *(--b))
		return 1;
	else
		return -1;  
}

void Graph::creategraph(char* city, char* con)		//create graph
{
	char* cities=NULL;
	char* city1,* city2,* c_cost,* c_channel;
	int cost, channel;

	Vertex* newGraph = new Vertex;

	cities = strtok(city,"\n");	//read city
	newGraph->setname(cities);	//set vertex
	vHead = newGraph;	//head points it

	for(int k=1; k<vertices; k++)	//make vertices and make a linked list
	{	
		cities = strtok(NULL,"\n");
		Vertex* newGraph = new Vertex;
		newGraph->setname(cities);
		Vertex* tmp;
		tmp = vHead;
		while(tmp->vNext !=NULL)
		{
			tmp = tmp->vNext;
		}
		tmp->vNext = newGraph;
	}

	int i = 0, j = 0;
	while(con[i]!=NULL)	//read con
	{
		if(con[i] == '\n')
			j++;

		i++;
	}
	j++;

	city1 = strtok(con, "	");	
	city2 = strtok(NULL, "	");
	c_cost = strtok(NULL, "	");
	c_channel = strtok(NULL,"	\n");
	cost = a_to_i(c_cost);
	channel = a_to_i(c_channel);

	Vertex* tmp1,* tmp2;	//points vertex who has the same name with file
	tmp1= tmp2 = vHead;


	while(tmp1!=NULL)
	{
		if(mystrcmp(tmp1->name,city1)==0)
			break;
		else
			tmp1 = tmp1->vNext;
	}

	while(tmp2!=NULL)
	{
		if(mystrcmp(tmp2->name,city2)==0)
			break;
		else
			tmp2 = tmp2->vNext;
	}



	Edge* etmp1 = new Edge;	//make edges
	Edge* etmp2 = new Edge;
	Edge* tmp;

	etmp1->setedge(city2,cost,channel);	//set edges
	etmp2->setedge(city1,cost,channel);

	////////connect edges to vertices//////////
	if(tmp1->adj == NULL)
	{
		tmp1->adj = etmp1;
	}
	else
	{
		tmp = tmp1->adj;
		while(tmp->adj!=NULL)
		{
			tmp = tmp->adj;
		}
		tmp->adj = etmp1;
	}


	if(tmp2->adj == NULL)
	{
		tmp2->adj = etmp2;
	}
	else
	{
		tmp = tmp2->adj;
		while(tmp->adj!=NULL)
		{
			tmp = tmp->adj;
		}
		tmp->adj = etmp2;

	}
	for(i=1;i<j;i++)
	{
		tmp1= tmp2 = vHead;

		city1 = strtok(NULL, "	");
		city2 = strtok(NULL, "	");
		c_cost = strtok(NULL, "	");
		c_channel = strtok(NULL,"	\n");
		cost = a_to_i(c_cost);
		channel = a_to_i(c_channel);
		while(tmp1!=NULL)
		{
			if(mystrcmp(tmp1->name,city1)==0)
				break;
			else
				tmp1 = tmp1->vNext;
		}

		while(tmp2!=NULL)
		{
			if(mystrcmp(tmp2->name,city2)==0)
				break;
			else
				tmp2 = tmp2->vNext;
		}



		Edge* etmp1 = new Edge;
		Edge* etmp2 = new Edge;
		Edge* tmp;

		etmp1->setedge(city2,cost,channel);
		etmp2->setedge(city1,cost,channel);


		if(tmp1->adj == NULL)
		{
			tmp1->adj = etmp1;
		}
		else
		{
			tmp = tmp1->adj;
			while(tmp->adj!=NULL)
			{
				tmp = tmp->adj;
			}
			tmp->adj = etmp1;
		}


		if(tmp2->adj == NULL)
		{
			tmp2->adj = etmp2;
		}
		else
		{
			tmp = tmp2->adj;
			while(tmp->adj!=NULL)
			{
				tmp = tmp->adj;
			}
			tmp->adj = etmp2;

		}


	}

/*
	/////////Print The Graph///////////////
	Vertex* vp = vHead;
	Edge* ep;
	for(int k=0;k<vertices;k++)
	{
		ep = vp->adj;
		cout << vp->name;
		while(ep!=NULL)
		{
			cout << "-" << ep->name;
			ep = ep->adj;
		}
		cout << endl;

		vp = vp->vNext;

	}
*/
}


