#include <iostream>
#include <fstream>

int main() {
    // Открываем входной файл
    std::ifstream in("input1.txt");
    if (!in) {
        std::cerr << "Error: Cannot open input file!" << std::endl;
        return 1;
    }

    // Создаем/очищаем выходной файл
    std::ofstream out("output1.txt");
    if (!out) {
        std::cerr << "Error: Cannot create output file!" << std::endl;
        return 1;
    }
    out.close();  // Закрываем для последующего открытия в режиме дополнения

    // Первый проход: копируем значения x в выходной файл
    out.open("output1.txt", std::ios::app);
    double x;
    while (in >> x) {
        out << x << '\n';
    }
    out.close();
    
    // Сбрасываем позицию чтения в начало файла
    in.clear();
    in.seekg(0);

    // Второй проход: вычисляем f(x) и дописываем результаты
    out.open("output1.txt", std::ios::app);
    while (in >> x) {
        double fx = x * (x + 1);  // Функция по условию
        out << fx << '\n';
    }

    // Закрываем файлы
    in.close();
    out.close();

    std::cout << "File processing completed successfully!" << std::endl;
    return 0;
}