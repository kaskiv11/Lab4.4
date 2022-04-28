// Lab4.4.cpp : 


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#pragma warning (disable : 4996)


using namespace std;

void PrintTXT(char* fname);
void AddTXT(char* fname);
void CheckTXT(char* fname, int& plus, int& minus, int& zero, int& word);
int addToFileC(char* fname, int plus, int minus, int zero, int word);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char fname[100];
	int plus = 0;
	int minus = 0;
	int zero = 0;
	int word = 0;
	char check[100] = "Checked_";
	int menuItem;
	do {
		cout << "Оберіть дію: " << endl;
		cout << "[1]  Cтворити файл." << endl;
		cout << "[2]  Переглянути нотатку." << endl;
		cout << "[3]  Додати рядки." << endl;
		cout << "[4]  Відкрити файл." << endl;
		cout << "[5]  Перевірити файл." << endl;
		cout << "[0]  вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		switch (menuItem) {
		case 1:
			cout << "Введіть ім'я файлу: "; cin >> fname;
			AddTXT(fname);
			break;
		case 2:
			PrintTXT(fname);
			break;
		case 3:
			AddTXT(fname);
			break;
		case 4:
			cout << "Введіть ім'я файлу: "; cin >> fname;
			break;
		case 5:
			CheckTXT(fname, plus, minus, zero, word);
			strcat(check, fname);
			strcpy(fname, check);
			strcpy(check, "");
			addToFileC(fname, plus, minus, zero, word);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);

	system("pause");
	cin.get();
	return 0;


}

void AddTXT(char* fname) {
	ofstream fout;
	fout.open(fname, ios::app);
	char ch;
	string s;

	do {
		cin.get();
		cin.sync();
		cout << "Введіть рядок:  "; getline(cin, s);
		fout << s << endl;
		cout << "Продовжити? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}


void PrintTXT(char* fname) {
	ifstream fin(fname);
	string s;
	while (getline(fin, s)) {
		cout << s << endl;
	}
	cout << endl;
}

void CheckTXT(char* fname, int& plus, int& minus, int& zero, int& word) {
	ifstream fin(fname);
	char s[400];
	char* w;
	bool done = false;
	cin.ignore();
	while (fin.getline(s, sizeof(s))) {
		w = strtok(s, " ");
		while (w != NULL) {
			for (int i = 0; i < strlen(w); i++) {
				if (w[i] != '0' && w[i] != '1' && w[i] != '2' && w[i] != '3' && w[i] != '4' && w[i] != '5' && w[i] != '6' && w[i] != '7' && w[i] != '8' && w[i] != '9' && w[i] != '-') {
					++word;
					w = strtok(NULL, " ");
					done = true;
					break;
				}
			}
			if (done == false) {
				int tmp = atoi(w);
				if (tmp > 0) {
					++plus;
					w = strtok(NULL, " ");
				}
				else if (tmp < 0) {
					++minus;
					w = strtok(NULL, " ");
				}
				else {
					++zero;
					w = strtok(NULL, " ");
				}
			}
			done = false;
		}
	}
}

int addToFileC(char* fname, int plus, int minus, int zero, int word) {
	ofstream fout(fname);
	if (!fout)
	{
		cerr << "Error writing file '" << fname << "'" << endl;
		return 0;
	}
	string s;
	fout << "Кількість додатніх елементів: " << plus << endl;
	fout << "Кількість від'ємних елементів: " << minus << endl;
	fout << "Кількість нульових елементів: " << zero << endl;
	fout << "Кількість слів: " << word << endl;
	fout.close();
	return 1;
}