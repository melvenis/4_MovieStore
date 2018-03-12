#include "Drama.h"
#include <sstream>
#include <iostream>


Drama::Drama(string input)
{
	stringstream info(input);
	string rmSpace; //remove unwanted whitespace
	info >> stock;
	getline(info, rmSpace, ' ');
	getline(info, director, ',');
	getline(info, rmSpace, ' ');
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

//destructor
Drama::~Drama()
{
}