#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void resh(double ch, double x, double y, double eps);
int main() {
	setlocale(LC_ALL, "Russian");
	double eps, Xn, Xk, dX;
	cout << "������� ��������� �������� ���������: ";
	cin >> Xn;
	cout << "������� �������� �������� ���������: ";
	cin >> Xk;
	cout << "������� ���: ";
	cin >> dX;
	cout << "������� ��������: ";
	cin >> eps; 
	cout << endl << "-------------------������ ���� �������----------------" << endl;
	cout << "|" << setw(15) << "�������� x" << "|" << setw(15) << "����� y" << "|" << setw(20) << "���-�� �������� n" << "|" << endl;
	cout << "------------------------------------------------------" << endl;
	for (double x = Xn; x <= Xk; x += dX) {
		double ch = x, y = ch; // ������ ���� ���� � �����
		resh(ch, x, y, eps);
	}
	system("pause");
}

void resh(double ch, double x, double y, double eps) {
	const int MaxIter = 500; // ������������ ���������� ��������
	bool done = true; // ������� ��������� ����������
	int n;
	double f;
	f = log(sqrt(x + 1)); 
	for (n = 0; fabs(ch) > eps; n++) {
		if (n >= MaxIter) { 
			done = false; break; }
		ch *= ((pow(-1, n))*(pow(x, n + 1))) / (sqrt(n + 1)); // ��������� ���� ����
		y += ch;
	}
	if (done) {
		cout << "|" << setw(15) << x << "|" << setw(15) << y << "|" << setw(20) << n << "|" << endl;
	}
	else cout << "��� ����������!\n"; 
}