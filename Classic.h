#pragma once
#include "Movie.h"
#include <sstream>
#include <iostream>

const string CLASSIC = "66"; //value for sorting genres
class Classic : public Movie
{
public:
	Classic(string);
	~Classic();
	bool operator<(Classic);
	bool operator>(Classic);
	bool operator==(Classic);
	void display();
private:
	string director;
	string actor;
	int month;
	void generateIndex();
};


