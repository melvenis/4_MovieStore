#pragma once
#include <string>
#include <list>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
class Customer
{
public:
	Customer(string);
	~Customer();
	void displayHistory();
	int getID();
	void addTransaction(string);
	bool operator==(Customer);
	vector<string> rentals();
	void giveBack(string, int);

private:
	int id;
	string name;
	list<string> history;
	vector<string> rented;
};

