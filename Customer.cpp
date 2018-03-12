#include "Customer.h"
using namespace std;

//constructor, creates customer with string containing ID and name
Customer::Customer(string input)
{
	stringstream line(input);
	line >> id;
	line.ignore(); //ignore whitespace
	getline(line, name);
	rented.reserve(1);
}

//displays customers transactions from oldest to new
void Customer::displayHistory()
{
	string idHlp = to_string(id);
	for (int i = 4 - idHlp.length(); i > 0; i--)
	{
		idHlp = "0" + idHlp;
	}
	cout << "Customer History: #" << idHlp << " " << name << endl; //heading
	for (auto it = history.begin(); it != history.end(); it++) //traverse list
	{
		cout << *it << endl;
	}
}

//returns customer's id number
int Customer::getID()
{
	return id;
}

//adds a new transaction to the customers list
//param trans: the string containing the transactino info
void Customer::addTransaction(string borrow)
{
	history.push_front("Borrowed: " + borrow); //add history
	rented.push_back(borrow);//add to borrowed array
}

//compares two customers by id and name
bool Customer::operator==(Customer c)
{
	bool check = false;
	check = (id == c.id);
	check = (name == c.name);
	return (id == c.id && name == c.name);
}

//retrieves the list of rented movies
vector<string> Customer::rentals()
{
	return rented;
}

void Customer::giveBack(string trans, int index)
{
	addTransaction("Returned: " + trans); //add transaction
	rented.erase(rented.begin() + index); //remove borrowed
}

//destructor, clears the list of transactions
Customer::~Customer()
{
	history.clear();
}