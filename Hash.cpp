#include "Hash.h"



Hash::Hash()
{
}


Hash::~Hash()
{
}

int Hash::hash(Customer* c, int i, int b, int r)
{
	int id = c->getID();
	int h2 = i * (r - (id % r));
	return (id + h2) % b;
}

int Hash::hash(int id, int i, int b, int r)
{
	int h2 = i * (r - (id % r));
	return (id + h2) % b;
}

