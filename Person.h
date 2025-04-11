#pragma once
#include "Date.h"
/*
дача 2.
Реализирайте класове, представящи Човек (Person) и Кола (Car).

Човекът трябва да има три имена (символни низове с произволна дължина),
дата на раждане (обект Date) и пол (изброен тип).
Нека датата на раждане и полът се задават при
конструиране и не могат повече да се променят (данните са const). 
Имената трябва да могат да се променят свободно, но да не са празни.
Подсигурете подходящи конструктори, деструктор и методи за достъп. Реализирайте метод за извеждане на
данните на екрана.
*/

namespace CLASSPERSON {
	enum Gender
	{
		MALE = 0,
		GIRL = 1,
	};
}

class Person
{
public:
	Person() = delete; // mojem i da ne go pokazvame taka, tui kato toi nqma da se suzdade inache, no predpochitam da se vidi
	// che ne iskam obekti ot tozi klas, koito da imat nqkakvi nevalidni stoinosti
	explicit Person(const char* name, const char* middleName, const char* lastName, int day, int month,int year, bool isMale);
	Person(const Person& other);
	Person& operator=(const Person& other) = delete; //imame const neshta, taka che takova neshto ne go pozvolqvame
	~Person();

	//getters
	inline const char* getFirstName()const {
		return this->firstName;
	}
	inline const char* getMiddleName()const {
		return this->middleName;
	}
	inline const char* getLastName()const {
		return this->lastName;
	}
	inline const Date& getBirthDate()const
	{
		return this->date;
	}
	inline const CLASSPERSON::Gender& getGender()const {
		return this->gender;
	}

	//setters
	void setFirstName(const char* name);
	void setMiddleName(const char* middleName);
	void setLastName(const char* lastName);

	//methods
	void print()const;
	const char* getGenderAsString() const;

private:
	char* firstName;
	char* middleName;
	char* lastName;
	const Date date;
	const CLASSPERSON::Gender gender;

	void init(const char* name, const char* middleName, const char* lastName);
};
