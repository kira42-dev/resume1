#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    double x;
    while (fin >> x) {
        double fx = 1/(x*x-x+1);
        fout << x << " " << fx << "\n";
    }
    return 0;
}