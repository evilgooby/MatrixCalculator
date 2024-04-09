#include"Header.h"

int main()
{
	int SIZE;
	cout << "¬ведите размер матрицы" << endl; cin >> SIZE;

	setlocale(LC_ALL, "rus");
	MatrixCalculator m(SIZE);
	MatrixCalculator m1(SIZE);
	MatrixCalculator m3(SIZE);
	m.AddMatrix();
	m1.AddMatrix();
	
	m.checkMatrix();

	return 0;
}



