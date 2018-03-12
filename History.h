#pragma once
#include "Action.h"
class History : public Action
{
public:
	History();
	~History();
	void doAction(string, map<string, Movie*>&,
		myHashTable<Customer>&);
};

