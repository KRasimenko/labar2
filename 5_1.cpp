#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "russian");
	ifstream dudes;
	ofstream dudes2010("workers2010.txt");

	string name;
	string adress;
	string nationality;
	string birthday;
	string num_of_shop;
	string education;
	string year_of_starting;

	dudes.open("workers.txt");
	if (dudes.is_open()) {
		while (!dudes.eof()) {
			getline(dudes, name, ';');
			getline(dudes, adress, ';');
			getline(dudes, nationality, ';');
			getline(dudes, birthday, ';');
			getline(dudes, num_of_shop, ';');
			getline(dudes, education, ';');
			getline(dudes, year_of_starting, ';');

			cout << "Name: " << name << endl;
			cout << "Address: " << adress << endl;
			cout << "Nationality: " << nationality << endl;
			cout << "Birthday: " << birthday << endl;
			cout << "Number of shop: " << num_of_shop << endl;
			cout << "Education: " << education << endl;
			cout << "Year of starting: " << year_of_starting << endl;
			cout << endl;
			dudes.ignore();

			if (!year_of_starting.empty() && stoi(year_of_starting) > 2010) {
				// Записываем считанные данные в новый файл
				dudes2010 << "Name: " << name << endl;
				dudes2010 << "Address: " << adress << endl;
				dudes2010 << "Nationality: " << nationality << endl;
				dudes2010 << "Birthday: " << birthday << endl;
				dudes2010 << "Number of shop: " << num_of_shop << endl;
				dudes2010 << "Education: " << education << endl;
				dudes2010 << "Year of starting: " << year_of_starting << endl;
				dudes2010 << endl; // Добавляем пустую строку между записями
			}
			dudes.ignore();
		}
		dudes.close();
		dudes2010.close();
		cout << "Data has been written to output.txt" << endl;
	}
	else {
		cout << "error";
	}
	return 0;
}
