#pragma once
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
#include "Error.h"
class MovieFactory
{
public:
	MovieFactory();
	~MovieFactory();
	static Movie* createMovie(string);
};

