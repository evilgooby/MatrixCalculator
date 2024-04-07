#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

class MatrixCalculator
{
public:
	MatrixCalculator(int const SIZE);
	MatrixCalculator(int const SIZE, int const SIZE2);
	~MatrixCalculator();

	void AddMatrix()
	{
		cout << "Заполним матрицу числами" << endl;
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				cin >> matrix1[i][j];

	}
	const void checkMatrix()
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
				cout << matrix1[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}

	void clearMemory(int** a, int n) { //Функция освобождения памяти, выделенной под двумерный динамический массив
		for (int i = 0; i < n; i++) {
			delete[] a[i];
		}
		delete[] a;
	}

	void determinant()
	{
		cout << findDet(matrix1, SIZE) << endl;
	}

private: int findDet(int** a, int n) { //Рекурсивная функция вычисления определителя матрицы
	if (n == 1)
		return a[0][0];
	else if (n == 2)
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	else {
		int d = 0;
		for (int k = 0; k < n; k++) {
			int** m = new int* [n - 1];
			for (int i = 0; i < n - 1; i++) {
				m[i] = new int[n - 1];
			}
			for (int i = 1; i < n; i++) {
				int t = 0;
				for (int j = 0; j < n; j++) {
					if (j == k)
						continue;
					m[i - 1][t] = a[i][j];
					t++;
				}
			}
			d += pow(-1, k + 2) * a[0][k] * findDet(m, n - 1);
			clearMemory(m, n - 1); //Освобождаем память, выделенную под алгебраическое дополнение
		}
		return d; //Возвращаем определитель матрицы
	}
}
public:

	void raiseToAPower(int power)
	{
		int** tempMatrix;
		tempMatrix = new int* [SIZE];	// создаем временную матрицу и выделяем под неё память
		for (int i = 0; i < SIZE; i++)
			tempMatrix[i] = new int[SIZE];

		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				tempMatrix[i][j] = 0;

		for (int i = 0; i < SIZE; i++)
			for (int k = 0; k < SIZE; k++)
				for (int j = 0; j < SIZE; j++)
					tempMatrix[i][k] += matrix1[i][j] * matrix1[j][k];

		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				matrix1[i][j] = tempMatrix[i][j];

		clearMemory(tempMatrix, SIZE);
	}

	void Multiply(int num)
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				matrix1[i][j] *= num;
			}
		}
	}


private:

	int** matrix1;
	int SIZE;
};



int main()
{
	setlocale(LC_ALL, "rus");
	MatrixCalculator m(3);
	m.AddMatrix();

	m.determinant();

	m.checkMatrix();

	return 0;
}



MatrixCalculator::MatrixCalculator(int const SIZE)
{
	this->SIZE = SIZE;
	matrix1 = new int* [SIZE];
	for (int i = 0; i < SIZE; i++)
		matrix1[i] = new int[SIZE];
}

MatrixCalculator::~MatrixCalculator()
{	
	for (int i = 0; i < SIZE; i++)
		delete[] matrix1[i];
	delete[] matrix1;

}
