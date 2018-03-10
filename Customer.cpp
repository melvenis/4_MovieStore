#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(string input)
{
	//id = first 4 digits;
	//name = last 2 words;
}


Customer::~Customer()
{
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
	return 0;
}
