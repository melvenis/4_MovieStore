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
