#pragma once
#include <string>
using namespace std;
class Movie
{
public:
	Movie();
	virtual ~Movie();
	int getStock();
	virtual void display() = 0;
	string getIndex();
protected:
	int stock;
	int year;
	string title;
	string indexer;
};

