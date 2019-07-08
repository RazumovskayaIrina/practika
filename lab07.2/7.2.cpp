#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void resh(double ch, double x, double y, double eps);
int main() {
	setlocale(LC_ALL, "Russian");
	double eps, Xn, Xk, dX;
	cout << "Введите начальное значение аргумента: ";
	cin >> Xn;
	cout << "Введите конечное значение аргумента: ";
	cin >> Xk;
	cout << "Введите шаг: ";
	cin >> dX;
	cout << "Введите точность: ";
	cin >> eps; 
	cout << endl << "-------------------Расчет ряда Тейлора----------------" << endl;
	cout << "|" << setw(15) << "Значение x" << "|" << setw(15) << "Сумма y" << "|" << setw(20) << "Кол-во итераций n" << "|" << endl;
	cout << "------------------------------------------------------" << endl;
	for (double x = Xn; x <= Xk; x += dX) {
		double ch = x, y = ch; // первый член ряда и суммы
		resh(ch, x, y, eps);
	}
	system("pause");
}

void resh(double ch, double x, double y, double eps) {
	const int MaxIter = 500; // ограничитель количества итераций
	bool done = true; // признак успешного вычисления
	int n;
	double f;
	f = log(sqrt(x + 1)); 
	for (n = 0; fabs(ch) > eps; n++) {
		if (n >= MaxIter) { 
			done = false; break; }
		ch *= ((pow(-1, n))*(pow(x, n + 1))) / (sqrt(n + 1)); // очередной член ряда
		y += ch;
	}
	if (done) {
		cout << "|" << setw(15) << x << "|" << setw(15) << y << "|" << setw(20) << n << "|" << endl;
	}
	else cout << "Ряд расходится!\n"; 
}