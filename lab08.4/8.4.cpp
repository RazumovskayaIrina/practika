#include <iostream> 
#include <iomanip>
#include <math.h>
using namespace std;

template <class T> void Vivod(T** A, const int n, const int m);
template <class T> T SUM(T** A, const int n, const int m);
template <class T> T KOL(T** A, const int n, const int m);

int main()
{


	setlocale(LC_ALL, "Rus");
	
	int n, m;
	cout << "Введите количество строк массива: \t ";
	cin >> n;
	cout << "Введите количество столбцов массива: \t";
	cin >> m;                  
	
	int** a = new int*[n];          
	for (int i = 0; i < n; i++) a[i] = new int[m]; 
	cout << "Введите элементы массива:" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
		{
			cout << "[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}

	Vivod(a, n, m); 
	KOL(a, n, m);
	SUM(a, n, m);
	delete[] a;


	
	cout << "Введите количество строк массива: \t ";
	cin >> n;
	cout << "Введите количество столбцов массива: \t";
	cin >> m;                        
	float** b = new float*[n];           
	for (int i = 0; i < n; i++) b[i] = new float[m]; 
	cout << "Введите элементы массива:" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cout << "[" << i << "][" << j << "]= ";
			cin >> b[i][j];
		}           
  

	Vivod(b, n, m); cout << endl;
	KOL(b, n, m);
	cout << "Невозможно решить данное здание с дробными числами, так как они не являются четными!" << endl;

	//Characteristik(b, nrow, ncol);
	delete[] b;

	system("pause");
}


template <class T> void Vivod(T** A, const int n, const int m)
{
	cout << "\nВид матрицы: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << A[i][j] << setw(4) << "  ";
		cout << endl;
	}

	return;
}

template <class T> T SUM(T** A, const int n, const int m)
{
	T *sum = new T[n];
	int c;
	for (int i = 0; i < n; i++) {
		sum[i] = 0;
		for (int j = 0; j < m; j++) {
			c = A[i][j] / 2;
			if (A[i][j] >= 0 && 2 * c == A[i][j])sum[i] += A[i][j];
		}
	}
	
	/*T *sum = new T[nrow];
	for (int i = 0; i < nrow; i++) {
		sum[i] = 0;
		for (int i = 0; i < nrow; i++) {
			for (int j = 0; j < ncol; j++)
			if (ptrA[i][j] > 0 && ptrA[i][j] % 2 == 0) sum[i] += ptrA[i][j];
		}
	}*/
	cout << "2) Cумма положит четных элементов строки: " << endl << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) cout << A[i][j] << setw(4) << "  ";
		cout << setw(4) << "= " << sum[i] << endl;
	}   cout << endl;
	cout << "______________________________________________________________________________" << endl;

		for (int i = 0; i < n - 1; i++)
		{
			if (sum[i] > sum[i + 1])
			{
				T buf = sum[i];
				sum[i] = sum[i + 1];
				sum[i + 1] = buf;
				for (int j = 0; j < m; j++)
				{
					T buf = A[i][j];
					A[i][j] = A[i + 1][j];
					A[i + 1][j] = buf;          //сортировка
				}
			}
		}
		cout << "3) Массив упорядоченный по взрастанию характеристик строк: " << endl << endl;
		for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) cout << A[i][j] << setw(4) << "  ";
		cout << setw(4) << "= " << sum[i] << endl;
	}   cout << endl;
	cout << "______________________________________________________________________________" << endl;
	return 0;
}

template <class T> T KOL(T** A, const int n, const int m)
{

	int kol = 0;
	int z = 0;
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (A[i][j] == 0) z = 1;
		}
		if (z == 0) ++kol;
		z = 0;
	}
	cout << endl << "1) Количество столбцов, не содержащих ни одного нулевого элемента: " << kol << endl;
	cout << "______________________________________________________________________________" << endl;

	return kol;

}
