#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include <iostream>

Person::Person(const char* name, const char* middleName, const char* lastName, int day, int month, int year, bool isMale)
	:date(day, month, year), gender(isMale ? CLASSPERSON::Gender::MALE : CLASSPERSON::Gender::GIRL)
{
	//ako date ili gender xvurlqt greshka celiqt ctor shte go napravi i nie shte se pogrijim da q xvanem otvun
	this->init(name, middleName, lastName);
}

Person::Person(const Person& other)
	:date(other.date), gender(other.gender)
{
	//moje i init funciqta da si polzvame
	
	// other e validen obekt- nqma kak da ima nullptr
	char* newName = new(std::nothrow) char[strlen(other.firstName) + 1];
	char* newMiddle = new(std::nothrow) char[strlen(other.middleName) + 1];
	char* newLast = new(std::nothrow) char[strlen(other.lastName) + 1];
	if (!newName || !newMiddle || !newLast) {
		delete[]newName;
		delete[]newMiddle;
		delete[]newLast;
		throw std::bad_alloc();
	}
	//inache sa zadelenei
	strcpy(newName, other.firstName);
	strcpy(newMiddle, other.middleName);
	strcpy(newLast, other.lastName);

	delete[]this->firstName;
	delete[]this->middleName;
	delete[]this->lastName;

	this->firstName = newName;
	this->middleName = newMiddle;
	this->lastName = newLast;
}

Person::~Person()
{
	delete[]firstName;
	delete[]middleName;
	delete[]lastName;
	//date si e statichen obekt i toi shte se osvobodi, a dannite v nego se osvobojdavat ot dtor na Date clasa
}

void Person::setFirstName(const char* name)
{
	if (name == nullptr) {
		throw std::invalid_argument("You are trying to set nullptr on your first name!");
	}
	else if (name == this->firstName) {
		return;
	}
	else {
		//shte se opitame da go setnem
		char* newName = new(std::nothrow)char[strlen(name) + 1];
		if (newName) {
			//ako e uspqlo zadelqneto
			strcpy(newName, name);
			delete[] this->firstName;
			this->firstName = newName;
		}
		else {
			delete[]newName;
			throw std::bad_alloc();
		}
	}
}

void Person::setMiddleName(const char* middleName)
{
	if (middleName == nullptr) {
		throw std::invalid_argument("You are trying to set nullptr on your middle name!");
	}
	else if (middleName == this->middleName) {
		return;
	}
	else {
		//shte se opitame da go setnem
		char* newName = new(std::nothrow)char[strlen(middleName) + 1];
		if (newName) {
			//ako e uspqlo zadelqneto
			strcpy(newName, middleName);
			delete[] this->middleName;
			this->middleName = newName;
		}
		else {
			delete[]newName;
			throw std::bad_alloc();
		}
	}
}

void Person::setLastName(const char* lastName)
{
	if (lastName == nullptr) {
		throw std::invalid_argument("You are trying to set nullptr on your first name!");
	}
	else if (lastName == this->lastName) {
		return;
	}
	else {
		//shte se opitame da go setnem
		char* newName = new(std::nothrow)char[strlen(lastName) + 1];
		if (newName) {
			//ako e uspqlo zadelqneto
			strcpy(newName, lastName);
			delete[] this->lastName;
			this->lastName = newName;
		}
		else {
			delete[]newName;
			throw std::bad_alloc();
		}
	}
}

const char* Person::getGenderAsString()const
{
	
	switch (this->gender) {
	case CLASSPERSON::Gender::MALE:
		return "MALE";
	case CLASSPERSON::Gender::GIRL:
		return "GIRL";
	default: return "UNKNOWN";
	}
}

void Person::print() const
{
	std::cout << this->firstName << "\n";
	std::cout << this->middleName << "\n";
	std::cout << this->lastName << "\n";
	date.print();
	std::cout << this->getGenderAsString() << "\n";
}

void Person::init(const char* name, const char* middleName, const char* lastName)
{
	// ako nqkoe xvurli greshka init shte xvurli, toest i ctor shte xvurli -> no otvun shte bude prixvanata
	this->setFirstName(name);
	this->setMiddleName(middleName);
	this->setLastName(lastName);
}
