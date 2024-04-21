#include <iostream>
#include <fstream>
using namespace std;
//Дан файл f, компоненты которого являются целыми числами. Найти
//количество чётных чисел среди компонент.
int main() {
    setlocale(LC_ALL, "russian");
	ifstream f;
	f.open("numbers.txt");
	int number;
	int two_ncount = 0;
    while (f >> number) {
        if (number % 2 == 0) {
            two_ncount++;
        }
    }

    // Закрываем файл
    f.close();

    // Выводим результат
    cout << "Количество четных чисел в файле: " << two_ncount << std::endl;

    ofstream res;
    res.open("res.txt");
    res << two_ncount;
    res.close();

}