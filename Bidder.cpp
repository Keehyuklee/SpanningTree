#include "Bidder.h"

int a_to_i2(char* arr)
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


double ctod(char* input)	//char type into double type
{
	char* c;
	double result = 0, tens = 1, temp;
	int ud = 0 , i;
	c = new char[2];
	c[1] = NULL;
	i = 0;
	while(input[i]!=NULL)
	{
		if(input[i]=='.')
		{
			ud = 1;
		}
		else if(!ud)
		{
			c[0] = input[i];
			temp = a_to_i2(c);
			result = result*10 + temp;
		}
		else
		{
			tens = tens/10;
			c[0] = input[i];
			temp = a_to_i2(c);
			result = result+tens*temp;
		}
		i++;
	}
	return result;
}

Bidder::Bidder(void)
{
}

Bidder::~Bidder(void)
{
}

Node* Bidder::Bid(char* bid)
{
	int i = 0, j = 0;
	while(bid[i]!=NULL)
	{
		if(bid[i] == '\n')
			j++;

		i++;
	}
	j++;	//count numbers of cities

	MaxPriorityQueue MQ;
	char* name;
	char* money;
	char* context=NULL;
	double Lease;
	
	name = strtok_s(bid,"	",&context);	
	money = strtok_s(NULL,"\n",&context);
	Lease = ctod(money);
	Node* newNode = new Node;
	newNode->lease = Lease;
	newNode->setname(name);	//set the new Node
	
	MQ.Push(newNode);

	for(int k=0; k<j-1; k++)
	{

		name = strtok_s(NULL,"	",&context);
		money = strtok_s(NULL,"\n",&context);
		Lease = ctod(money);

		Node* newNode = new Node;
		newNode->lease = Lease;
		newNode->setname(name);
		
		MQ.Push(newNode);

	}
//	MQ.printQueue();
	return MQ.gethead();	//return queue`s head
}