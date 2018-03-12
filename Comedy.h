#pragma once
#include "Movie.h"
class Comedy : public Movie
{
public:
	Comedy(string);
	~Comedy();
	bool operator<(Comedy);
	bool operator>(Comedy);
	bool operator==(Comedy);
	void display();	//standard display with stock
	string transDisplay(); //display for transactions
private:
	string director;
};

