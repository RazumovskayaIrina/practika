#include <fstream>
#include <iostream>
#include <cstdio>
#include <windows.h>
using namespace std;


void Lines(char *word, char *buf, char *buffer, long l_word) {
	long i = 0, n = 0, j = 0, m = 0, cnt = 0;
	cout << "Предложения с введенным словом  #" << word << "#:" << endl;
	cout << "___________________________________________________________________________________________________" << endl << endl;

	while (buf[i]) {
		if (buf[i] == '.' || buf[i] == '!' || buf[i] == '?') {
			for (j = n, m = 0; j <= i; j++, m++) {
				buffer[m] = buf[j];
			}
			buffer[m] = '\0';
			char *p = buffer;

			while (p = strstr(p, word)) {

				char *c = p;
				p += l_word;

				if (c != buf) {
					if (!ispunct(*(c - 1)) && !isspace(*(c - 1)))
						continue;
					if (ispunct(*p) || isspace(*p) || (*p == '\0')) {
						cnt++;
						cout << buffer << endl;
						break;
					}
				}
			}
			n = i + 1;
		}
		i++;
	}
	if(cnt == 0) { cout <<"Таких предложений нет!" << endl; }
	cout << "___________________________________________________________________________________________________" << endl;

}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream fin("text.txt");
	if (!fin) { 
		cout << "Файл не может быть открыт!" << endl; 
		return 1; 
	}

	fin.seekg(0, ios::end);
	long len = fin.tellg();
	char *buf = new char[len + 1];
	char *buffer = new char[len + 1];
	char *word = new char[len];
	fin.seekg(0, ios::beg);
	fin.read(buf, len);
	buf[len] = '\0';
	cout << "Введите слово для поиска: "; cin >> word;
	int l_word = strlen(word);
	word[len] = '\0';
	Lines(word, buf, buffer, l_word);
	cout << endl;
	system("pause");
}
