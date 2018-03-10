#pragma once
#include <string>
#include <list>
using namespace std;
class Customer
{
public:
	Customer();
	~Customer();
	void displayHistory();
	bool addTransaction(Transaction);
	bool isBorrowed(Movie);
	int getID();
private:
	int id;
	string name;
	list<string> history;

};

