#pragma once
#include "Movie.h"
class Drama : public Movie
{
public:
	Drama(string);
	~Drama();
	bool operator<(Drama);
	bool operator>(Drama);
	bool operator==(Drama);
	void display();//standard display with stock
	string transDisplay(); //display for transactions



private:
	string director;
};

