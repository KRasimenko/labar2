#include <iostream>
#include <fstream>
using namespace std;
int main() {
	ifstream file("1.txt");
	double numbers;
	int zero_count = 0;
	double product = 1;
	while (file >> numbers) {
		if (numbers == 0) {
			zero_count++;
		}
		if ((numbers > 0) && (numbers < 1)) {
			product = product * numbers;
		}
		
	}
	cout << "cout Zeros " << zero_count << endl;
	cout << "Second description " << product << endl;

}