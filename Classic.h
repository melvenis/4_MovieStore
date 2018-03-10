#pragma once
#include "Movie.h"
class Classic : public Movie
{
public:
	Classic();
	~Classic();
	bool operator<(Classic);
	bool operator>(Classic);
	bool operator==(Classic);
private:
	string actor;
	int month;
};

