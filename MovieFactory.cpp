#include "MovieFactory.h"



MovieFactory::MovieFactory()
{
}


MovieFactory::~MovieFactory()
{
}

Movie* MovieFactory::createMovie(string input)
{
	Movie* m;
	char type = input.at(0);
	string info = input.substr(3);
	switch (type)
	{
	case 'C': m = new Classic(info);
		break;
	case 'D': m = new Drama(info);
		break;
	case 'F': m = new Comedy(info);
		break;
	default: cout << "Error --Invalid Movie Format" << endl;
		m = NULL;
		break;
	}
	return m;
}
