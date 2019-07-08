#include <iostream>
#include<math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int i = 0;//�������
	int n = 0; //���������� ��������� � �������

	cout << "������� ���������� ��������� �������: ";
	cin >> n;
	int* a = new int[n];
	cout << endl << "������� �������� �������: ";
	for (i = 0; i < n; i++) cin >> a[i];
	cout  << "______________________________________________________________________________" << endl;
	//���� ������� 1
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			sum += a[i];
		}
	}
	cout << endl << " 1. ����� ������������� ���������:\t" << sum << endl;

	//���� ������� 2
	
//���������� ������������
	int imax = 0, imin = 0;//������������ ������� � �����������
	for (i = imax = imin = 0; i < n; i++)
	{
		if (abs(a[i]) > abs(a[imax])) imax = i;
		if (abs(a[i]) < abs(a[imin])) imin = i;
	}

	int ibeg = imax < imin ? imax : imin;//������
	int iend = imax < imin ? imin : imax;//�����
	int p = 1;//���������� ������������
	if (iend - ibeg == 1)
		p = 0;
	else
	{

		for (i = ibeg + 1; i < iend; i++)
			p = p * a[i];
	}
	
	cout << " 2. ������������ ��������� ����� ���� � ��� �� ������ ����������: " << p << endl;
	
	// ������� 3 ����������� �������� ������� �� �������� 
	int maxi = 0, k = 0, j = 0;
	for (i = 0; i < n; i = i++) {
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
	cout << " 3. ������������� ������ �� ��������: ";
	for (i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl << "______________________________________________________________________________" << endl;
	delete[] a;
	system("pause");
}
