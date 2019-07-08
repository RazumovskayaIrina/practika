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
	cout << "������� ���������� ����� �������: \t ";
	cin >> n;
	cout << "������� ���������� �������� �������: \t";
	cin >> m;                  
	
	int** a = new int*[n];          
	for (int i = 0; i < n; i++) a[i] = new int[m]; 
	cout << "������� �������� �������:" << endl;
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


	
	cout << "������� ���������� ����� �������: \t ";
	cin >> n;
	cout << "������� ���������� �������� �������: \t";
	cin >> m;                        
	float** b = new float*[n];           
	for (int i = 0; i < n; i++) b[i] = new float[m]; 
	cout << "������� �������� �������:" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cout << "[" << i << "][" << j << "]= ";
			cin >> b[i][j];
		}           
  

	Vivod(b, n, m); cout << endl;
	KOL(b, n, m);
	cout << "���������� ������ ������ ������ � �������� �������, ��� ��� ��� �� �������� �������!" << endl;

	//Characteristik(b, nrow, ncol);
	delete[] b;

	system("pause");
}


template <class T> void Vivod(T** A, const int n, const int m)
{
	cout << "\n��� �������: " << endl;
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
	cout << "2) C���� ������� ������ ��������� ������: " << endl << endl;
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
					A[i + 1][j] = buf;          //����������
				}
			}
		}
		cout << "3) ������ ������������� �� ���������� ������������� �����: " << endl << endl;
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
	cout << endl << "1) ���������� ��������, �� ���������� �� ������ �������� ��������: " << kol << endl;
	cout << "______________________________________________________________________________" << endl;

	return kol;

}
