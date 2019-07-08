#include <windows.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int FIO = 20, �_GR = 8, YSPEV = 5;

struct STUDENT {
	char fio[FIO + 1];
	char n_gr[�_GR + 1];
	int  yspev[YSPEV];
	double s_ball;
};


void Vvod(STUDENT *st, int n) {

	for (int j = 0; j < n; j++) {
		cout << "____________________________" << endl;
		cout << "������� ������ �������� � " << j + 1 << endl << endl;
		cout << "������� ������� � ��������: ";
		cin.getline(st[j].fio, FIO + 1);
		OemToChar(st[j].fio, st[j].fio);
		cin.getline(st[j].fio, FIO + 1);
		OemToChar(st[j].fio, st[j].fio);
		cout << "������� ����� ������: ";
		cin.getline(st[j].n_gr, �_GR + 1);
		OemToChar(st[j].n_gr, st[j].n_gr);
		st[j].s_ball = 0;
		for (int i = 0; i < YSPEV; i++) {
			cout << "������� ������ �� �������� " << i + 1 << ": ";
			cin >> st[j].yspev[i];
			st[j].s_ball += st[j].yspev[i];
		}
		st[j].s_ball /= YSPEV;
	}
}

void sort(STUDENT *st, STUDENT stud, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (st[j].s_ball > st[j + 1].s_ball) {
				stud = st[j];
				st[j] = st[j + 1];
				st[j + 1] = stud;
			}
		}
	}
}

void spisok(STUDENT *st, int n) {
	int cnt2 = 0;
	for (int j = 0; j < n; j++) {
		bool cnt = true;
		for (int i = 0; i < YSPEV; i++) {
			if (st[j].yspev[i] != 4 && st[j].yspev[i] != 5) { cnt = false; cnt2++; break; };
		}
		if (cnt == true) { cout << st[j].fio << "   " << st[j].n_gr << endl; }
	}
	if (cnt2 == n)cout << "����� ��������� ���!";
}

int main() {

	setlocale(LC_ALL, "Russian");
	int n = 5;
	cout << "������� ����������� ���������: ";
	cin >> n;
	const int FIO = 20, �_GR = 7, YSPEV = 5, l_buf = FIO + �_GR + YSPEV;
	STUDENT *st = new STUDENT[n];
	STUDENT stud = st[0];

	Vvod(st, n);
	sort(st, stud, n);

	cout << endl << "________________________������ ��������� ����������� �� ����������� �������� �����____________________" << endl << endl;
	for (int j = 0; j < n; j++) {
		cout << "-  ������� � ��������:  " << st[j].fio << endl;
		cout << "-  ����� ������:  " << st[j].n_gr << endl;
		for (int i = 0; i < YSPEV; i++) {
			cout << "   * ������ " << i + 1 << ": " << st[j].yspev[i];
			cout << endl;
		}
		cout << "-  ������� ����:  " << st[j].s_ball << endl << endl;
	}
	
	cout << "_________________________________________������ ���������� � ����������______________________________________" << endl << endl;
	spisok(st, n);
	cout << "_______________________________________________________________________________________________________" << endl << endl;
	system("pause");
}
 