#include "Classic.h"


Classic::Classic(string input)
{
	stringstream info(input);
	string temp;
	info >> stock;
	remaining = stock; //none borrowed
	info.ignore();
	info.ignore();
	getline(info, director, ',');
	info.ignore();
	getline(info, title, ',');
	info.ignore();
	getline(info, actor, ' ');
	getline(info, temp, ' '); //gets last name
	actor += " " + temp; //combine name
	info >> month;
	info >> year;
	generateIndex();
}

//creates an index for storing in store inventory
void Classic::generateIndex() {
	string monthHelp = to_string(month);
	if (monthHelp.length() == 1) //single dig month
	{
		monthHelp = "0" + monthHelp; //fix single digit month
	}
	indexer = CLASSIC; //each genre has uniq tag for sorting
	indexer.append(to_string(year)).append(monthHelp)
		.append(actor);
}


bool Classic::operator<(Classic)
{
	return false;
}

bool Classic::operator>(Classic)
{
	return false;
}

bool Classic::operator==(Classic)
{
	return false;
}


void Classic::display()
{
	cout << "C, " << stock << ", " << director
		<< ", " << title << ", " << actor << " "
		<< month << " " << year << endl;
}

string Classic::transDisplay()
{
	string tran = "C, " + director + ", " + title + ", " + actor +
		" " + to_string(month) + " " + to_string(year);
	return tran;
}

Classic::~Classic()
{
}