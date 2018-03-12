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

	//Input my test customer file*********************
	//************************
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
	//*******************************************

	//*********** input my test customer files
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
	//************************************8
	
	//***RETRIeve customer test*******************
	Customer* teed = myStore.remCustomer(1);
	cout << teed->getID();
	//*********************************************8

	//**********attempt duplicate customer input*********
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

	cout << "success, next line should be blank" << endl << endl;
	myStore.doAction("B 0001 D C 8 1942 Ingrid Bergman");

	cout << "should fail customer id check." << endl;
	myStore.doAction("B 6969 D C 8 1942 Ingrid Bergman");

	cout << "should fail movie genre check" << endl;
	myStore.doAction("B 0001 D Z 8 1942 Ingrid Bergman");

	cout << "should fail movie format check" << endl;
	myStore.doAction("B 0001 C C 8 1942 Ingrid Bergman");

	cout << "should fail to find movie" << endl;
	myStore.doAction("B 0001 D C 8 1942 Engrid Bergman");
	cout << "should fail to find movie" << endl;
	myStore.doAction("B 0001 D C 18 1942 Ingrid Bergman");
	cout << "should fail to find movie" << endl;
	myStore.doAction("B 0001 D C 8 1941 Engrid Bergman");
	cout << "\n display history, should say borrow" << endl;
	teed->displayHistory();
	myStore.doAction("B 0001 D C 8 1942 Ingrid Bergman");
	myStore.doAction("B 0001 D C 8 1942 Ingrid Bergman");
	cout << "2 more for 3 total? " << endl;
	teed->displayHistory();

	cout << endl << endl << endl;
	cout << "should be none to rent" << endl;
	myStore.doAction("B 0001 D C 8 1942 Ingrid Bergman");
	cout << "try to return from wrong customer" << endl;
	myStore.doAction("R 3333 D C 8 1942 Ingrid Bergman");
	cout << "try to return from invalid customer" << endl;
	myStore.doAction("R 6969 D C 8 1942 Ingrid Bergman");
	cout << "try to return from wrong movie info" << endl;
	myStore.doAction("R 0001 x C 8 1942 Ingrid Bergman");
	cout << "try to return from wrong movie info" << endl;
	myStore.doAction("R 0001 D X 8 1942 Ingrid Bergman");
	cout << "try to return from wrong movie info" << endl;
	myStore.doAction("R 0001 D C 1 1942 Ingrid Bergman");
	cout << "try to return from wrong movie info" << endl;
	myStore.doAction("R 0001 D C 8 ");
	cout << "attempting to return 3 movies." << endl;
	myStore.doAction("R 0001 D C 8 1942 Ingrid Bergman");
	myStore.doAction("R 0001 D C 8 1942 Ingrid Bergman");
	myStore.doAction("R 0001 D C 8 1942 Ingrid Bergman");
	cout << "try to return one too many, cant return." << endl;
	myStore.doAction("R 0001 D C 8 1942 Ingrid Bergman");
	cout << "valid borrow" << endl;
	myStore.doAction("B 0001 D C 8 1942 Ingrid Bergman");
	cout << "valid borrow" << endl;
	myStore.doAction("B 3333 D C 8 1942 Ingrid Bergman");
	cout << "valid borrow" << endl;
	myStore.doAction("B 3333 D C 8 1942 Ingrid Bergman");
	cout << "none left" << endl;
	myStore.doAction("B 0001 D C 8 1942 Ingrid Bergman");


	


	system("pause");
}
