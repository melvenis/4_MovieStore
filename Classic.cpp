#include "Classic.h"


Classic::Classic(string input)
{
	stringstream info(input);
	string rmSpace; //remove unwanted whitespace
	info >> stock;
	getline(info, rmSpace, ' ');
	getline(info, director, ',');
	getline(info, rmSpace, ' ');
	getline(info, title, ',');
	getline(info, rmSpace, ' ');
	getline(info, actor, ' ');
	getline(info, rmSpace, ' '); //gets last name
	actor.append(rmSpace); //combine name
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
		<< ", " << title << ", " << actor << ", "
		<< month << " " << year << endl;
}

Classic::~Classic()
{
}