#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const int x = 6;
    int a[x][x];

    ifstream fin("mas.txt");
    if (!fin) {
        cerr << "Ошибка: не удалось открыть файл mas.txt\n";
        return 1;
    }

    // Чтение матрицы
    for (int i = 0; i < x; ++i) {
        for (int k = 0; k < x; ++k) {
            fin >> a[i][k];
        }
    }
    fin.close();

    // 1) Количество положительных на главной диагонали
    int posCount = 0;
    for (int i = 0; i < x; ++i) {
        if (a[i][i] > 0) {
            posCount++;
        }
    }

    // 2) Минимальный элемент на побочной диагонали
    int naimen = a[0][x - 1];
    for (int i = 1; i < x; ++i) {
        int v = a[i][x - 1 - i];
        if (v < naimen) {
            naimen = v;
        }
    }

    // 3) Вывод результатов
    cout << "Положительных на главной диагонали: " << posCount << "\n";
    cout << "Минимальный на побочной диагонали: " << naimen
         << ", делится на 7? ";
    if (naimen % 7 == 0) 
        cout << "Да\n";
    else 
        cout << "Нет\n";

    cout << "Строки с отрицательным произведением диагональных элементов: ";
    int first = 1;
    for (int i = 0; i < x; ++i) {
        int prod = a[i][i] * a[i][x - 1 - i];
        if (prod < 0) {
            if (!first) 
                cout << ", ";
            cout << (i + 1);
            first = 0;
        }
    }
    if (first) {
        // Если ни одна строка не подходит
        cout << "нет";
    }
    cout << "\n";

    return 0;
}