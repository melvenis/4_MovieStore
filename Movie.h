#pragma once
#include <string>
using namespace std;
class Movie
{
public:
	Movie();
	virtual ~Movie() = 0;
private:
	string title;
	int year;
	int stock;
};

