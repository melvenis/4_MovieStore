#pragma once
#include "Customer.h"
const int initSize = 13;
const int initR = 5;
class myHashTable
{
public:
	myHashTable();
	~myHashTable();
	int getSize(); //number of accounts stored
	int getCapacity(); //the capacity of table
	int getSpace(); //the remaining space in table
	bool contains(int); //search for customer
	bool add(Customer*); //adds new customer
	Customer* getAccnt(int); //returns customer
private:
	int b; //number to hash
	int r; //number for 2nd hashing
	Customer** accnts; //table of customer accnts
	int capacity; //total size of table
	int size; //accounts in table
	void resize(int, int); //resizes when too full
	int hash(int, int); //generates index in array
};

