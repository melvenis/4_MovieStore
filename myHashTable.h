#pragma once
#include "Customer.h"

const int MAXSIZE = 10006; 
const int R;
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
	Customer** accnts; //table of customer accnts
	int size; //accounts in table
	int hash(int, int); //generates index in array
};

