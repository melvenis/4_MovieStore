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

string Movie::getIndex()
{
	return indexer;
}
