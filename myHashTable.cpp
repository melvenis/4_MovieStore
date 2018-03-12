#pragma once
#include "myHashTable.h"
template<class V>
myHashTable<V>::myHashTable()
{
	entries = new V*[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
	{
		entries[i] = NULL;
	}
	size = 0;
	b = MAXSIZE + 1;
}



template<class V>
int myHashTable<V>::getSize()
{
	return size;
}

template<class V>
int myHashTable<V>::getCapacity()
{
	return b;
}

template<class V>
int myHashTable<V>::getSpace()
{
	double space = 1.0 * b / size;
	//rounding is negligible
	return static_cast<int>(100 * space);
}





template<class V>
bool myHashTable<V>::add(V* entry)
{
	int i = 0; //colisions
	int hash;
	while (true)
	{
		hash = Hash::hash(entry, i, b, R);
		if (entries[hash] == NULL) //open space
		{
			size++;
			entries[hash] = entry;
			return true;
		}
		if (entries[hash] != NULL) {
			cout << "COLLISION!!!!" << endl;
		}
		i++; //collision found, find next space
	}
}



template<class V>
bool myHashTable<V>::contains(V * entry)
{
	int i = 0; //collisions
	int hash;
	while (true)
	{
		hash = Hash::hash(entry, i, b, R);
		if (entries[hash] == NULL) //open space
		{
			return false; //no match found
		}
		if (*entry == *entries[hash])
		{
			entry = entries[hash];
			return true;
		}
		i++; //collision found, continue search
	}
}





//THIS ONE MAKES NO SENSE
//*********
//*********
template<class V>
V * myHashTable<V>::getEntry(int id)
{
	int i = 0;
	int hash;
	hash = Hash::hash(id, i, b, R);
	if (entries[hash] == NULL) //open slot
	{
		return NULL; //not found
	}
	return entries[hash];
}

template<class V>
myHashTable<V>::~myHashTable()
{
	//destroy all entries in hash table
	for (int i = 0; i < MAXSIZE; i++) 
	{
		entries[i] = NULL;
	}
	delete[] entries; //free memory
}