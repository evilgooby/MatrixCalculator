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

	void AddMatrix(); // ���������� �������
	const void checkMatrix(); // ������ ������� matrix1
	const void checkMatrix(double** tempMatrix); // ������ ������� ������� ��������� � �������� ���������
	void determinant(); // ����� ������� ���������� ������������
	void obratnaya(); // ���������� �������� ������� matrix1
	double** transpone(); // ���������������� matrix1
	void raiseToAPower(int power); // ���������� ������� � ������� 
	void Multiply(int num); // ��������� �������

	MatrixCalculator operator*=(const MatrixCalculator& matrix);
	MatrixCalculator operator+=(const MatrixCalculator& matrix);
	MatrixCalculator operator+(const MatrixCalculator& matrix);
	MatrixCalculator operator*(const MatrixCalculator& matrix);
	MatrixCalculator& operator =(const MatrixCalculator& matrix);
	MatrixCalculator operator-=(const MatrixCalculator& matrix); 	
	MatrixCalculator operator-(const MatrixCalculator& matrix);

private:
	void clearMemory(double** a, int n); //������� ������������ ������, ���������� ��� ��������� ������������ ������
	double** copyMatrix(double** tempMatrix); // ����������� ������ �� ��������� ������� � ��������
	double** GetMatr(double** mas, int rows, int cols, int row, int col);	// ��������� ������� ��� i-� ������ � j-�� �������
	int findDet(double** mas, int n); //����������� ������� ���������� ������������ �������
	double** Mreverse(double** mas, int m); // ���������� ��������
	double** transpone(double** mas, int m); // ���������������� �� ������� 

	double** matrix1;
	int SIZE;
};
