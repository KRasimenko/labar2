#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL,"ru");
    // Создать бинарный файл с информацией о компьютерах
    ofstream fout("computers.bin", ios::binary);

    // Написать заголовок файла
    int num_computers = 5;
    fout.write((char*)&num_computers, sizeof(int));

    // Написать данные о компьютерах
    struct Computer {
        char name[50];
        double cpu;
        int ram;
        int hdd;
        int price;
    };

    Computer computers[] = {
        {"Asus X555MA", 2.4, 8, 512, 15000},
        {"Lenovo IdeaPad 320", 1.6, 4, 500, 10000},
        {"Acer Aspire E15", 2.2, 8, 1024, 18000},
        {"HP Pavilion 15", 1.8, 4, 512, 12000},
        {"Asus X507MA", 2.8, 8, 1024, 16000},
    };

    for (int i = 0; i < num_computers; i++) {
        fout.write((char*)&computers[i], sizeof(Computer));
    }

    fout.close();

    // Определить общую стоимость предложенных к продаже компьютеров, у которых частота процессора более 2 ГГц/сек фирмы «Asus»
    int total_cost = 0;
    ifstream fin("computers.bin", ios::binary);

    // Пропустить заголовок файла
    fin.seekg(4);

    // Прочитать данные о компьютерах
    for (int i = 0; i < num_computers; i++) {
        Computer computer;
        fin.read((char*)&computer, sizeof(Computer));

        // Проверить, соответствует ли компьютер заданным критериям
        if (computer.cpu > 2.0 && strncmp(computer.name, "Asus", 4) == 0) {
            total_cost += computer.price;
        }
    }

    fin.close();

    // Напечатать общую стоимость
    cout << "Общая стоимость: " << total_cost << endl;

    return 0;
}