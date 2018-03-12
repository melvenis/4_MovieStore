#include "Comedy.h"
#include <iostream>
#include <sstream>

Comedy::Comedy(string input)
{
	stringstream info(input);
	string rmSpace; //remove unwanted whitespace
	info >> stock;
	getline(info, rmSpace, ' ');
	getline(info, director, ',');//set director
	getline(info, rmSpace, ' ');
	getline(info, title, ','); //set title
	info >> year; //set year
	indexer = COMEDY; //map reference
	indexer.append(title).append("" + year);
}

bool Comedy::operator<(Comedy)
{
	return false;
}

bool Comedy::operator>(Comedy)
{
	return false;
}

bool Comedy::operator==(Comedy)
{
	return false;
}

void Comedy::display()
{
	cout << "F, " << stock << ", " << director
		<< ", " << title << ", " << year << endl;
}

//destructor
Comedy::~Comedy()
{
}