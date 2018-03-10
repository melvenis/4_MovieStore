#pragma once
#include "Movie.h"
class Drama : public Movie
{
public:
	Drama();
	~Drama();
	bool operator<(Drama);
	bool operator>(Drama);
	bool operator==(Drama);

private:
	string director;
};

