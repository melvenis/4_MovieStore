#include "Movie.h"
#include <iostream>
//constructor
Movie::Movie()
{
}

//destructor
Movie::~Movie()
{
}

//return number of movie in inventory
int Movie::getStock()
{
	return stock;
}

int Movie::getRemaining()
{
	return remaining;
}

void Movie::rent()
{
	remaining--;
}

void Movie::turnIn()
{
	remaining++;
}

string Movie::getIndex()
{
	return indexer;
}
