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
	void checkMatrix()
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
				cout << matrix1[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}

	void raiseToAPower(int power)
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				matrix1[i][j] = pow(matrix1[i][j], power);
			}
		}
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
	double** matrix1;
	int SIZE;
};



int main()
{
	setlocale(LC_ALL, "rus");
	MatrixCalculator m(3);
	m.AddMatrix();
	m.checkMatrix();
	m.raiseToAPower(2);

	m.checkMatrix();

	return 0;
}



MatrixCalculator::MatrixCalculator(int const SIZE)
{
	this->SIZE = SIZE;
	matrix1 = new double* [SIZE];
	for (int i = 0; i < SIZE; i++)
		matrix1[i] = new double [SIZE];
}

MatrixCalculator::~MatrixCalculator()
{	
	for (int i = 0; i < SIZE; i++)
		delete[] matrix1[i];
	delete[] matrix1;
}
