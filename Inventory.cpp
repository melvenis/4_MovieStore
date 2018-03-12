#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::doAction(string, map<string, Movie*>& movies,
	myHashTable<Customer>& accounts)
{
	Movie* m;
	for (map<string, Movie*>::iterator it = movies.begin(); 
		it != movies.end(); ++it)
	{
		m = it->second;
		m->display();
	}
}
