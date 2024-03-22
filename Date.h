#pragma once
#include "BaseInfo.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
class Data :public BaseInfo
{
private:
	int day;
	int month;
	int year;
	bool active;

public:

	Data()
	{
		day = 0;
		month = 0;
		year = 0;
	}

	Data(int day, int month, int year)
	{
		if (ValidIsDate(day, month, year))
		{
			this->day = day;
			this->month = month;
			this->year = year;
		}
		else
		{
			cout << "ERROR FORMAT OF DATA" << endl;
			exit(0);
		}
	}

	void ShowInfo() override
	{
		cout << setfill('0') << setw(2) << day << "/" << setw(2) << month << "/" << year;
	}

	Data& operator+=(const Data& other) {
		day += other.day;
		month += other.month;
		year += other.year;
		return *this;
	}

	Data& operator=(const Data& other) {
		if (this != &other) {
			day = other.day;
			month = other.month;
			year = other.year;
		}
		return *this;
	}

	friend istream& operator>>(istream& input, Data& data) {
		cout << "Enter day: ";
		input >> data.day;

		cout << "Enter month: ";
		input >> data.month;

		cout << "Enter year: ";
		input >> data.year;

		return input;
	}

	bool ValidIsDate(int day, int month, int year)
	{
		int day1 = 31;
		int month1 = 12;
		int year1 = 2024;

		for (int i = 1; i <= day1; i++)
		{
			if (day == i)
			{
				day = i;
				break;
			}
			else if (i == day1)
			{
				return false;
			}
		}
		for (int i = 1; i <= month1; i++)
		{
			if (month == i)
			{
				month = i;
				break;
			}
			else if (i == month1)
			{
				return false;
			}
		}
		for (int i = 0; i <= year1; i++)
		{
			if (year == i)
			{
				year = i;
				break;
			}
			else if (i == year1)
			{
				return false;
			}
		}
	}

	Data& operator-=(const Data& other) {
		day -= other.day;
		month -= other.month;
		year -= other.year;
		return *this;
	}




	friend ostream& operator<<(ostream& output, const Data& data) {
		output << setfill('0') << setw(2) << data.day << "/" << setw(2) << data.month << "/" << data.year;
		return output;
	}

	void GetInfoData() const
	{
		cout << "Informathion about day: " << day << "." << month << "." << year << endl;
	}

	int& SetData(int a, int b, int c)
	{
		return day = a, month = b, year = c;
	}

};