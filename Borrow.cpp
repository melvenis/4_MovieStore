#include "Borrow.h"

Borrow::Borrow()
{
}


Borrow::~Borrow()
{
}

void Borrow::doAction(string trans, map<string, Movie*>& movies,
	myHashTable<Customer>& accounts)
{

	vector<string> tokens(5);

	/*tester tes;
	tes.getTokens(tokens, trans);*/
	//takes input string and fills vector with relevant movie tokens
	ActionFactory::getTokens(tokens, trans);
	if (tokens[0].length() != 4)
	{
		return; //get tokens method found invalid input, do nothing
	}
	//valid id, find genre of movie to retreive from db
	string index;
	char ch = tokens[1].at(0); //genre element
	switch (ch)
	{
	case 'C': 
	{
		index = CLASSIC;
		if (tokens[3].length() == 1)
		{
			tokens[3] = "0" + tokens[3];
		} //appends tokens to recreate movie search index
		index.append(tokens[2]).append(tokens[3]).append(tokens[4]);
	}
		break;
	case 'D':
	{
		index = DRAMA;//appends tokens to recreate movie search index
		index.append(tokens[2]).append(tokens[3]);
	}
		break;
	case 'F':
	{
		index = COMEDY;//appends tokens to recreate movie search index
		index.append(tokens[2]).append(tokens[3]);
	}
		break;
	default: return;
	}

	Movie* m;
	//search for movie
	map<string, Movie*>::const_iterator iter = movies.find(index);
	if (iter == movies.end()) {
		//unable to find movie
		cout << "Error --Movie information does not match..." << endl
			<< "check title/actor/director etc and try again." << endl;
		return;
	}
	m = iter->second;
	
	//movie found, search client by id number
	Customer* client = accounts.getEntry(stoi(tokens[0]));
	if (client == NULL) //invalid customer id
	{
		cout << "Error --Invalid Customer ID, sign up today!" << endl;
		return;
	}
	//movie and customer ok, available in stock?
	if (m->getRemaining() <= 0)
	{
		cout << "All copies rented, could we suggest Top Gun?" << endl;
		return;
	}
	
	//all checks pass, rent to customer and list on trans history
	m->rent(); //decrease remaining by 1
	client->addTransaction(m->transDisplay()); //add transaction with movie
}