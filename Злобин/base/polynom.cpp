#include "polynom.h"

Polynom::Polynom(string s, int _total_unkowns) : total_unknowns(_total_unkowns)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '+')s[i] = ' ';
		if (s[i] == '-' && s[i + 1] == ' ') {
			s[i] = ' ';
			s[i + 1] = '-';
		}
	}
	stringstream ss(s);
	string tmp;
	vector<string> v;
	while (ss >> tmp) v.push_back(tmp);
	for each (string str in v)
	{
		Monom m(str, total_unknowns);
		Insert(m);
	}
}

Polynom Polynom::operator+(const Polynom& _polynom)
{
	return Polynom();
}

Polynom Polynom::operator-(const Polynom& _polynom)
{
	return Polynom();
}

Polynom Polynom::operator*(const Polynom& _polynom)
{
	return Polynom();
}

void Polynom::Insert(const Monom& m)
{
}

void Polynom::Differential(char _x, int deg)
{
}

void Polynom::Integral(char _x, int deg)
{
}

double Polynom::Result(const vector<double>& _res)
{
	return 0.0;
}
