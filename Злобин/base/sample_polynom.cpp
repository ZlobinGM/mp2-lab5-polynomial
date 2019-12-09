#include <iostream>
#include <limits>
#include <string>
#include <conio.h>
#include <ctime>
#include <Windows.h>
#include "polynom.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	string unknowns = "xyznk";
	int total_unknows;
	cout << "Введите число переменных x. -1 < x < " << unknowns.length() + 1 << " : ";
	do {
		cin >> total_unknows;
	} while (total_unknows < 0 || total_unknows > unknowns.length());
	cin.ignore();

	string polynom;
	cout << "Введите полином вида (7x1y2z3 -7x1 6y3) : ";
	getline(cin, polynom);

	int ans = 0;
	Polynom p(polynom, total_unknows), tmp;
	Monom m;
	cout << p;
	do {
		cout << "Выберите операцию : " << endl;
		cout << "1. Вывести как таблицу." << endl;
		cout << "2. +" << endl;
		cout << "3. -" << endl;
		cout << "4. *" << endl;
		cout << "5. / (только на моном)" << endl;
		cout << "6. Дифференцировать" << endl;
		cout << "7. Интегрировать" << endl;
		cout << "8. Посчитать" << endl;
		cout << "9. Введите новый моном" << endl;
		cout << "10. Выход" << endl;
		do {
			cin >> ans;
		} while (ans < 1 || ans > 10);
		cin.ignore();

		char x;
		int deg;
		double def;
		vector<double> defs;
		switch (ans)
		{
		case 1:
			p.GetTable();
			break;
		case 2:
			cout << "Введите полином вида (7x1y2z3 -7x1 6y3) : ";
			getline(cin, polynom);
			tmp = Polynom(polynom, total_unknows);
			p = p + tmp;
			cout << p;
			break;
		case 3:
			cout << "Введите полином вида (7x1y2z3 -7x1 6y3) : ";
			getline(cin, polynom);
			tmp = Polynom(polynom, total_unknows);
			p = p - tmp;
			cout << p;
			break;
		case 4:
			cout << "Введите полином вида (7x1y2z3 -7x1 6y3) : ";
			getline(cin, polynom);
			tmp = Polynom(polynom, total_unknows);
			p = p * tmp;
			cout << p;
			break;
		case 5:
			cout << "Введите моном вида (7x1y2z3) : ";
			getline(cin, polynom);
			m = Monom(polynom, total_unknows);
			p = p / m;
			cout << p;
			break;
		case 6:
			cout << "Введите переменную по которой будет взята частичная производная : ";
			cin >> x;
			cout << "Сколько раз взять производную : ";
			do {
				cin >> deg;
			} while (deg < 1);
			p.Differential(x, deg);
			cout << p;
			break;
		case 7:
			cout << "Введите переменную по которой будет взят интеграл : ";
			cin >> x;
			cout << "Сколько раз взять интеграл : ";
			do {
				cin >> deg;
			} while (deg < 1);
			try {
				p.Integral(x, deg);
				cout << p;
			}
			catch (const char* exception) {
				cout << "Логарифмы не поддерживаются ";
			}
			break;
		case 8:
			cout << "Введите значения переменных : ";
			for (size_t i = 0; i < total_unknows; i++)
			{
				cout << unknowns[i] << " = ";
				cin >> def;
				defs.push_back(def);
			}
			cout << p.Result(defs) << endl;
			break;
		case 9:
			cout << "Введите полином вида (7x1y2z3 -7x1 6y3) : ";
			getline(cin, polynom);
			p = Polynom(polynom, total_unknows);
			break;
		}
	} while (ans != 10);
	return 0;
}
