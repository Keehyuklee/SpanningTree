#include "MaxPriorityQueue.h"

MaxPriorityQueue::MaxPriorityQueue(void)
{
	mqHead = NULL;
}

MaxPriorityQueue::~MaxPriorityQueue(void)
{
}

void MaxPriorityQueue::Push(Node *n)	//push
{	

	////////make a linked list////////
	if(mqHead == NULL)	//if queus`s head is empty
	{
		mqHead = n;
		n->next = NULL;
	}
	else
	{
		if(n->lease > mqHead->lease)
		{
			n->next = mqHead;
			mqHead = n;
		}
		else
		{
			Node* tmp;
			tmp = mqHead;
			while(tmp->next!=NULL && n->lease < tmp->next->lease)
			{
				tmp = tmp->next;
			}

			if(tmp->next == NULL)
			{
				tmp->next = n;
				n->next = NULL;
			}
			else
			{
				n->next = tmp->next;
				tmp->next = n;
			}
			
		}
	}
}

Node* MaxPriorityQueue::pop()
{
	if(mqHead == NULL)
		return 0;

	Node* tmp = mqHead;
	mqHead = mqHead->next;

	return tmp;
}

void MaxPriorityQueue::printQueue()
{
	Node* tmp;
	tmp = mqHead;
	while(tmp!=NULL)
	{
		cout << tmp->Name << "	" << tmp->lease << endl;
		tmp = tmp->next;
	}

}