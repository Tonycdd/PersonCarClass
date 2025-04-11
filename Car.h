#pragma once
#include "Person.h"
/*
Колата има модел и марка, които са символни низове с произволна дължина, дата на производство (Date), цвят (unsigned int)
и собственик (Person). Модела, марката и датата на производство не могат да се променят (направете ги const), цветът винаги
е зададен и трябва да е в RGB формат (най-младшия байт на числото е стойност за синьо, вторият - за зелено, третият за червено;
най-старшият байт трябва да е винаги 0), а собственика е указател към Person, който може да е зададен, но може и да не е (nullptr),
когато няма такъв. За колата реализирайте подходящи конструктори и методи за достъп, също извеждане на екрана и смяна на собственик.
*/

class Car
{
public:
	// nqmame default ctor, tui kato ne biva da promenqme sled tova model,brand,date...
	Car() = delete;
	//color vinagi e zadaden, taka che shte priemame i za nego argumenti
	explicit Car(const char* model, const char* brand, int day,int month, int year, unsigned char red, unsigned char blue, unsigned char green, Person* owner = nullptr);
	Car(const Car& other) = delete; // imame const char*, nqma kak da napravim standartno kopirane, tui kato strcpy - > trqbva da svalim s const cast
	// constata za da raboti, taka che nqma da pozvolqvame kopirane
	Car& operator=(const Car& other) = delete;
	~Car();

	//getters
	inline const char* getModel()const {
		return this->model;
	}
	inline const char* getBrand()const {
		return this->brand;
	}
	inline const Date& getDate()const {
		return this->date;
	}
	inline const Person* getOwner()const
	{
		return this->person;
	}
	inline unsigned char getRed()const {
		return (this->color >> 16) & 0xFF;
	}
	inline unsigned char getGreen()const {
		return (this->color >> 8) & 0xFF;
	}
	inline unsigned char getBlue()const {
		return this->color & 0xFF;
	}

	//methods
	void print()const;
	void changeOwner(Person* newOwner);

private:
	const char* model;
	const char* brand;
	const Date date;

	unsigned int color;
	
	/*
	obqsnenie

	4*8 -> 32 baita

	(0 << 24) → nai-starshiqt e vinagi 0

	(red << 16) → 3 bait
	(green << 8) → 2 bait
	(blue) →nai-mladshi
	*/

	Person* person; // moje bi e po-dobre, tui kato kolata moje i da nqma sobstvenik - nullptr

	inline unsigned int createColor(unsigned char r, unsigned char g, unsigned char b) {
		return (0 << 24) | (r << 16) | (g << 8) | b; 
	}
};
