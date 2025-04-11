#include "System.h"
#include <iostream>

const int MAX_SIZE_BUFFER = 128;

System::System(int peopleCount, int carsCount)
{
	// mnogo tup variant, no tova izmislix za da moje da mi raboti cheteneto
	int counter = 0;

	if (peopleCount < 0 || carsCount < 0) {
		throw std::invalid_argument("Invalid initial size for people and cars!");
	}
	this->people = new(std::nothrow) Person*[peopleCount];
	if (!this->people) {
		throw std::bad_alloc();
	}
	//inache e uspqlo
	this->cars = new(std::nothrow) Car * [carsCount];
	if (!this->cars) {
		throw std::bad_alloc();
	}
	//inache e uspqlo
	this->peopleCount = peopleCount;
	this->carsCount = carsCount;

	//mojeshe da se izvede vuv funkciq
	//sega trqbva da se suzdade vseki ot personite i kolite
	
	for (size_t i = 0; i < peopleCount; i++)
	{
		char* name1 = new(std::nothrow) char[MAX_SIZE_BUFFER];
		char* name2 = new(std::nothrow) char[MAX_SIZE_BUFFER];
		char* name3 = new(std::nothrow) char[MAX_SIZE_BUFFER];

		if (!name1 || !name2 || !name3) {
			delete[]name1;
			delete[]name2;
			delete[]name3;
			throw std::bad_alloc();
		}

		int day, month, year;
		int isMale;

		std::cout << "Initializing person number: " << i << "\n";

		std::cin.clear();
		if (counter > 0) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << "Enter name: ";
		std::cin.getline(name1, MAX_SIZE_BUFFER, '\n');
		
		std::cout << "Enter middle name: ";

		std::cin.getline(name2, MAX_SIZE_BUFFER, '\n');
		std::cout << "Enter last name: ";

		std::cin.getline(name3, MAX_SIZE_BUFFER, '\n');
		std::cout << "Enter birth day: ";
		std::cin >> day;

		std::cout << "Enter birth month: ";
		std::cin >> month;

		std::cout << "Enter birth year: ";
		std::cin >> year;

		std::cout << "Enter your gender(1 for Male, 0 for Girl): ";
		std::cin >> isMale;


		std::cin.clear();
		//tuk ne se grijim za greshka,ako ima greshka ima nqkolko podxoda:
		// da produljim s inicializaciq na ostanalite
		// da sprem izpulnenieto na systemata - izbirame tova
		this->people[i] = new Person(name1, name2, name3, day, month, year, isMale);
		// za izchistvane na bufera sled kato sme pisali chisla v nego
		counter++;
		std::cout << "\n";
		delete[]name1;
		delete[]name2;
		delete[]name3;
	}
	
	counter = 0;
	std::cin.ignore();
	//mojeshe da se izvede vuv funkciq
	for (size_t i = 0; i < carsCount; i++)
	{
		char* model = new(std::nothrow) char[MAX_SIZE_BUFFER];
		char* brand = new(std::nothrow) char[MAX_SIZE_BUFFER];

		Person* owenr = nullptr;

		if (!brand|| !model) 
		{
			delete[] model;
			delete[] brand;
			throw std::bad_alloc();
		}
		std::cout << "Initializing car number: " << i << "\n";
		
		if (counter > 0) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cin.ignore();
		std::cout << "Enter brand: ";

		std::cin.getline(brand, MAX_SIZE_BUFFER,'\n');
		std::cout << "Enter model: ";
		std::cin.getline(model, MAX_SIZE_BUFFER);

		int day, month, year;
		std::cout << "Enter day: ";
		std::cin >> day;
		std::cout << "Enter month: ";
		std::cin >> month;
		std::cout << "Enter year: ";
		std::cin >> year;

		unsigned char red, green, blue;
		std::cout << "Enter red value (0-255): ";
		std::cin >> red;
	
		std::cout << "Enter green value (0-255): ";
		std::cin >> green;

		std::cout << "Enter blue value (0-255): ";
		std::cin >> blue;

		//dali ima svoi owner
		char setOwner;
		std::cout << "Do you want to assign an owner to this car? (y/n): ";
		std::cin >> setOwner;
		if (setOwner == 'y' || setOwner == 'Y') {
			
			int ownerIndex;
			std::cout << "Enter the index of the owner (0 to " << this->peopleCount - 1 << "): ";
			std::cin >> ownerIndex;

			//dali e validen
			if (ownerIndex >= 0 && ownerIndex < peopleCount) {
				owenr = people[ownerIndex];  // zadavame go kato sobstvenik
			}
			else {
				std::cout << "Invalid owner index! The car will have no owner.\n";
			}
		}


		std::cin.clear();

		cars[i] = new Car(brand,model,day,month,year,red,blue,green,owenr);
		counter++;
		std::cout << "\n";
		
		delete[]model;
		delete[]brand;
		
	}
}

System::~System()
{
	for (int i = 0; i < peopleCount; ++i) {
		delete people[i];
	}
	delete[] people;

	for (int i = 0; i < carsCount; ++i) {
		delete cars[i];
	}
	delete[] cars;;
}

int System::numberOfCarsWithNoOwners() const
{
	int n = 0;
	for (size_t i = 0; i < carsCount; i++)
	{
		if (cars[i]->getOwner() == nullptr) {
			n++;
		}
	}
	return n;
}

int System::numberOfPeopleWhoAreOwnersOfMoreThanCar() const
{
	int n = 0;
	for (size_t i = 0; i < peopleCount; i++)
	{
		int carCount = 0;
		for (size_t j = 0; j < carsCount; j++)
		{
			if (cars[j]->getOwner() == people[i]) {
				carCount++;
			}
			
		}
		if (carCount > 1) {
			n++;
		}
	}
	return n;
}


void System::printCarsOfPerson(const Person* person) const
{
	for (size_t i = 0; i < carsCount; i++)
	{
		if (cars[i]->getOwner() == person) {
			cars[i]->print();
		}
	}
}

void System::printPeopleWithCarAmount(int carCount) const
{
	if (carCount < 0) {
		return;
	}
	//inache e pone 1
	for (size_t i = 0; i < peopleCount ; i++)
	{
		int count = 0;
		for (size_t j = 0; j < carCount; j++)
		{
			if (cars[j]->getOwner() == people[i]) {
				count++;
			}
		}
		if (count == carCount) {
			people[i]->print();
		}
	}
}

void System::transferCarOwnerShip(int carIndex, Person* newOwner)
{
	if (carIndex < 0 || carIndex > carsCount) {
		return;
	}
	else if (newOwner == nullptr) {
		std::cerr << "New owner is nullptr?!?\n";
		return;
	}
	//inache sa validni
	cars[carIndex]->changeOwner(newOwner);
}

void System::print()const {
	for (size_t i = 0; i < peopleCount; i++)
	{
		people[i]->print();
	}

	for (size_t i = 0; i < carsCount; i++)
	{
		cars[i]->print();
	}
}