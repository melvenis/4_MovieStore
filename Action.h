#pragma once
#include <string>
#include <map>
#include <vector>
#include "Movie.h"
#include "Customer.h"
#include "myHashTable.h"
using namespace std;

class Action
{
public:
	Action();
	virtual ~Action();
	virtual void doAction(string, map<string, Movie*>&,
		myHashTable<Customer>&) = 0;
}; 