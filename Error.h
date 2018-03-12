#pragma once
#include <iostream>
#include "Action.h"
class Error : public Action
{
public:
	Error();
	~Error();
	void doAction(string, map<string, Movie*>&,
		myHashTable<Customer>&);
};

