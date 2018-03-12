#pragma once
#include "Movie.h"
const string DRAMA = "44"; //value for sorting genres
class Drama : public Movie
{
public:
	Drama(string);
	~Drama();
	bool operator<(Drama);
	bool operator>(Drama);
	bool operator==(Drama);
	friend ostream& operator<<(ostream&, Drama&);
	void display();

private:
	string director;
};

