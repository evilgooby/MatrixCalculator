#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

class MatrixCalculator
{
public:
	MatrixCalculator(int const SIZE);
	~MatrixCalculator();

	void AddMatrix(); // заполнение матрицы
	const void checkMatrix(); // чтение матрицы matrix1
	const void checkMatrix(double** tempMatrix); // чтение матрицы которую передадим в качестве аргумента
	void determinant(); // вызов функции вычисления определителя
	void obratnaya(); // нахождение обратной матрицы matrix1
	double** transpone(); // транспонирование matrix1
	void raiseToAPower(int power); // возведение матрицы в степень 
	void Multiply(int num); // умножение матрицы

	MatrixCalculator operator*=(const MatrixCalculator& matrix);
	MatrixCalculator operator+=(const MatrixCalculator& matrix);
	MatrixCalculator operator+(const MatrixCalculator& matrix);
	MatrixCalculator operator*(const MatrixCalculator& matrix);
	MatrixCalculator& operator =(const MatrixCalculator& matrix);
	MatrixCalculator operator-=(const MatrixCalculator& matrix); 	
	MatrixCalculator operator-(const MatrixCalculator& matrix);

private:
	void clearMemory(double** a, int n); //Функция освобождения памяти, выделенной под двумерный динамический массив
	double** copyMatrix(double** tempMatrix); // перемещение данных из временной матрицы в основную
	double** GetMatr(double** mas, int rows, int cols, int row, int col);	// Получение матрицы без i-й строки и j-го столбца
	int findDet(double** mas, int n); //Рекурсивная функция вычисления определителя матрицы
	double** Mreverse(double** mas, int m); // нахождение обратной
	double** transpone(double** mas, int m); // транспонирование из функции 

	double** matrix1;
	int SIZE;
};
