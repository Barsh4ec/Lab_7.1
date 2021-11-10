#include <iostream>
#include <cmath>
#include <time.h>
#include <Windows.h>
#include <iomanip>

using namespace std;

void Create(int** Z, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			Z[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** Z, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << Z[i][j];
		cout << endl;
	}
	cout << endl;
}

void Change(int** Z, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = Z[row1][j];
		Z[row1][j] = Z[row2][j];
		Z[row2][j] = tmp;
	}
}

void Sort(int** Z, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((Z[i1][0] > Z[i1 + 1][0])
				||
				(Z[i1][0] == Z[i1 + 1][0] &&
					Z[i1][1] > Z[i1 + 1][1])
				||
				(Z[i1][0] == Z[i1 + 1][0] &&
					Z[i1][1] == Z[i1 + 1][1] &&
					Z[i1][2] < Z[i1 + 1][2]))
				Change(Z, i1, i1 + 1, colCount);
}

int Kilk(int** Z, const int rowCount, const int colCount)
{
	int k = 0;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			if (!(Z[i][j] > 0 && i || j % 2 != 0))
				k++;
	}
	return k;
}

int Sum(int** Z, const int rowCount, const int colCount)
{
	int s = 0;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			if (!(Z[i][j] > 0 && i || j % 2 != 0))
				s += Z[i][j];
	}
	return s;
}

void Zamina(int** Z, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			if (!(Z[i][j] > 0 && i || j % 2 != 0))
				Z[i][j] = 0;
	}
}
	

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));
	int Low = -41;
	int High = 23;

	int rowCount = 7;
	int colCount = 9;

	int** Z = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		Z[i] = new int[colCount];
	Create(Z, rowCount, colCount, Low, High);
	cout << "Z[" << rowCount << "][" << colCount << "] =" << endl;
	Print(Z, rowCount, colCount);

	Sort(Z, rowCount, colCount);
	cout << "ѕосортована матриц€ Z[" << rowCount << "][" << colCount << "] =" << endl;
	Print(Z, rowCount, colCount);

	cout << " ≥льк≥сть елемент≥в, €к≥ задов≥льн€бть вказаному критер≥ю = " << Kilk(Z, rowCount, colCount) << endl;
	cout << "—ума елемент≥в, €к≥ задов≥льн€бть вказаному критер≥ю = " << Sum(Z, rowCount, colCount) << endl;
	cout << "Z[" << rowCount << "][" << colCount << "] =" << endl;
	Zamina(Z, rowCount, colCount);
	Print(Z, rowCount, colCount);

	return 0;
}