#include "Comedy.h"
#include <iostream>
#include <sstream>

Comedy::Comedy(string input)
{
	stringstream info(input);
	info >> stock;
	remaining = stock; //none borrowed
	info.ignore(); //ignore whitespace
	info.ignore();
	getline(info, director, ',');//set director
	info.ignore();
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

string Comedy::transDisplay()
{
	string tran = "F, " + director + ", " + title 
		+ ", " + to_string(year);
	return tran;
}

//destructor
Comedy::~Comedy()
{
}