#include "Store.h"

Store::Store()
{
}


Store::~Store()
{
}

void Store::doAction(string input)
{
	Action* a;
	a = ActionFactory::create(input);
	a->doAction(input, movies, accounts);
}

void Store::addMovie(string input)
{
	Movie* m;
	m = MovieFactory::createMovie(input);
	movies.insert(std::pair<string, Movie*>(m->getIndex(), m));
}

void Store::remMovie(string)
{
}

void Store::addCustomer(string input)
{
	Customer* a = new Customer(input);
	accounts.add(a);
}

Customer* Store::remCustomer(int input)
{
	return accounts.getEntry(input);
}
