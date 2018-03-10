#pragma once
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
class MovieFactory
{
public:
	MovieFactory();
	~MovieFactory();
	Movie static createMovie(char);
};

