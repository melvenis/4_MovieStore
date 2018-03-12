#pragma once
#include "Action.h"
#include "Store.h"
class Inventory : public Action
{
public:
	Inventory();
	~Inventory();
	void doAction(string, map<string, Movie*>&,
		myHashTable<Customer>&);
};

