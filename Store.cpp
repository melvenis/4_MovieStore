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
	a->doAction();
}

void Store::addMovie(string input)
{
	Movie* m;
	m = MovieFactory::createMovie(input);
	movies.insert(std::pair<string, Movie*>(m->getIndex(), m));
}



void Store::inventory() {
	Movie* m;
	for (map<string, Movie*>::iterator it = movies.begin();
		it != movies.end(); ++it)
	{
		m = it->second;
		m->display();
	}
}


void Store::remMovie(string)
{
}

void Store::addCustomer(string input)
{
	Customer a(input);
	accounts.add(&a);
}

void Store::remCustomer(string input)
{
	Customer a(input);
	bool is = accounts.contains(&a);
	cout << "answer is " << is << endl;
}
