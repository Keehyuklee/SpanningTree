#include "Vertex.h"

Vertex::Vertex(void)
{
	vNext = nullptr;
	adj = nullptr;
}

Vertex::~Vertex(void)
{
}

void Vertex::setname(char* c)
{
	strcpy(name,c);
}