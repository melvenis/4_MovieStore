#pragma once
#include "Movie.h"
const string COMEDY = "22"; //value for sorting genres
class Comedy : public Movie
{
public:
	Comedy(string);
	~Comedy();
	bool operator<(Comedy);
	bool operator>(Comedy);
	bool operator==(Comedy);
	friend ostream& operator<<(ostream&, Comedy&);
	void display();
private:
	string director;
};

