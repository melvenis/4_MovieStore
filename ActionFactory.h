#pragma once
#include<string>
#include <iostream>
#include <sstream>
#include "Borrow.h"
#include "History.h"
#include "Inventory.h"
#include "Return.h"
#include "Error.h"

using namespace std;

class ActionFactory
{
public:
	ActionFactory();
	~ActionFactory();
	//creates pointer to desired action
	static Action* create(string); 
	static void getTokens(vector<string>&, string); //discerns movie tokens
};