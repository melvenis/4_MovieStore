#pragma once
#include "Movie.h"
#include <sstream>
#include <iostream>


class Classic : public Movie
{
public:
	Classic(string);
	~Classic();
	bool operator<(Classic);
	bool operator>(Classic);
	bool operator==(Classic);
	void display(); //standard display with stock
	string transDisplay(); //display for transactions
private:
	string director;
	string actor;
	int month;
	void generateIndex();
};


