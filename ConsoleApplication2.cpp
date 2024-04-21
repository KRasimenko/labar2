#include <iostream>
#include <fstream>

using namespace std;

int main() {
	fstream input_a1("a1.txt");
	fstream output_a2("a2.txt");
	double number;
	while(input_a1 >> number) {
		if (number != 0) {
			output_a2 << number <<" ";
		}
	}
	input_a1.close();
	output_a2.close();
	return 0;
}