#pragma once
#include <string>
using namespace std;

//allows for easy sorting in map, also allows expansion of any number
//of future genres as "11111111" will come before 22 etc.
const string COMEDY = "22"; 
const string DRAMA = "44"; 
const string CLASSIC = "66";

class Movie
{
public:
	Movie();
	virtual ~Movie();
	int getStock();
	int getRemaining();
	void rent();
	void turnIn();
	virtual void display() = 0;	//standard display with stock
	virtual string transDisplay() = 0; //display for transactions
	string getIndex();
protected:
	int stock;
	int remaining;
	int year;
	string title;
	string indexer;
};

