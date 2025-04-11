#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
#include <iostream>


Car::Car(const char* model, const char* brand, int day, int month, int year, unsigned char red, unsigned char blue, unsigned char green, Person* owner)
	:model(nullptr),brand(nullptr), date(day, month, year), color(createColor(red, blue, green)), person(owner)
{
	// ako nqkoe ne uspee celiqt ctor xvurlq greshka
	//imame nqkakvi nachalni stoinosti
	if (!model || !brand) {
		throw std::invalid_argument("Cannot be nullptr!");
	}
	//inache shte se opitame da gi setnem
	char* m = new(std::nothrow) char[strlen(model) + 1]; // dtor shte se pogriji
	char* b = new(std::nothrow)char[strlen(model) + 1]; // dtor se griji
	if (!m || !b) {
		delete[]m;
		delete[]b;
		throw std::bad_alloc();
	}
	//inache sa uspqli
	strcpy(m, model);
	strcpy(b, brand);
	//te se incializirat za purvi put, taka che sa nullptr i nqmame kakvo da im triem
	this->brand = b;
	this->model = m;
}

Car::~Car()
{
	delete[]this->brand;
	delete[]this->model;
	delete[]this->person;
}

void Car::print() const
{
	std::cout <<this->model << "\n";
	std::cout << this->brand << "\n";
	this->date.print();
	if (this->person != nullptr) {
		this->person->print();
	}
	std::cout << "RGB: R=" << (int)this->getRed() << " G=" << this->getGreen() << " B=" << this->getBlue() << "\n";
}

//newOner -> ne e const, koeto znachi che ne zapazva samiqt chovek
void Car::changeOwner(Person* newOwner)
{
	//moje i nullptr da e ne e problem
	this->person = newOwner;
}
