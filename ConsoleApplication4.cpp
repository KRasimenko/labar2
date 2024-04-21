#include <iostream>
#include <fstream>

using namespace std;

int main() {
	fstream Nega("a.txt");
	setlocale(LC_ALL, "Russian");
	int num;
	int count_negative = 0;
	int inx = 0;
	while (Nega >> num) {
		if ((inx % 2 == 0) && (num < 0)) {
			count_negative++;
		}
		inx++;
	}
	cout << "Количество отрицательных числе на четных позциях " << count_negative;
	Nega.close();
	return 0;
}