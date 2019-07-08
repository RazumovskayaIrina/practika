#include <windows.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	const int FIO = 20, GR = 7, YSPEV = 5, l_buf = FIO + GR + YSPEV;
	int n, cnt2 = 0;
	cout << "Введите колличество студентов: ";
	cin >> n;
	struct STUDENT {
		char fio[FIO + 1];
		char n_gr[GR + 1];
		int  yspev[YSPEV];
		double s_ball;
	};

	STUDENT stud;
	STUDENT *st = new STUDENT[n];

	for (int j = 0; j < n; j++) 
	{
		cout << "_________________________________" << endl; 
		cout << "Введите данные студента № " << j + 1 << endl << endl;
		cout << "Введите фамилию и инициалы: ";
		cin.getline(st[j].fio, FIO + 1);
		OemToChar(st[j].fio, st[j].fio);
		cin.getline(st[j].fio, FIO + 1);
		OemToChar(st[j].fio, st[j].fio);
		cout << "Введите номер группы: ";
		cin.getline(st[j].n_gr, GR + 1);
		OemToChar(st[j].n_gr, st[j].n_gr);
		st[j].s_ball = 0;
		for (int i = 0; i < YSPEV; i++) {
			cout << "Введите оценку по предмету " << i + 1 << ": ";
			cin >> st[j].yspev[i];
			st[j].s_ball += st[j].yspev[i];
		}
		st[j].s_ball /= YSPEV;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (st[j].s_ball > st[j + 1].s_ball) {
				stud = st[j];
				st[j] = st[j + 1];
				st[j + 1] = stud;
			}
		}
	}

	cout << endl << "________________________Данные студентов упорядочены по возрастанию среднего балла____________________" << endl << endl;
	for (int j = 0; j < n; j++) {
		cout << "-  Фамилия и инициалы: " << st[j].fio << endl;
		cout << "-  Номер группы: " << st[j].n_gr << endl;
		for (int i = 0; i < YSPEV; i++) {
			cout << "   * Оценка: " << i + 1 << ": " << st[j].yspev[i];
			cout << endl;
		}
		cout << "-  Средний балл: " << st[j].s_ball << endl << endl;
	}

	cout << "_________________________________________Список хорошистов и отличников______________________________________" << endl << endl;
	for (int j = 0; j < n; j++) {
		bool cnt = true;
		for (int i = 0; i < YSPEV; i++) {
			if (st[j].yspev[i] != 4 && st[j].yspev[i] != 5) { cnt = false; cnt2++; break; };
		}
		if (cnt == true) { cout << st[j].fio << "   " << st[j].n_gr << endl; }
	}
	
	if (cnt2 == n) 
	cout << "Таких студентов нет!"  << endl;
	cout << "_______________________________________________________________________________________________________" << endl << endl;

	system("pause");
}