#pragma once
#include "myHashTable.h"
#include "myHashTable.cpp"
#include "MovieFactory.h"
#include "ActionFactory.h"
#include "MediaFactory.h"
#include "Customer.h"
#include <map>

class Store
{
public:
	Store();
	~Store();
	void doAction(string);
	void addMovie(string);
	void remMovie(string);
	void addCustomer(string);
	void remCustomer(string);
	void inventory();
private:
	myHashTable<Customer> accounts;
	map<string, Movie*> movies;
	map<char, int> tester;
};

