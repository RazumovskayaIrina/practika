#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>

using namespace std;
int **mas, n, m, i, j, koll=0, l, buf;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "������� ���������� ����� �������: \t ";
	cin >> n;
	cout << "������� ���������� �������� �������: \t";
	cin >> m;
	mas = new int*[n];
	for (i = 0; i < n; i++)
		mas[i] = new int[m];
	cout << "������� �������� �������:\t " << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			cout << "[" << i << "][" << j << "]= ";
			cin >> mas[i][j];
		}
	cout << "\n��� �������: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		cout << mas[i][j] << setw(4) << "  ";
		cout << endl;
	}
	

	for (j = 0; j < m; j++)
	{
		for (i = 0; i < n && mas[i][j] != 0; i++);
		if (i == n)koll++;
	}
	cout << endl << "1) ���������� ��������, �� ���������� �� ������ �������� ��������: " << koll << endl;
	cout << "______________________________________________________________________________" << endl;

	long *sum = new long[n];
	for (int i = 0; i < n; i++)
		sum[i] = 0;
		for (i = 0; i < n; i++) {
		for (j = 0; j < m; j ++)
			if (mas[i][j] > 0 && mas[i][j] % 2 == 0) sum[i] += mas[i][j];
	}
	

	cout << "2) C���� ������� ������ ��������� ������: " << endl << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) cout << mas[i][j] << setw(4) << "  ";
		cout << setw(4) << "= " << sum[i] << endl;
	}   cout << endl;
	cout << "______________________________________________________________________________" << endl;


	for (l = 0; l < m; l++)
		for (i = 0; i < n - 1; i++)
		{
			if (sum[i] > sum[i + 1])
			{
				buf = sum[i];
				sum[i] = sum[i + 1];
				sum[i + 1] = buf;
				for (j = 0; j < m; j++)
				{
					buf = mas[i][j];
					mas[i][j] = mas[i + 1][j];
					mas[i + 1][j] = buf;          //����������
				}
			}
		}
	
	cout << "3) ������ ������������� �� ���������� ������������� �����: " << endl << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << mas[i][j] << setw(4) << "  ";
		cout << setw(4) << "= " << sum[i] << endl;
	}
	cout << "______________________________________________________________________________" << endl;

	system("pause");
}
