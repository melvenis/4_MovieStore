#pragma once
#include "Customer.h"
#include "Hash.h"

const int MAXSIZE = 10006; 
const int R = 6007;
template <class V>
class myHashTable
{
public:
	myHashTable();
	~myHashTable();
	int getSize(); //number of stored items
	int getCapacity(); //the capacity of table
	int getSpace(); //the remaining space in table
	bool contains(V*); //search for value
	bool add(V*); //adds new value
	V* getEntry(int); //returns value
private:
	int b; //number to mod in hashing
	V** entries; //table of entries
	int size; //accounts in table

};


