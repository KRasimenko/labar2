#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{   
    setlocale(LC_ALL, "rus");
    // Путь к бинарному файлу
    const char* path = "input.bin";

    // Вектор для хранения данных из файла
    vector<char> data(37);

    // Вектор для хранения строк русского алфавита
    vector<string> strings;

    // Заполнение вектора строк русского алфавита
    for (int i = 0; i < 36; i++)
        strings.push_back(string(1, static_cast<char>(0x400 + (i * 2))));

    // Копирование первого символа каждой строки из вектора строк в вектор данных
    for (int i = 0; i < 36; i++)
        data[i] = strings[i][0];

    // Открытие бинарного файла для записи
    ofstream out(path, ios::binary);

    // Запись вектора данных в бинарный файл
    out.write(data.data(), data.size());

    // Закрытие бинарного файла
    out.close();

    // Вывод данных из вектора до изменения в бинарном файле
    for (int i = 0; i < 36; i++)
        cout << data[i];
    cout << endl;

    // Открытие бинарного файла для чтения
    ifstream in(path, ios::binary);

    // Считывание вектора данных из бинарного файла
    in.read(data.data(), data.size());

    // Закрытие бинарного файла
    in.close();

    // Замена символов '*' и '/' на '+' в векторе данных
    for (int i = 0; i < 36; i++)
        if (data[i] == '*' || data[i] == '/')
            data[i] = '+';

    // Открытие бинарного файла для записи
    out.open(path, ios::binary);

    // Запись измененного вектора данных в бинарный файл
    out.write(data.data(), data.size());

    // Закрытие бинарного файла
    out.close();

    // Вывод данных из вектора после изменения в бинарном файле
    for (int i = 0; i < 36; i++)
        cout << data[i];

    return 0;
}
