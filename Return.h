#pragma once
#include "Action.h"
#include "ActionFactory.h"
class Return : public Action
{
public:
	Return();
	~Return();
	void doAction(string, map<string, Movie*>&,
		myHashTable<Customer>&);
};

