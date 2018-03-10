#pragma once
#include "Movie.h"
class Comedy : public Movie
{
public:
	Comedy();
	~Comedy();
	bool operator<(Comedy);
	bool operator>(Comedy);
	bool operator==(Comedy);
private:
	string director;
};

