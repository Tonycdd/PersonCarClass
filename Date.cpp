#include "Date.h"
#include <ctime> // tm
#include <iostream> // cout cin
#include <stdexcept> // throw 


const int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1900;

}

Date::Date(int day, int month, int year)
	:Date()
{
	// nqma da reshavam problemut s visokosnite godini, no kato budeshtoo podobrenie e otvorena vuzmojnost
	//trqbva da validirame mesecut sprqmo datite
	if (day < 0 || !validateDay(day, month)) {
		throw std::invalid_argument("Invalid day!");
	}
	else if (month < 0 || month > 12)
	{
		throw std::invalid_argument("Invalid month!");
	}
	else if (year < 1900) {
		throw std::invalid_argument("Invalid date!");
	}

	//inache datite sa ok sprqmo mesecite

	//UMISHLENO NE POZLVAM setDate, iskame malko poveche inforamciq ot prosto invalid arguments, moje i da nqma mnogo smisul
	this->day = day;
	this->month = month;
	this->year = year;
}

void Date::setDate(int day, int month, int year) {
	//imame veche validna data
	if (day < 0 || !validateDay(day, month) || year < 1900) {
		throw std::invalid_argument("Invalid arguments!");
	}
	//vsichko e ok i go setvame?
	this->day = day;
	this->month = month;
	this->year = year;
}

void Date::print() const
{
	std::cout << "Date\n";
	std::cout << (this->day < 10 ? "0" : "") << this->day << "\\" << (this->month < 10 ? "0" : "") << this->month << "\\" << this->year << "\n";
}

const char* Date::dayOfWeek() const
{
	//  !tozi algoritum go vidqx ot internet!
	tm time = {};
	time.tm_year = this->year - 1900;
	time.tm_mon = this->month - 1;
	time.tm_mday = this->day;

	mktime(&time);
	const char* days[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	return days[time.tm_wday];
}

int Date::differenceBetweenDates(const Date& other) const
{
	int totalDaysCurrent = this->getTotalDays();
	int totalDaysOther = other.getTotalDays();

	int final = totalDaysCurrent - totalDaysOther;
	return final;

}

bool Date::operator==(const Date& other) const
{
	// ako sa ravni -> vrushta 0
	// <0 ako purvata e po-malka ot vtorata
	// >0 inache

	if (this->year != other.year)\
	{
		return this->year - other.year;
	}
	else if (this->month != other.month) {
		return this->month - other.month;
	}
	else if (this->day != other.day) {
		return this->day - other.day;
	}
	return 0;
}

void Date::addDays(int day)
{
	//days could be negative ones?
	// kakvo pravim ako sme purvi mesec, izvadim poveche ot kolkoto imame dni i trqbva da smenim i dni i godini i meseci?
	// analogichno pri dobavqneto

	// DISCLAIMER:
	// tova ne e osnovnata ni cel i moje bi ne trqbva da se spravqme s tozi problem, zatova shte se koncentrirame vurxu drugoto

	// shte priemame samo dni koito ne ni izkarvat ot meseca

	std::cout << "\nDISCLAIMER, WE TAKE ONLY DAYS WHICH DONT CHANGE OUR MOTHNS NOR OUR YAERS! \n";
	switch (this->month)
	{
	case 1:
		if (this->day + day > 31 || this->day + day < 1) {
			throw std::invalid_argument("THIS CHANGES MONTHS OR YEARS!");
		}
		this->day += day;
		break;
	case 2:
		if (this->day + day > 28 || this->day + day < 1) {
			throw std::invalid_argument("THIS CHANGES MONTHS OR YEARS!");
		}
		this->day += day;
		break;
	case 3:
		if (this->day + day > 31 || this->day + day < 1) {
			throw std::invalid_argument("THIS CHANGES MONTHS OR YEARS!");
		}
		this->day += day;
		break;
	case 4:
		if (this->day + day > 30 || this->day + day < 1) {
			throw std::invalid_argument("THIS CHANGES MONTHS OR YEARS!");
		}
		this->day += day;
		break;
	case 5:
		if (this->day + day > 31 || this->day + day < 1) {
			throw std::invalid_argument("THIS CHANGES MONTHS OR YEARS!");
		}
		this->day += day;
		break;
	case 6:
		if (this->day + day > 30 || this->day + day < 1) {
			throw std::invalid_argument("THIS CHANGES MONTHS OR YEARS!");
		}
		this->day += day;
		break;
	case 7:
		if (this->day + day > 31 || this->day + day < 1) {
			throw std::invalid_argument("THIS CHANGES MONTHS OR YEARS!");
		}
		this->day += day;
		break;
	case 8:
		if (this->day + day > 31 || this->day + day < 1) {
			throw std::invalid_argument("THIS CHANGES MONTHS OR YEARS!");
		}
		this->day += day;
		break;
	case 9:
		if (this->day + day > 30 || this->day + day < 1) {
			throw std::invalid_argument("THIS CHANGES MONTHS OR YEARS!");
		}
		this->day += day;
	case 10:
		if (this->day + day > 31 || this->day + day < 1) {
			throw std::invalid_argument("THIS CHANGES MONTHS OR YEARS!");
		}
		this->day += day;
		break;
	case 11:
		if (this->day + day > 30 || this->day + day < 1) {
			throw std::invalid_argument("THIS CHANGES MONTHS OR YEARS!");
		}
		this->day += day;
		break;
	case 12:
		if (this->day + day > 31 || this->day + day < 1) {
			throw std::invalid_argument("THIS CHANGES MONTHS OR YEARS!");
		}
		this->day += day;
		break;
	default:
		break;
	}
}

bool Date::validateDay(int day, int month) {
	switch (month)
	{
	case 1:
		return day <= 31;
	case 2:
		return day <= 28;
	case 3:
		return day <= 31;
	case 4:
		return day <= 30;
	case 5:
		return day <= 31;
	case 6:
		return day <= 30;
	case 7:
		return day <= 31;
	case 8:
		return day <= 31;
	case 9:
		return day <= 30;
	case 10:
		return day <= 31;
	case 11:
		return day <= 30;
	case 12:
		return day <= 31;
	default:
		return false;
	}
}

long long Date::getTotalDays() const
{
	int days = this->day;

	//dobavqme mesecite
	for (int i = 0; i < this->month - 1; i++)
	{
		// :: okazva globalen skope
		days += ::days[i];
	}


	// dobavqme ot godinite 
	//ne smqtame visokosni godini- taka se razbraxme - 1 godina 365 dni
	days += this->year * 365;
	return days;
}
