#pragma once
#include "Action.h"
#include "ActionFactory.h"
class Borrow : public Action
{
public:
	Borrow();
	~Borrow();
	void doAction(string, map<string, Movie*>&, 
		myHashTable<Customer>&);
};

