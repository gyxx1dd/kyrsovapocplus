#pragma once
#include "Time.h"
class File :public Time, public Data
{
private:
	string filename;
	int filesize;
	Data date;
	Time time;
	string attributes;



public:
	File()
	{

	}
	File(string name, int size, const Data& date1, const Time& time, string attributes)
	{
		this->filename = name;
		this->filesize = size;
		this->date = date1;
		this->time = time;
		this->attributes = attributes;
	}


	friend ostream& operator<<(ostream& os, const File& file) {
		os << "Name: " << file.filename << endl;
		os << "Size: " << file.filesize << " bytes" << endl;
		os << "Date Created: " << file.date << endl;
		os << "Time Created: " << file.time << endl;
		os << "Attributes: " << file.attributes << endl;
		return os;
	}

	File(const File& other)
		: filename(other.filename), filesize(other.filesize), date(other.date), time(other.time), attributes(other.attributes) {}

	File& operator=(const File& other) {
		if (this != &other) {
			filename = other.filename;
			filesize = other.filesize;
			date = other.date;
			time = other.time;
			attributes = other.attributes;
		}
		return *this;
	}

	int GetFilesize() const { return filesize; }
	string getName() const { return filename; }
	Data getData() const { return date; }
	Time getTime() const { return time; }

	void updateTime(int hours, int minutes, int seconds) {
		time += Time(hours, minutes, seconds);
	}

	void updateTime2(int hours, int minutes, int seconds) {
		time -= Time(hours, minutes, seconds);
	}



	void myswitch(int number)
	{
		switch (number)
		{
		case 1:
			date.ShowInfo();
			cout << endl;
			break;
		case 2:
			time.ShowInfo();
			cout << endl;
			break;
		case 3:
			cout << attributes << endl;
			break;
		default:
			cout << "error number" << endl;
		}
	}

};