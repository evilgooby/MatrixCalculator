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
    MatrixCalculator(const MatrixCalculator &matrix);   // конструктор копирования
    MatrixCalculator(MatrixCalculator &&matrix);        // конструктор перемещения
    void operator =(const MatrixCalculator& matrix);    // оператор присваивания
    void operator =(MatrixCalculator&& matrix);         // оператор перемещения
	~MatrixCalculator();                                // деструктор

    int getSIZE(const MatrixCalculator& matrix);
	void AddMatrix();                                   // Заполнение матрицы
	const void checkMatrix();                           // чтение матрицы matrix1
	void determinant();                                 // Нахождение определителя
	void obratnaya();                                   // нахождение обратной matrix1
	double** transpone();                               // транспонирование matrix1
	void raiseToAPower(int power);                      // возведение в степень
	void Multiply(int num);                             // умножение матрицы

	MatrixCalculator operator*=(const MatrixCalculator& matrix);
	MatrixCalculator operator+=(const MatrixCalculator& matrix);
	MatrixCalculator operator+(const MatrixCalculator& matrix);
	MatrixCalculator operator*(const MatrixCalculator& matrix);
	MatrixCalculator operator-=(const MatrixCalculator& matrix); 	
	MatrixCalculator operator-(const MatrixCalculator& matrix);

private:
	void clearMemory(double** a, int n);                //освобождаем память
	double** copyMatrix(double** tempMatrix);           // что то типо конструктора копирования
	double** GetMatr(double** mas, int rows, int cols, int row, int col);	// получение матрицы без i-й строки и j-го столбца
	int findDet(double** mas, int n);                   //рукурсивная функция вычисление определителя
	double** Mreverse(double** mas, int m);             // нахождение обратной
	double** transpone(double** mas, int m);            // транспонирование из функции
	const void checkMatrix(double** tempMatrix);
	double** matrix1;
	int SIZE;
};
