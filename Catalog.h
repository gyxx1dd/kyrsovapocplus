#pragma once
#include "File.h"
class Catalog
{
private:
	vector<File> search;
	File getin;

public:
	Catalog()
	{

	}

	void addFile(const File& file) {
		search.push_back(file);
	}

	void showFiles(string& mask) {
		for (auto& de : search) {
			if (de.getName().find(mask) != string::npos) {
				cout << "File: " << de.getName() << ", Size: " << de.GetFilesize() << " bytes" << " Data: " << de.getData() << " Time: " << de.getTime() << endl;

				int choice;
				cout << "�� ������ � �����? (1. �������� ������, 2. �������� ������): ";
				cin >> choice;

				switch (choice) {
				case 1: {
					int hoursToAdd;
					cout << "����� ��� ���������: ";
					cin >> hoursToAdd;
					de.updateTime(hoursToAdd, 0, 0);
					cout << "Updated time: " << de.getTime() << endl;
					break;
				}
				case 2: {
					int hoursToSubtract;
					cout << "����� ��� ���������: ";
					cin >> hoursToSubtract;
					de.updateTime2(hoursToSubtract, 0, 0);
					cout << "Updated time: " << de.getTime() << endl;
					break;
				}
				default:
					cout << "Invalid!" << endl;
				}
			}
			else {
				cout << "File not found" << endl;
			}
		}
	}
	void createAndAddFile() {
		string name;
		int size;
		int day, month, year;
		int hours, minutes, seconds;
		string attributes;
		cout << "��������� ������ �����" << endl;
		cout << "������ �����: ";
		cin >> name;

		cout << "������ ����� � ������: ";
		cin >> size;

		cout << "creation date (day month year): ";
		cin >> day >> month >> year;

		cout << "creation time (hours minutes seconds): ";
		cin >> hours >> minutes >> seconds;

		cout << "Enter file attributes: ";
		cin >> attributes;

		File newFile(name, size, Data(day, month, year), Time(hours, minutes, seconds), attributes);
		addFile(newFile);

		cout << "New file added successfully!" << endl;
		cout << "-----------" << endl;
		cout << newFile << endl;
	}





};