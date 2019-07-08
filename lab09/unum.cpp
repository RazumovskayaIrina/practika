#include "unum.h";
void prob(char *ss) {
	int i;
	for (i = 0; ss[i] != '\0'; i++) {
		if (ss[i] == '_') { ss[i] = ' '; }
	}
}
void pod(char *ss) {
	int i;
	for (i = 0; ss[i] != '\0'; i++) {
		if (ss[i] == ' ') { ss[i] = '_'; }
	}
}
int input(bibl &buf) {
	cout << "������������ ����� ������:\n";
	cout << "������� ����� ���: "; 
	cin >> buf.ud; 
	OemToCharA(buf.ud, buf.ud);  
	if (buf.ud[0] == '0') { 
		cout << "������!\n"; return 1; }
	cout << "������� ������� ������: ";
	cin >> buf.fm; 
	OemToCharA(buf.fm, buf.fm); 
	buf.fm[0] = toupper(buf.fm[0]);
	cout << "������� ������ ����� �����: "; 
	cin >> buf.en[0]; 
	buf.en[0] = toupper(buf.en[0]); 
	buf.en[1] = '.';
	cout << "������� ������ ����� ��������: "; 
	cin >> buf.en[2]; 
	buf.en[2] = toupper(buf.en[2]); 
	buf.en[3] = '.'; 
	buf.en[4] = '\0'; 
	OemToCharA(buf.na, buf.na);
	cout << "������� �������� �����: ";	
	cin.ignore(); 
	cin.getline(buf.na, dl); 
	OemToCharA(buf.na, buf.na);
	cout << "������� ��� �������: "; 
	cin >> buf.go;
	cout << "������� ����������: "; 
	cin >> buf.kl; 
	cin.ignore();
	return 0;
}
void input(bibl *&nach, bibl x) {
	if (NULL == nach) {
		nach = new bibl;
		nach->l = nach->r = NULL;
		strcpy(nach->ud, x.ud);
		strcpy(nach->fm, x.fm);
		strcpy(nach->en, x.en);
		strcpy(nach->na, x.na);
		nach->go = x.go;
		nach->kl = x.kl;
	}
	else {
		if (nach->go > x.go) {
			if (nach->l != NULL) { input(nach->l, x); }
			else {
				nach->l = new bibl;
				nach->l->l = nach->l->r = NULL;
				strcpy(nach->l->ud, x.ud);
				strcpy(nach->l->fm, x.fm);
				strcpy(nach->l->en, x.en);
				strcpy(nach->l->na, x.na);
				nach->l->go = x.go;
				nach->l->kl = x.kl;
			}
		}
		if (nach->go <= x.go) {
			if (nach->r != NULL) { input(nach->r, x); }
			else {
				nach->r = new bibl;
				nach->r->l = nach->r->r = NULL;
				strcpy(nach->r->ud, x.ud);
				strcpy(nach->r->fm, x.fm);
				strcpy(nach->r->en, x.en);
				strcpy(nach->r->na, x.na);
				nach->r->go = x.go;
				nach->r->kl = x.kl;
			}
		}
	}
}

void menu() {
	cout << "����: \n"
		<< "1. ����� ���� ���������������� ����\n"
		<< "2. ����� ���� ���� � �������\n"
		<< "3. ����� ���� �� ������\n"
		<< "4. �������� ������ � �����\n"
		<< "5. ������� ������ � �����\n"
		<< "6. �������� � ����\n"
		<< "7. ������� ��������� ����\n"
		<< "8. ����� �� �������\n" ;
	cout << "________________________________________________________________________________________________________________________\n";

}

void output() {
	cout  << left << setw(dl) << "����� ���" << setw(dl) << "������� � �������� ������" << setw(dl) << "�������� �����" << setw(12) << "��� �������" << "   " << setw(11) << "����������" << endl << endl;
}

void output(bibl *nach, bool &e, int menu) {//����� ���� ������ 0
	if (nach != NULL) {
		output(nach->l, e, menu);
		if (menu == 0 || menu == 1 && nach->kl > 0) {
			if (e) { 
				output(); e = 0; };
			cout << left << setw(dl) << nach->ud << nach->fm << " " << setw(dl - 1 - strlen(nach->fm)) << nach->en << setw(dl) << nach->na << right << setw(11) << nach->go << "   " << setw(11) << nach->kl << endl;
		}
		output(nach->r, e, menu);
	}
}

void output(bibl *nach, bool &e, char *ss) {//����� ������
	if (nach != NULL) {
		output(nach->l, e, ss);
		if (strcmp(nach->fm, ss) == 0) {
			if (e) { 
				output(); e = 0; }
			cout << left << setw(dl) << nach->ud << nach->fm << " " << setw(dl - 1 - strlen(nach->fm)) << nach->en << setw(dl) << nach->na << right << setw(11) << nach->go << "   " << setw(11) << nach->kl << endl;
		}
		output(nach->r, e, ss);
	}
}

void output(bibl *nach, ofstream &y) {
	if (nach != NULL) {
		pod(nach->na);
		y << left << setw(dl) << nach->ud << nach->fm << " " << setw(dl - 1 - strlen(nach->fm)) << nach->en << setw(dl) << nach->na << right << setw(11) << nach->go << "   " << setw(11) << nach->kl << endl;
		output(nach->r, y);
		output(nach->l, y);
	}
}

bibl *_delete(bibl *nach, char *ss) {
	bibl *ptr, *pmin, *tmp;
	if (nach == NULL)
		return nach;
	if (strcmp(ss, nach->na) == 0) {
		ss[0] = '-';
		if (nach->r == NULL) {
			tmp = nach->l;
		}
		else {
			ptr = nach->r;
			if (ptr->l == NULL) {
				ptr->l = nach->l;
				tmp = ptr;
			}
			else {
				pmin = ptr->l;
				while (pmin->l != NULL) {
					ptr = pmin;
					pmin = ptr->l;
				}
				ptr->l = pmin->r;
				pmin->l = nach->l;
				pmin->r = nach->r;
				tmp = pmin;
			}
		}
		delete nach;
		return tmp;
	}
	else {
		nach->l = _delete(nach->l, ss);
		nach->r = _delete(nach->r, ss);
	}
	return nach;
}

void _delete(bibl *&nach) {
	if (nach != NULL) {
		_delete(nach->l);
		_delete(nach->r);
		delete nach;
		nach = NULL;
	}
}