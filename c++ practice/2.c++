#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");
    fout << std::fixed << std::setprecision(4);
    double x;
    while (fin >> x) {
        double fx = x * (x + 1);
        fout << std::setw(7) << x << " " << std::setw(7) << fx << "\n";
    }
    return 0;
}