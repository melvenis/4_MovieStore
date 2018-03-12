#pragma once
#include <iostream>
#include "Movie.h"
#include "Action.h"
class Error : public Action
{
public:
	Error();
	~Error();
	void doAction();
};

