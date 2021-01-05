// Lab_06_4.cpp
// < ������� ������� >
// ����������� ������ � 6.4(1)
// ����������� ����������� ������ ����������� ������o�
// ������ 1

#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const  int High) // �������, �� ����� �����
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);

}

void Print(int* a, const int size) // �������, ��� ��������� ����� �� �����
{
	cout << "Array =";
	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << a[i] << ",";
	}
	cout << endl;
}

int Sum(int* a, const int size) // �������, ��� �������� ���� �䒺���� �������� ������.
{
	int S = 0;

	for (int i = 0; i < size; i++)
	{
		if (a[i] < 0)
			S += a[i];
	}

	return S;


}
int FindMin(int* a, const int size) //  �������, ��� ���� ��������� ������� ������
{
	int min = a[0];
	int imin = 0;
	for (int i = 1; i < size; i++)
		if (a[i] < min)
		{
			min = a[i];
			imin = i;
		}

	return imin;
}
int FindMax(int* a, const int size) //   �������, ��� ���� ������������ ������� ������
{
	int max = a[0];
	int imax = 0;
	for (int i = 1; i < size; i++)
		if (a[i] > max)
		{
			max = a[i];
			imax = i;
		}

	return imax;
}

int P1(int* a, int ix1, int ix2) //  �������, ��� ���� ������� �������� ������, ������������ �� ������������ � ��������� ����������.
{
	int P = 1;

	for (int i = ix1 + 1; i <ix2; i++)
	{
		P *= a[i];
	}

	return P;
}

void Sort(int* a, const int size) //  �������, ��� ���������� �������� ������ �� ����������.
{
	for (int i = 1; i < size; i++) 
		for (int j = 0; j < size - i; j++) 
			if (a[j] > a[j + 1]) 
			{ 
				int x = a[j];
				a[j] = a[j + 1];
				a[j + 1] = x;
			}
}

int main()
{
	srand((unsigned)time(NULL));


	int Low, High, n, iMin, iMax, P;

	cout << "Array size ="; cin >> n;

	int* a = new int[n];


	cout << "Low ="; cin >> Low;
	cout << "High ="; cin >> High;
	cout << endl;

	
	Create(a, n, Low, High);
	Print(a, n);
	cout << endl;

	int S = Sum(a, n);
	cout << "1.1)Sum = " << S << endl;
	cout << endl;

	iMin = FindMin(a, n);
	iMax = FindMax(a, n);

	cout << "Min a[" << iMin << "]=" << a[iMin] << endl;
	cout << "Max a[" << iMax << "]=" << a[iMax] << endl;
	cout << endl;

	if (iMin < iMax)             
		P = P1(a, iMin, iMax);
	else
		P = P1(a, iMax, iMin);

	cout << "1.2)P = " << P << endl;
	cout << endl;

	Sort(a, n);
	Print(a, n);

	
	return 0;
}