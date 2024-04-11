#include"Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	int SIZE;
	cout << "¬ведите размер матрицы" << endl; cin >> SIZE;

	MatrixCalculator m(SIZE);
	MatrixCalculator m1(SIZE);
	MatrixCalculator m3(SIZE);
	m.AddMatrix();
	m1.AddMatrix();
	m3.AddMatrix();


	m = m1 * m3;
	
	m.checkMatrix();

	return 0;
}



