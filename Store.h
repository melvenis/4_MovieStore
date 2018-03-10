#pragma once
#include "myHashTable.h"
#include "MovieFactory.h"
#include "ActionFactory.h"
#include "MediaFactory.h"
#include "Customer.h"
#include <map>
#include <vector>

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
private:
	myHashTable account;
	vector<map<char, Movie>> movies;
};

