#pragma once
#include "Date.h"
class Time :public BaseInfo
{
private:
	int hours;
	int minute;
	int second;

public:
	Time()
	{
		hours = 0;
		minute = 0;
		second = 0;
	}

	Time(int hours, int minute, int second)
	{
		if (ValidIsTime(hours, minute, second))
		{
			this->hours = hours;
			this->minute = minute;
			this->second = second;
		}
		else
		{
			cout << "ERROR FORMAT OF TIME" << endl;
			exit(0);
		}
	}

	void ShowInfo() override
	{
		cout << setfill('0') << setw(2) << this->hours << ":" << setw(2) << this->minute << ":" << setw(2) << this->second;

	}

	Time& operator+=(const Time& other) {
		hours += other.hours;
		minute += other.minute;
		second += other.second;
		return *this;
	}

	Time& operator-=(const Time& other) {
		hours -= other.hours;
		minute -= other.minute;
		second -= other.second;
		return *this;
	}

	bool ValidIsTime(int hours, int minute, int second)
	{
		int hours1 = 24;
		int minute1 = 60;
		int second1 = 60;

		if (hours < 0 || hours >= hours1)
			return false;

		if (minute < 0 || minute >= minute1)
			return false;

		if (second < 0 || second >= second1)
			return false;

		return true;
	}

	friend ostream& operator<<(ostream& output, const Time& time) {
		output << setfill('0') << setw(2) << time.hours << ":" << setw(2) << time.minute << ":" << setw(2) << time.second;
		return output;
	}

	friend istream& operator>>(istream& input, Time& time) {
		cout << "Enter hours: ";
		input >> time.hours;

		cout << "Enter minute: ";
		input >> time.minute;

		cout << "Enter second: ";
		input >> time.second;

		return input;
	}

	Time& operator=(const Time& other) {
		if (this != &other) {
			hours = other.hours;
			minute = other.minute;
			second = other.second;
		}
		return *this;
	}




	void GetInfoTime() const
	{
		cout << "Hours: " << hours << " Minute: " << minute << " Second: " << second << endl;
	}

	int& SetTime(int a, int b, int c)
	{
		return hours = a, minute = b, second = c;
	}




};