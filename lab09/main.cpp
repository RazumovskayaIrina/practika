#include "unum.h"

void main() {
	setlocale(LC_ALL, "Rus");
	bool e, e0;
	bibl buf, *nach = NULL;
	ifstream x;
	ofstream y;
	x.open(F);
	while (!x.eof()) {
		x >> buf.ud >> buf.fm >> buf.en >> buf.na >> buf.go >> buf.kl;
		prob(buf.na);
		if (strlen(buf.ud) < 2) { break; };
		input(nach, buf);
	}
	x.close();
	e = 1; menu();
	while (e) {
		switch (_getch()) {
		case '1':
			e0 = 1;
			output(nach, e0, 0);
			cout << "________________________________________________________________________________________________________________________\n";

			if (e0) { cout << "��� �������!\n"; break; }
			break;
		case '2':
			e0 = 1;
			output(nach, e0, 1);
			cout << "________________________________________________________________________________________________________________________\n";

			if (e0) { cout << "��� �������!\n"; break; }
			break;
		case '3':
			e0 = 1;
			cout << "������� ������� ������: "; 
			cin >> buf.fm; 
			cin.ignore(); 
			OemToCharA(buf.fm, buf.fm); 
			buf.fm[0] = toupper(buf.fm[0]);
			cout << endl << "************************************************************************************************************************\n";
			output(nach, e0, buf.fm);
			cout << endl << "************************************************************************************************************************\n";

			if (e0) { cout << "��� �������!\n"; break; };
			break;
		case '4':
			if (input(buf)) { break; };
			input(nach, buf);
			cout << "������ ������� ���������!\n";
			break;
		case '5':
			cout << "������� �������� ����� ��� � �������� (��� ������ ������� 0): "; 
			cin.getline(buf.na, dl); OemToCharA(buf.na, buf.na); 
			if (buf.na[0] == '0') { cout << "������!\n"; break; };
			_delete(nach, buf.na);
			if (buf.na[0] == '-') { cout << "������ ������� �������!\n"; }
			else { cout << "������ �� �������!\n"; };
			break;
		case '6':
			y.open(F);
			output(nach, y);
			y.close();
			cout << "���� �������!\n";
			break;
		case '7':
			system("cls");
			menu();
			break;
		case '8': e = 0; break;
		};
	};
	_delete(nach);
};