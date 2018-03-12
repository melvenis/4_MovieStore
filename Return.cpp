#include "Return.h"


Return::Return()
{
}


Return::~Return()
{
}

void Return::doAction(string trans, map<string, Movie*>& movies, 
	myHashTable<Customer>& accounts)
{
	vector<string> tokens(5);  //contains movie details

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
	//search for movie (safe method so not found won't crash)
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

	//esnure customer has actually borrowed this movie
	vector<string> rnt = client->rentals();
	string check = m->transDisplay(); //movie rental signature
	for (int i = 0; i < rnt.size(); i++)
	{
		if (check == rnt.at(i)) //movie found
		{
			m->turnIn(); //increase available movies by 1
			client->giveBack(check, i); //return movie on client history
			return;
		}
	}

	//movie wasn't rented by customer, send alert
	cout << "Movie was not rented by this customer." << endl;
}