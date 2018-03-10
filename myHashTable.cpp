#include "myHashTable.h"

//constructor, initialize size, at null
myHashTable::myHashTable()
{
	accnts = new Customer*[initSize];
	size = 0;
	capacity, b = initSize;
	r = initR;
}

//deconstructor
myHashTable::~myHashTable()
{
	//destroy all customer in hash table
	for (int i = 0; i < size; i++) {
		accnts[i] = NULL;
	}
	delete[] accnts; //free memory
}

//amount of customers
int myHashTable::getSize()
{
	return size;
}

//total capacity of hash table
int myHashTable::getCapacity()
{
	return capacity;
}

//returns the % hashtableis full
int myHashTable::getSpace()
{
	float space = 1.0 * capacity / size;
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

void myHashTable::resize(int capacity, int size)
{

}

int myHashTable::hash(int id, int collisions)
{
	int h2 = collisions * (r - (id % r));
	return (id + h2) % b;
	
	
	
	//int hash, h2;
	//bool open = false; //found open slot

	//while (true) //loop until open space found
	//{
	//	h2 = collisions * (r - (id % r));
	//	hash = (id + h2) % b;
	//	if (accnts[hash] == NULL)
	//	{
	//		return hash; //found index space
	//	}
	//	else
	//	{
	//		i++; //add collision
	//	}	
}

