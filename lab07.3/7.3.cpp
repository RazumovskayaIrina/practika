#include <iostream>
#include<math.h>
using namespace std;

int sum(int *a, int n)
{
	//Блок задания 1
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			sum += a[i];
		}
	}
	return sum;
}

int pr(int *a, int n)
{
	//Блок задания 2

	int imax = 0, imin = 0;
	for (int i = imax = imin = 0; i < n; i++) {
		if (a[i] > a[imax]) imax = i;
		if (a[i] < a[imin]) imin = i;
	}
	int ibeg = imax < imin ? imax : imin;
	int iend = imax < imin ? imin : imax;
	int p = 1;
	for (int i = ibeg + 1; i < iend; i++) p *= a[i];
	
	return p;
}

void sort(int *a, int n)
{
	//Блок задания 3
	int maxi = 0, k = 0, j = 0;
	for (int i = 0; i < n; i = i++) {
		maxi = a[i];
		k = i;
		for (j = i + 1; j < n; j = j + 1) {
			if (maxi < a[j]) {
				maxi = a[j];
				k = j;
			}
		}
		a[k] = a[i];
		a[i] = maxi;
	}
}

void out(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";

	}

}

int main()
{
	int n; //количество элементов в массиве
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество элементов массива:  ";
	cin >> n;
	int* a = new int[n];
	cout << endl << "Введите элементы массива:  ";
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << "______________________________________________________________________________" << endl;


	cout << endl << " 1. Сумма положительных элементов:  " << sum(a, n) << endl;
	cout << endl << " 2. Произведение элементов между макс и мин по модулю элементами:  " << pr(a, n) << endl;
	sort(a, n);
	cout << endl << " 3. Упорядоченный массив по убыванию:  ";
	out(a, n);
	cout << endl << "______________________________________________________________________________" << endl << endl;
	system("pause");

	}