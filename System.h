#pragma once
#include "Person.h"
#include "Car.h"
/*
Реализирайте система (като клас), която поддържа множество коли и множество хора. Трябва да можете да генерирате различни справки,
като:
колко хора са собственици на повече от една кола
кои коли са собственост на даден човек
кои хора имат определен брой коли (0, 1, 2 и т.н.) Също да можете да прехвърлите кола към нов собственик (продажба).
На този етап не се изисква добавяне или премахване на коли и хора в системата след създаването ѝ.
*/

class System
{
public:
	System() = delete; // iskam da e izrichno pokazano che ne go iskame
	System(int peopleCount, int carsCount);
	System(const System& other) = delete; // ne bixme iskali da kopirame cqlata sistema, no bixme mogli ako trqbva da se dobavi
	System& operator=(const System& other) = delete;
	~System();

	//spravkite 
	int numberOfCarsWithNoOwners()const;
	int numberOfPeopleWhoAreOwnersOfMoreThanCar()const;
	void printCarsOfPerson(const Person* person)const;
	void printPeopleWithCarAmount(int carCount)const;
	void transferCarOwnerShip(int carIndex, Person* newOwner);

	void print()const;

private:
	Person** people;
	Car** cars;
	size_t peopleCount;
	size_t carsCount;

};

