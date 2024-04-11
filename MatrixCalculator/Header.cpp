#include"Header.h"

MatrixCalculator::MatrixCalculator(int const SIZE)
{
	this->SIZE = SIZE;
	matrix1 = new double* [SIZE];
	for (int i = 0; i < SIZE; i++)
		matrix1[i] = new double[SIZE];

	//for (int i = 0; i < SIZE; i++)
	//{
	//	for (int j = 0; j < SIZE; j++)
	//	{
	//		matrix1[i][j] = 0;
	//	}
	//}

	AddMatrix();
}

MatrixCalculator::~MatrixCalculator()
{
	for (int i = 0; i < SIZE; i++)
		delete[] matrix1[i];
	delete[] matrix1;
}

void MatrixCalculator::AddMatrix()
{
	cout << "�������� ������� �������" << endl;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			cin >> matrix1[i][j];
}

const void MatrixCalculator::checkMatrix()
{
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cout << matrix1[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

const void MatrixCalculator::checkMatrix(double** tempMatrix)
{
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cout << tempMatrix[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}

void MatrixCalculator::determinant()
{
	cout << findDet(matrix1, SIZE) << endl;
}

void MatrixCalculator::clearMemory(double** a, int n)
{
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
}

double** MatrixCalculator::copyMatrix(double** tempMatrix)
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matrix1[i][j] = tempMatrix[i][j];
	return matrix1;
}

double** MatrixCalculator::GetMatr(double** mas, int rows, int cols, int row, int col)
{
	int di, dj;
	double** p = new double* [rows];
	di = 0;
	for (int i = 0; i < rows - 1; i++) {
		if (i == row)
			di = 1;
		dj = 0;
		p[i] = new double[cols];
		for (int j = 0; j < cols - 1; j++) {
			if (j == col)
				dj = 1;
			p[i][j] = mas[i + di][j + dj];
		}
	}
	return p;
}

int MatrixCalculator::findDet(double** mas, int n)
{
	if (n < 0)
	{
		cout << "������������ ��������� ����������!";
		return 0;
	}
	else if (n == 1)
		return mas[0][0];
	else if (n == 2)
		return mas[0][0] * mas[1][1] - mas[0][1] * mas[1][0];
	else
	{
		int d = 0;
		for (int k = 0; k < n; k++)
		{
			double** m = new double* [n - 1];
			for (int i = 0; i < n - 1; i++)
			{
				m[i] = new double[n - 1];
			}
			for (int i = 1; i < n; i++)
			{
				int t = 0;
				for (int j = 0; j < n; j++)
				{
					if (j == k)
						continue;
					m[i - 1][t] = mas[i][j];
					t++;
				}
			}
			d += pow(-1, k + 2) * mas[0][k] * findDet(m, n - 1);
			clearMemory(m, n - 1);
		}
		return d;
	}
}

double** MatrixCalculator::Mreverse(double** mas, int m)
{
	double** tempMatrix = new double* [m];

	double det = findDet(mas, m);
	for (int i = 0; i < m; i++)
	{
		tempMatrix[i] = new double[m];
		for (int j = 0; j < m; j++)
		{
			tempMatrix[i][j] = findDet(GetMatr(mas, m, m, i, j), m - 1);
			if ((i + j) % 2 == 1)
				tempMatrix[i][j] = -tempMatrix[i][j];
			tempMatrix[i][j] = tempMatrix[i][j] / det;
		}
	}
	return transpone(tempMatrix, m);
}

void MatrixCalculator::obratnaya()
{
	Mreverse(matrix1, SIZE);
}

double** MatrixCalculator::transpone(double** mas, int m)
{
	double** tempMatrix = new double* [m];

	for (int i = 0; i < m; i++)
	{
		tempMatrix[i] = new double[m];
		for (int j = 0; j < m; j++)
		{
			tempMatrix[i][j] = mas[j][i];
		}
	}
	copyMatrix(tempMatrix);
	clearMemory(tempMatrix, m);
	return matrix1;
}

double** MatrixCalculator::transpone()
{
	double** tempMatrix;
	tempMatrix = new double* [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tempMatrix[i] = new double[SIZE];
		for (int j = 0; j < SIZE; j++)
			tempMatrix[i][j] = matrix1[j][i];
	}
	copyMatrix(tempMatrix);
	clearMemory(tempMatrix, SIZE);
	return matrix1;
}

void MatrixCalculator::raiseToAPower(int power)
{
	double** tempMatrix;

	tempMatrix = new double* [SIZE];
	for (int i = 0; i < SIZE; i++)
		tempMatrix[i] = new double[SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			tempMatrix[i][j] = 0;

	for (int i = 0; i < SIZE; i++)
		for (int k = 0; k < SIZE; k++)
			for (int j = 0; j < SIZE; j++)
				tempMatrix[i][k] += matrix1[i][j] * matrix1[j][k];
	copyMatrix(tempMatrix);
	clearMemory(tempMatrix, SIZE);
}

void MatrixCalculator::Multiply(int num)
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matrix1[i][j] *= num;
}

MatrixCalculator MatrixCalculator::operator*=(const MatrixCalculator& matrix)
{
	double** tempMatrix;

	tempMatrix = new double* [SIZE];
	for (int i = 0; i < SIZE; i++)
		tempMatrix[i] = new double[SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			tempMatrix[i][j] = 0;

	for (int i = 0; i < SIZE; i++)
		for (int k = 0; k < SIZE; k++)
			for (int j = 0; j < SIZE; j++)
				tempMatrix[i][k] += matrix1[i][j] * matrix.matrix1[j][k];
	
	copyMatrix(tempMatrix);
	clearMemory(tempMatrix, SIZE);
	return *this;
}

MatrixCalculator MatrixCalculator::operator+=(const MatrixCalculator& matrix)
{
	double** tempMatrix;

	tempMatrix = new double* [SIZE];
	for (int i = 0; i < SIZE; i++)
		tempMatrix[i] = new double[SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			tempMatrix[i][j] = 0;

	for (int i = 0; i < SIZE; i++)
		for (int k = 0; k < SIZE; k++)
			for (int j = 0; j < SIZE; j++)
				tempMatrix[i][k] += matrix1[i][j] + matrix.matrix1[j][k];

	copyMatrix(tempMatrix);
	clearMemory(tempMatrix, SIZE);
	return *this;
}

MatrixCalculator MatrixCalculator::operator+(const MatrixCalculator& matrix)
{
	double** tempMatrix;

	tempMatrix = new double* [SIZE];
	for (int i = 0; i < SIZE; i++)
		tempMatrix[i] = new double[SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			tempMatrix[i][j] = 0;

	for (int i = 0; i < SIZE; i++)
		for (int k = 0; k < SIZE; k++)
			for (int j = 0; j < SIZE; j++)
				tempMatrix[i][k] += matrix1[i][j] + matrix.matrix1[j][k];

	copyMatrix(tempMatrix);
	clearMemory(tempMatrix, SIZE);
	return *this;
}


MatrixCalculator MatrixCalculator::operator*(const MatrixCalculator& matrix)
{
	double** tempMatrix;
	tempMatrix = new double* [SIZE];
	for (int i = 0; i < SIZE; i++)
		tempMatrix[i] = new double[SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			tempMatrix[i][j] = 0;

	for (int i = 0; i < SIZE; i++)
		for (int k = 0; k < SIZE; k++)
			for (int j = 0; j < SIZE; j++)
				tempMatrix[i][k] += matrix1[i][j] * matrix.matrix1[j][k];

	copyMatrix(tempMatrix);
	clearMemory(tempMatrix, SIZE);
	return *this;
}

MatrixCalculator& MatrixCalculator::operator=(const MatrixCalculator& matrix)
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matrix1[i][j] = matrix.matrix1[i][j];
	return *this;
}

MatrixCalculator MatrixCalculator::operator-=(const MatrixCalculator& matrix)
{
	double** tempMatrix;

	tempMatrix = new double* [SIZE];
	for (int i = 0; i < SIZE; i++)
		tempMatrix[i] = new double[SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			tempMatrix[i][j] = 0;

	for (int i = 0; i < SIZE; i++)
		for (int k = 0; k < SIZE; k++)
			for (int j = 0; j < SIZE; j++)
				tempMatrix[i][k] += matrix1[i][j] - matrix.matrix1[j][k];

	copyMatrix(tempMatrix);
	clearMemory(tempMatrix, SIZE);
	return *this;
}

MatrixCalculator MatrixCalculator::operator-(const MatrixCalculator& matrix)
{
	double** tempMatrix;

	tempMatrix = new double* [SIZE];
	for (int i = 0; i < SIZE; i++)
		tempMatrix[i] = new double[SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			tempMatrix[i][j] = 0;

	for (int i = 0; i < SIZE; i++)
		for (int k = 0; k < SIZE; k++)
			for (int j = 0; j < SIZE; j++)
				tempMatrix[i][k] += matrix1[i][j] - matrix.matrix1[j][k];

	copyMatrix(tempMatrix);
	clearMemory(tempMatrix, SIZE);
	return *this;
}
