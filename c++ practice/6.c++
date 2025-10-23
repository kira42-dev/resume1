#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("mas.txt");
    int n;
    in >> n;
    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            in >> matrix[i][j];
        }
    }
    in.close();

    // Задача a: Количество положительных элементов на главной диагонали
    int count_positive = 0;
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] > 0) {
            count_positive++;
        }
    }
    cout << count_positive << endl;

    // Задача b: Проверка делимости минимального элемента побочной диагонали на 7
    int min_side = matrix[0][n-1]; // Инициализация первым элементом
    for (int i = 1; i < n; i++) {
        if (matrix[i][n-1-i] < min_side) {
            min_side = matrix[i][n-1-i];
        }
    }
    if (min_side % 7 == 0) {
        cout << "да" << endl;
    } else {
        cout << "нет" << endl;
    }

    // Задача c: Строки с отрицательным произведением диагональных элементов
    for (int i = 0; i < n; i++) {
        int product = matrix[i][i] * matrix[i][n-1-i];
        if (product < 0) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}