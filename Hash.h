#pragma once
#include "Customer.h"
class Hash
{
public:
	Hash();
	~Hash();
	static int hash(Customer*,int,int,int);
	static int hash(int, int, int, int);
};

