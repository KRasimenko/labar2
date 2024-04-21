#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	fstream input_a1("a1.txt");
	fstream output_a2("a2.txt");

	char character;
	while (input_a1.get(character)) {
		if (!isdigit(character)) {
			output_a2 << character;
		}
	}
	input_a1.close();
	output_a2.close();
	return 0;
}
