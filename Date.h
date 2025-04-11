#pragma once
#include <stdexcept>

class  Date
{
public:
	//big 4
	Date();
	Date(int day, int month, int year);
	Date(const Date& other) = default;
	Date& operator=(const Date& other) = default;
	~Date() = default;

	//getters
	inline unsigned int getDay()const {
		return this->day;
	}

	inline unsigned int getMonth()const {
		return this->month;
	}

	inline unsigned int getYear()const {
		return this->year;
	}

	//setters -> nqma da napravim a shte napravim edin cqlosten, tui kato trqbva datata da e valid
	void setDate(int, int, int);


	//methods
	void print()const;
	const char* dayOfWeek()const;
	int differenceBetweenDates(const Date& other)const;
	bool operator==(const Date& other) const;

	//mutators - promenqt obekta
	void addDays(int days);

	long long getTotalDays()const;
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
	bool validateDay(int, int);
};

