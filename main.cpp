#include "Store.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Customer.h"
#include "Classic.h"
#include "Drama.h"
#include "Comedy.h"

int main()
{
	string minput = "mtest.txt";
	string cinput = "data4customers.txt";
	string ainput = "data4commands.txt";
	Store myStore;

	ifstream infile;
	infile.open(minput);
	if (!infile)
	{
		std::cout << "error opening movie data file" << std::endl;
		exit(1);
	}
	std::string line;
	while (getline(infile, line))
	{
		myStore.addMovie(line);
	}
	infile.close();
	infile.open(cinput);
	if (!infile)
	{
		std::cout << "error opening customer data file" << std::endl;
		exit(1);
	}
	while (getline(infile, line))
	{
		myStore.addCustomer(line);
	}
	infile.close();

	myStore.inventory();
	myStore.remCustomer("3333 Witch Wicked");

	

	Customer a("1221 Bill Brasky");
	Customer b("0010 Hilda Hi");
	a.display();
	b.display();
	Classic c("10, George Cukor, Holiday, Katherine Hepburn 9 1938");
	Drama d("10, Steven Spielberg, Schindler's List, 1993");
	Comedy f("10, Nora Ephron, You've Got Mail, 1998");
	f.display();
	d.display();
	c.display();


	system("pause");
}