#include"Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	int SIZE;
	cout << "Введите размер матрицы" << endl; cin >> SIZE;

	MatrixCalculator m(SIZE);
	MatrixCalculator m1(SIZE);
	MatrixCalculator m3(SIZE);


	m = m1 * m3;
	
	m.checkMatrix();

	return 0;
}



