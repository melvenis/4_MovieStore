#include "ActionFactory.h"

//constructor
ActionFactory::ActionFactory()
{
}

//destructor
ActionFactory::~ActionFactory()
{
}

/*uses char at 0 of input string to determine
  action type to use
  */
Action * ActionFactory::create(string input)
{
	Action* a;
	switch (input.at(0))
	{
	case 'B': a = new Borrow();
		break;
	case 'H': a = new History();
		break;
	case 'I': a = new Inventory();
		break;
	case 'R': a = new Return();
		break;
	default: a = new Error();
		break;
	}
	return a;
}

/*
	getTokens()
	param info: string with action request, containing all transaction info
	breaks down info to correct tokens based on the genre, checking for incorrect
	input in genre or format, if so, replacing the token for customer id with '%'
	as a flag to the calling class
*/
void ActionFactory::getTokens(vector<string>& token, string info)
{
	int month, year;
	string title, actor, director;
	
	string id = info.substr(2, 4); //customer id
	token[0] = id;
	char media = info.at(7); //media char
	char genre = info.at(9); //genre char
	token[1] = genre;
	string remain = info.substr(11); //remaining substring
	stringstream ss(remain); //string stream of remaining string
	
	if (media != 'D') //valid media test
	{
		cout << "Error - No such Media Exists!" << endl;
		token[0] = "%"; //fail flag
		return;
	}
	
	//determine genre for relevant tokens, fail if not correct genre
	switch (genre)
	{
	case 'C': //classic genre
	{ 
		ss >> month;
		ss >> year;
		ss.ignore(); //ignore whitespace
		getline(ss, actor);
		token[2] = to_string(year);
		token[3] = to_string(month);
		token[4] = actor;
		return;
	}
		break;
	case 'D': //drama genre
	{
		getline(ss, director, ',');
		ss.ignore(); //ignore whitespace
		getline(ss, title);
		token[2] = director;
		token[3] = title;
		return;
	}
		break;
	case 'F': //comedy genre
	{
		getline(ss, title, ',');
		ss >> year;
		token[2] = title;
		token[3] = year;
		return;
	}
		break;
	default: cout << "Error - Invalid Genre" << endl;
		token[0] = "%"; //fail flag
		return;
	}
}
