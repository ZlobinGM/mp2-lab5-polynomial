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
	Polynom res(_polynom);
	for (Node<Monom>* p = pFirst; p != nullptr; p = p->pNext)
		res.Insert(p->data);
	return res;
}

Polynom Polynom::operator-(const Polynom& _polynom)
{
	Polynom res(*this);
	for (Node<Monom>* p = _polynom.pFirst; p != nullptr; p = p->pNext) {
		p->data.c *= -1;
		res.Insert(p->data);
	}
	return res;
}

Polynom Polynom::operator*(const Monom& _monom)
{
	if (_monom.c == 0)return Polynom();
	Polynom res(*this);
	for (Node<Monom>* p = res.pFirst; p != nullptr; p = p->pNext)
		p->data = p->data * _monom;
	return res;
}

Polynom Polynom::operator*(const Monom& _monom) const
{
	if (_monom.c == 0)return Polynom();
	Polynom res(*this);
	for (Node<Monom>* p = res.pFirst; p != nullptr; p = p->pNext)
		p->data = p->data * _monom;
	return res;
}

Polynom Polynom::operator*(const Polynom& _polynom)
{
	Polynom res(total_unknowns);
	for (Node<Monom>* p = pFirst; p != nullptr; p = p->pNext)
		res = res + _polynom * p->data;
	return res;
}

Polynom Polynom::operator/(const Monom& _monom)
{
	if (_monom.c == 0) throw "division_by_zero";
	Polynom res(*this);
	for (Node<Monom>* p = res.pFirst; p != nullptr; p = p->pNext)
		p->data = p->data / _monom;
	return res;
}

void Polynom::Insert(const Monom& m)
{
	if (m.c == 0)return;
	if (pFirst == nullptr) {
		pFirst = new Node<Monom>;
		pFirst->data = m;
		pFirst->pNext = nullptr;
		length++;
		return;
	}

	Node<Monom>* _p = new Node<Monom>, * p;
	_p->pNext = pFirst;
	for (p = _p; p->pNext != nullptr; p = p->pNext)
	{
		if (p->pNext->data > m) {
			Node<Monom>* tmp = new Node<Monom>;
			tmp->data = m;
			tmp->pNext = p->pNext;
			p->pNext = tmp;
			length++;
			return;
		}
		if (p->pNext->data == m) {
			double eps = 10e-6;
			if (fabs(p->pNext->data.c - m.c) < eps) {
				Node<Monom>* tmp = p->pNext;
				p = tmp->pNext;
				pFirst = (tmp == pFirst) ? p : pFirst;
				delete tmp;
				length--;
				return;
			}
			else {
				p->pNext->data.c += m.c;
				return;
			}
		}
	}
	_p->data = m;
	_p->pNext = nullptr;
	p->pNext = _p;
	length++;
}

void Polynom::Differential(char _x, int deg)
{
	Node<Monom>* _p = new Node<Monom>, * p;
	_p->pNext = pFirst;
	for (p = _p; p->pNext != nullptr;)
	{
		int var = p->pNext->data.GetPow(_x);
		if (var < deg && var > 0) {
			Node<Monom>* tmp = p->pNext;
			p->pNext = tmp->pNext;
			pFirst = (tmp == pFirst) ? p->pNext : pFirst;
			delete tmp;
			length--;
			continue;
		}
		p->pNext->data.Differential(_x, deg);
		p = p->pNext;
	}
	delete _p;
}

void Polynom::Integral(char _x, int deg)
{
	for (Node<Monom>* p = pFirst; p != nullptr; p = p->pNext)
		p->data.Integral(_x, deg);
}

double Polynom::Result(const vector<double>& _res)
{
	double res = 0;
	for (Node<Monom>* p = pFirst; p != nullptr; p = p->pNext)
		res += p->data.Result(_res);
	return res;
}

void Polynom::GetTable()
{
	cout << "\tc";
	string unknowns("xyznk");
	for (size_t i = 0; i < total_unknowns; i++)
		cout << "\t" << unknowns[i];
	cout << endl;
	if (pFirst == nullptr) {
		Monom(0, total_unknowns).Print();
		return;
	}
	for (Node<Monom>* p = pFirst; p != nullptr; p = p->pNext)
		p->data.Print();
}
