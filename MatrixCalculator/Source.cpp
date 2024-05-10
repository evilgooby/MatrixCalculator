#include"Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	int SIZE;
	cout << "Введите размер матрицы" << endl; cin >> SIZE;

	MatrixCalculator m(SIZE);
	MatrixCalculator m1(SIZE);
    m1 = move(m);
    std::cout<< m.getSIZE(m) << " " << m1.getSIZE(m1);
    m.checkMatrix();
	//m1.checkMatrix();

	return 0;
}



