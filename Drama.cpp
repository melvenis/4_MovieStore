#include "Drama.h"
#include <sstream>
#include <iostream>


Drama::Drama(string input)
{
	stringstream info(input);
	info >> stock;
	remaining = stock; //none borrowed
	info.ignore(); //remove whitespace
	getline(info, director, ',');
	getline(info, title, ',');
	info >> year;
	indexer = DRAMA;
	indexer.append(director).append(title);
}

bool Drama::operator<(Drama)
{
	return false;
}

bool Drama::operator>(Drama)
{
	return false;
}

bool Drama::operator==(Drama)
{
	return false;
}

void Drama::display()
{
	cout << "D, " << stock << ", " << director
		<< ", " << title << ", " << year << endl;
}

string Drama::transDisplay()
{
	string tran = "F, " + director + ", " + title
		+ ", " + to_string(year);
	return tran;
}

//destructor
Drama::~Drama()
{
}