#pragma once
#include <string>
#include <list>
using namespace std;
class Customer
{
public:
	Customer(string);
	~Customer();
	void displayHistory();
	int getID();
private:
	int id;
	string name;
	list<string> history;

};

