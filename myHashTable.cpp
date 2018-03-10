#include "myHashTable.h"

//constructor, initialize size, at null
myHashTable::myHashTable()
{
	accnts = new Customer*[MAXSIZE];
	size = 0;
	b = MAXSIZE + 1;
}

//deconstructor
myHashTable::~myHashTable()
{
	//destroy all customer in hash table
	for (int i = 0; i < MAXSIZE; i++) {
		accnts[i] = NULL;
	}
	delete[] accnts; //free memory
}

//amount of customer accounts
int myHashTable::getSize()
{
	return size;
}

//total capacity of hash table
int myHashTable::getCapacity()
{
	return b;
}

//returns the % hashtableis full
int myHashTable::getSpace()
{
	float space = 1.0 * b / size;
	//rounding is negligible
	return static_cast<int>(100 * space); 
}

//searches for customer via id
bool myHashTable::contains(int id)
{
	int collisions = 0;
	int hash;
	while (true)
	{
		hash = myHashTable::hash(id, collisions);
		if (accnts[hash] == NULL) //open space
		{
			return false; //no match found
		}
		if (id == accnts[hash]->getID)
		{
			return true;
		}
		collisions++; //collision found, continue search
	}
}

bool myHashTable::add(Customer* cust)
{
	int collisions = 0;
	int hash;
	while (true)
	{
		hash = myHashTable::hash(cust->getID, collisions);
		if (accnts[hash] == NULL) //open space
		{
			accnts[hash] = cust;
			return true;
		}
		collisions++; //collision found, find next space
	}
}

Customer* myHashTable::getAccnt(int id)
{
	int collisions = 0;
	int hash;
	while (true)
	{
		hash = myHashTable::hash(id, collisions);
		if (accnts[hash] == NULL) //open slot
		{
			return NULL; //not found
		}
		if (id == accnts[hash]->getID)
		{
			return accnts[hash]; //customer found
		}
		collisions++; //collision found, continue search
	}
}

int myHashTable::hash(int id, int collisions)
{
	int h2 = collisions * (R - (id % R));
	return (id + h2) % b;
}

