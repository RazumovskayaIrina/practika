#include <iostream> 
#include <iomanip>
#include <math.h>
#include <windows.h>
using namespace std;
int **mas, n, m, i, j, kol=0;

void Vivod(int **mas, int n, int m)
{
	cout << "\nВид матрицы: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << mas[i][j] << setw(4) << "  ";
		cout << endl;
	}

	return;
}

int SUM(int **mas, int n, int m)
{
	int *sum = new int[n];
	int c;
	for (int i = 0; i < n; i++) {
		sum[i] = 0;
		for (int j = 0; j < m; j++) {
			c = mas[i][j] / 2;
			if (mas[i][j] >= 0 && 2 * c == mas[i][j])sum[i] += mas[i][j];
		}
	}

	/*int*sum = new int[n];
	for (int i = 0; i < n; i++) {
		sum[i] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
			if (mas[i][j] > 0 && mas[i][j] % 2 == 0) sum[i] += mas[i][j];
		}
	}*/
	cout << "2) Cумма положит четных элементов строки: " << endl << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) cout << mas[i][j] << setw(4) << "  ";
		cout << setw(4) << "= " << sum[i] << endl;
	}   cout << endl;
	cout << "______________________________________________________________________________" << endl;

	for (int i = 0; i < n - 1; i++)
	{
		if (sum[i] > sum[i + 1])
		{
			int buf = sum[i];
			sum[i] = sum[i + 1];
			sum[i + 1] = buf;
			for (int j = 0; j < m; j++)
			{
				buf = mas[i][j];
				mas[i][j] = mas[i + 1][j];
				mas[i + 1][j] = buf;          //сортировка
			}
		}
	}
	cout << "3) Массив упорядоченный по взрастанию характеристик строк: " << endl << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) cout << mas[i][j] << setw(4) << "  ";
		cout << setw(4) << "= " << sum[i] << endl;
	}   cout << endl;
	cout << "______________________________________________________________________________" << endl;
	return 0;
}

int KOL(int **mas, int n, int m)
{

	int kol = 0;
	int z = 0;
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (mas[i][j] == 0) z = 1;
		}
		if (z == 0) ++kol;
		z = 0;
	}
	cout << endl << "1) Количество столбцов, не содержащих ни одного нулевого элемента: " << kol << endl;
	cout << "______________________________________________________________________________" << endl;

	return kol;

}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите количество строк массива:  " << endl;
	cin >> n;
	cout << "Введите количество столбцов массива: " << endl;
	cin >> m;
	mas = new int*[n];
	for (int i = 0; i < n; i++)
		mas[i] = new int[m];
	cout << "Введите элементы массива: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "[" << i << "][" << j << "]= ";
			cin >> mas[i][j];
		}

	Vivod(mas, n, m);
	KOL(mas, n, m);
	SUM(mas, n, m);

	system("pause");
}

