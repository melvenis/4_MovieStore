#include "Customer.h"
#include <iostream>
#include <sstream>
using namespace std;

Customer::Customer(string input)
{
	stringstream line(input);
	line >> id;
	getline(line, name, ' ');//flush whitespace
	getline(line, name);
}


Customer::~Customer()
{
	history.clear();
}

void Customer::displayHistory()
{
	while (!history.empty())
	{
		cout << history.front() << endl;
		history.pop_front();
	}
}

int Customer::getID()
{
	return id;
}

bool Customer::operator==(Customer c)
{
	return (id == c.id && name == c.name);
}

void Customer::display()
{
	cout << id << " " << name << endl;
}
