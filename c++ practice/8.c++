#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  ifstream file("C:/Users/olesy/Desktop/diag.txt");

  if (!file) {
    cout << "File error!";
    return 1;
  }

  int n; file >> n;

  int** matr = new int*[n];

  for (int i = 0; i < n; i++) {
    matr[i] = new int[n];
    for (int j = 0; j < n; j++)
      file >> matr[i][j];
  }
  file.close();

  //контрольный вывод
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout.width(3); cout << matr[i][j];
    }
    cout << endl;
  }
  
  //количество положительных элементов на главной диагонали
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (matr[i][i] > 0)
      sum++;
  }
  cout << endl << "Kolvo + elem on main diag: " << sum << endl;

  //делится ли мин элемент побочной диагонали на 7
  int min = matr[0][n-1];
  for (int i = 0; i < n - 1 - i; i++) {
    if (matr[i][n - i - 1] <= min)
    min = matr[i][n - i - 1];
  }
  cout << "Min elem poboch diag " << min;
  if (min % 7 == 0) cout << " delitsa na 7\n";
  else cout << " ne delitsa 7\n";

  //вывести на экран номера строк, в которых произведение элементов, стоящих на главной и на побочной диагоналях, отрицательное число
  for (int i = 0; i < n; i++) {
    if (matr[i][i] * matr[i][n - i - 1] < 0)
      cout << endl << i;
  }

  delete[] matr;

  return 0;
}