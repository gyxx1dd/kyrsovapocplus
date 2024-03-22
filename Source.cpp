#include "Catalog.h"


int main()
{
	setlocale(LC_ALL, "Ukr");
	Catalog catalog;
	File ahg("Filename", 17, Data(24, 8, 2023), Time(16, 14, 12), "public");
	cout << ahg << endl;
	ofstream outputFile("output.txt");
	if (outputFile.is_open()) {
		outputFile << ahg << endl;

		outputFile.close();

		cout << "Дані успішно записані у файл 'output.txt'" << endl;
	}
	else {
		cout << "Помилка відкриття файлу для запису" << endl;
	}
	cout << endl;
	int number = 0;
	cout << "Input number for print some info: " << endl;
	cout << "1.Print data" << endl;
	cout << "2.Print time" << endl;
	cout << "3.Print attributes" << endl;
	cin >> number;
	ahg.myswitch(number);
	catalog.addFile(ahg);
	string name;
	cout << "----------------------" << endl;
	cout << "Input name" << endl;
	cin >> name;
	catalog.showFiles(name);
	catalog.createAndAddFile();

	return 0;
}