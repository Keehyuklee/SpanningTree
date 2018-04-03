#include "SpanningTree.h"

SpanningTree::SpanningTree(void)
{
	vHead = NULL;
	qHead = NULL;
	tmpHead = NULL;
	tree = 0;
}

SpanningTree::SpanningTree(Vertex* v, Node* q, int n)	//graph, bid, number of cities
{
	vHead = v;
	qHead = q;
	tree = n;
}

SpanningTree::~SpanningTree(void)
{
}

int mystrcmp2(char *a, char *b)		//string compare function
{
	while(*a++ == *b++)
		if(*a == '\0')
			return 0;

	if(*(--a) > *(--b))
		return 1;
	else
		return -1;  
}

void SpanningTree::MST()
{
	ofstream fout;
	fout.open("mp3.out.txt",ios::app);	//file open for printout
	
	Vertex* tmp;
	Vertex* temp;
	Vertex* fail= NULL;
	char* name;

	double lease;

	int cost = 0;
	int totalcost = 0;
	double totallease = 0;

	Node* pop = qHead;
	
	for(;pop!=NULL;pop=pop->next)	//run until queue is empty
	{
		
		Vertex* newGraph = new Vertex;	//vertex for newgraph
		newGraph->setname(vHead->name);
		tmpHead = newGraph;
		name = pop->Name;
		lease = pop->lease;

		if(isDone(vHead)==false)
		{

			for(int i = 0; i<tree-1; i++)
			{
				tmp = vHead;	//original graph
				temp = tmpHead;	//newgraph`s head

				Edge* Min;	//Has minimum cost
				Edge* etmp;
				Vertex* vMin;

				Min = new Edge;
				Min->cost = 100000;

				while(temp!=NULL)	//until newgraph is done
				{
					tmp = vHead;
					while(tmp!=NULL)	//until original graph is done
					{

						if(mystrcmp2(temp->name,tmp->name) == 0)	//if newgraph`s pointer and original`s graph is the same
						{
							etmp = tmp->adj;	//temporary edge pointer
							while(etmp!=NULL)
							{
								/////if the edge has smaller coast and more than 0 channel and it does not make cycle //////
								if(Min->cost > etmp->cost && etmp->flag==0 && etmp->channel > 0 && isCycle(etmp->name)==false)
								{
									Min = etmp;		//Min points this
									vMin = tmp;
								}
								etmp = etmp->adj;
							}
						}
						tmp = tmp->vNext;
					}
					temp = temp->vNext;
				}	//after this roop Min points the edge which has the smallest cost


				Vertex* search = tmpHead;

				while(search!=NULL)
				{
					if(mystrcmp2(search->name,Min->name)==0)
						break;

					search = search->vNext;
				}
				if(search==NULL)
				{
					Vertex* newVertex = new Vertex;
					newVertex->setname(Min->name);
					newVertex->vNext = NULL;

					search = tmpHead;
					while(search->vNext != NULL)
					{
						search = search->vNext;
					}
					search->vNext = newVertex;
				}	//add a vertex into the graph

	
				//////add two edges into the graph
				Edge* newEdge1 = new Edge;
				Edge* newEdge2 = new Edge;

				newEdge1->name = Min->name;
				newEdge1->cost = Min->cost;
				newEdge1->adj = NULL;

				newEdge2->name = vMin->name;	
				newEdge2->cost = Min->cost;
				newEdge2->adj = NULL;

				vMin = vHead;
				while(mystrcmp2(vMin->name,Min->name)!=0)
				{
					vMin = vMin->vNext;
				}

				etmp = vMin->adj;	
				while(etmp!=NULL)
				{
					if(mystrcmp2(newEdge2->name,etmp->name)==0)
						break;

					etmp = etmp->adj;
				}
			
				Min->channel--;	//subtract channel
				etmp->channel--;
				Min->flag = 1;	//flag 1 means it is already used
				etmp->flag = 1;
				cost += Min->cost;	

				search = tmpHead;
				while(mystrcmp2(search->name,newEdge1->name)!=0)
				{
					search=search->vNext;
				}
				if(search->adj==NULL)
				{
					search->adj = newEdge2;
				}
				else
				{
					etmp = search->adj;
					while(etmp->adj!=NULL)
					{
						etmp = etmp->adj;
					}
					etmp->adj = newEdge2;
				}

				search = tmpHead;
				while(mystrcmp2(search->name,newEdge2->name)!=0)
				{
					search=search->vNext;
				}
				if(search->adj==NULL)
				{
					search->adj = newEdge1;
				}
				else
				{
					etmp = search->adj;
					while(etmp->adj!=NULL)
					{
						etmp = etmp->adj;
					}
					etmp->adj = newEdge1;
				}

			}


			int k;
			Vertex* check = tmpHead;
			for(k=0; check!=NULL; k++)
			{
				check = check->vNext;
			}

			if(k==tree)	//succeeded
			{

				///////////print result/////////////
				cout << name << " holds the following connection plan:" << endl;
				fout << name << " holds the following connection plan:" << endl;
				cout << "MST : ";
				fout << "MST : ";
				Vertex* print = tmpHead;
				cout << print->name;
				fout << print->name;

				print = print->vNext;
				while(print!=NULL)
				{
					cout << "-" << print->name;
					fout << "-" << print->name;
					print = print->vNext;
				}cout << endl;fout << endl;
				cout << "Total connection cost : " << cost << endl << endl;
				fout << "Total connection cost : " << cost << endl << endl;
				totalcost += cost;
				totallease += lease;
			}
			else	//failed
			{
				Vertex* newfail = new Vertex;
				newfail->setname(name);
				newfail->vNext = NULL;

				if(fail==NULL)
				{
					fail = newfail;
				}
				else
				{
					Vertex* fs=fail;
					while(fs->vNext!=NULL)
					{
						fs = fs->vNext;
					}
					fs->vNext = newfail;
				}

			}
		}
		else
		{
			Vertex* newfail = new Vertex;
				newfail->setname(name);
				newfail->vNext = NULL;

				if(fail==NULL)
				{
					fail = newfail;
				}
				else
				{
					Vertex* fs=fail;
					while(fs->vNext!=NULL)
					{
						fs = fs->vNext;
					}
					fs->vNext = newfail;
				}
		}
		////////////////Reset////////////////
		tmpHead = NULL;
		cost = 0;

		Vertex* vReset = vHead;
		while(vReset!=NULL)
		{
			Edge* eReset = vReset->adj;
			while(eReset!=NULL)
			{
				eReset->flag = 0;
				eReset = eReset->adj;
			}
			vReset = vReset->vNext;
		}


	}
	
	/////print overall result/////
	cout << "<<Link rental fail Company List>>" << endl;
	fout << "<<Link rental fail Company List>>" << endl;
	Vertex* fs= fail;
	while(fs!=NULL)
	{
		cout << fs->name << endl;
		fout << fs->name << endl;
		fs = fs->vNext;
	}cout << endl;fout << endl;

	cout << "Total amount of lease for this year : "<<totallease << endl;
	cout << "Total amount of connection for this year : " << totalcost << endl;
	fout << "Total amount of lease for this year : "<<totallease << endl;
	fout << "Total amount of connection for this year : " << totalcost << endl;

	fout.close();
}

//////////if any vertex has no channel it returns true//////////
bool SpanningTree::isDone(Vertex* v)
{
	Vertex* vtmp = v;
	Edge* etmp;
	int TC;	//total connection
	while(vtmp!=NULL)
	{
		TC = 0;
		etmp = vtmp->adj;
		while(etmp!=NULL)
		{
			TC += etmp->channel;
			etmp = etmp->adj;
		}
		vtmp = vtmp->vNext;
		if(TC <= 0)
			return true;
	}
	return false;
}

////////////check cycle/////////////
bool SpanningTree::isCycle(char* c)
{
	Vertex* tmp = tmpHead;
	while(tmp!=NULL)
	{
		if(mystrcmp2(tmp->name,c)==0)
			return true;
		tmp = tmp->vNext;
	}
	return false;
}