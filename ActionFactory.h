#pragma once
#include<string>
#include "Borrow.h"
#include "History.h"
#include "Inventory.h"
#include "Return.h"
using namespace std;

class ActionFactory
{
public:
	ActionFactory();
	~ActionFactory();
	//creates pointer to desired action
	static Action* create(string); 
};

