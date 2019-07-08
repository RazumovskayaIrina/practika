#include <iostream>
#include<math.h>
using namespace std;
template <class T> T sum(T *A, const int n);
template <class T> T proizv(T *A, const int n);
template <class T> T sort(T *A, const int n);
;
int main() {
	
	int n; //���������� ��������� � �������
	setlocale(LC_ALL, "Rus");
	
	cout << endl << "____________________________________________��� ������ DOUBLE__________________________________" << endl << endl;
	cout  << "������� ���������� ���������:  "; 
	cin >> n;
	double *b = new double[n];
	cout << endl << "������� �������� ������� (���� double):  " ;
	for (int i = 0; i < n; i++) cin >> b[i]; 

	
	//���� 1-�� �������
	sum(b, n);
	//���� 2-�� �������
	proizv(b, n);
	//���� 3-�� �������
	sort(b, n);
	cout << endl << endl << "____________________________________________��� ������ INT_____________________________________" << endl ;

	cout << endl <<"������� ���������� ��������� �������:  ";
	cin >> n;
	int* a = new int[n];
	cout << endl <<"������� �������� ������� (���� int):  ";
	for (int i = 0; i < n; i++) cin >> a[i]; 
		
	//���� 1-�� �������
	sum(a, n);
	//���� 2-�� �������
	proizv(a, n);
	//���� 3-�� �������
	sort(a, n);
	
	delete[] a;
	delete[] b;
	system("pause");
}


template <class T> T  sum(T *A, const int n)
{ 
	T sum = 0;
	for (int i = 0; i < n; i++) if (A[i] > 0) sum += A[i];
	if (sum == 0)
	{ cout << "\n������������� ��������� ���!\n"; return 1;
	}
	else
	{ cout << "\n1) ����� ������������� ���������:  " << sum << endl; return 0;
	}
}

template <class T> T proizv(T *A, const int n)
{
	int imax = 0, imin = 0;
	for (int i = imax = imin = 0; i < n; i++) {
		if (A[i] > A[imax]) imax = i;
		if (A[i] < A[imin]) imin = i;
	}
	int ibeg = imax < imin ? imax : imin;
	int iend = imax < imin ? imin : imax;
	double p = 1;
	for (int i = ibeg + 1; i < iend; i++) p *= A[i];
	cout << "\n2) ������������ ��������� ����� max � min: " << p << endl << endl;
	return 0;
}
	
	
template <class T> T sort(T *A, const int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int maxi = 0, k = 0, j = 0;
		for (i = 0; i < n; i = i++) {
			T maxi = A[i];
			k = i;
			for (j = i + 1; j < n; j = j + 1) {
				if (maxi < A[j]) {
					maxi = A[j];
					k = j;
				}
			}
			A[k] = A[i];
			A[i] = maxi;
		}
		cout << "3) ��������������� ������ �� ��������:  ";
		for (i = 0; i < n; i++) cout << A[i] << " ";
		cout << endl << "______________________________________________________________________________" << endl;
		return 0;
	}
}