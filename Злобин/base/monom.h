#ifndef __MONOM_H__
#define __MONOM_H__

#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>

using namespace std;

struct Monom
{
	double c;
	vector<int> power; 
	Monom() : c(0), power(0) {}
	Monom(double _c) : c(_c), power(0) {}
	Monom(double _c, int total_unkowns) : c(_c), power(total_unkowns) {}
	Monom(double _c, const vector<int>& _power) : c(_c), power(_power) {}
	Monom(string m, int total_unkowns) :power(total_unkowns) {
		string unknowns("xyznk"), tmp, _x;
		m.push_back(' ');
		m.insert(m.begin(), ' ');
		for (string::iterator i = --m.end(); m.begin() < i; i--)
			if (unknowns.find(*i) != string::npos) {
				m.insert(i + 1, ' ');
				m.insert(i, ' ');
			}
		stringstream s(m);
		vector<string> v;
		while (s >> tmp) v.push_back(tmp);
		try {
			c = stod(v.at(0));
			v.erase(v.begin());
		}
		catch (invalid_argument) {
			c = 1;
		}
		for (size_t i = 0; i < v.size() - 1; i++)
		{
			_x = v.at(i);
			tmp = v.at(++i);
			power[unknowns.find(_x)] = stoi(tmp);
		}
	}
	Monom(const Monom& _monom) :c(_monom.c), power(_monom.power) {}

	bool operator< (const Monom& _monom) {
		if (power.size() != _monom.power.size()) throw "not_equal";
		for (size_t i = 0; i < power.size(); i++)	{
			if (power[i] == _monom.power[i]) continue;
			else
				return (power[i] < _monom.power[i]) ? true : false;
		}
		return false;
	}
	bool operator> (const Monom& _monom) {
		if (power.size() != _monom.power.size()) throw "not_equal";
		for (size_t i = 0; i < power.size(); i++) {
			if (power[i] == _monom.power[i]) continue;
			else
				return (power[i] > _monom.power[i]) ? true : false;
		}
		return false;
	}
	bool operator<= (const Monom& _monom) { return !(*this > _monom); }
	bool operator>= (const Monom& _monom) { return !(*this < _monom); }
	bool operator== (const Monom& _monom) {
		if (power.size() != _monom.power.size()) throw "not_equal";
		for (size_t i = 0; i < power.size(); i++) {
			if (power[i] != _monom.power[i]) return false;
		}
		return true;
	}

	Monom& operator= (const Monom& _monom) {
		c = _monom.c;
		power = _monom.power;
		return *this;
	}
	Monom operator* (double _c) {
		Monom res(*this);
		res.c *= _c;
		return res;
	}
	Monom operator* (const Monom& _monom) {
		Monom res(_monom);
		res.c *= c;
		for (size_t i = 0; i < res.power.size(); i++)
			res.power[i] += power[i];
		return res;
	}
	Monom operator/ (const Monom& _monom) {
		Monom res(*this);
		res.c /= _monom.c;
		for (size_t i = 0; i < res.power.size(); i++)
			res.power[i] -= _monom.power[i];
		return res;

	}

	void Differential(char _x, int deg) {
		string unknowns("xyznk");
		int index = unknowns.find(_x);
		if (power[index] < deg && power[index] >= 0) {
			c = 0;
			for each (int d in power) { d = 0; }
			return;
		}
		for (size_t i = 0; i < deg; i++)
		{
			c *= power[index];
			power[index]--;
		}
	}
	void Integral(char _x, int deg) {
		string unknowns("xyznk");
		int index = unknowns.find(_x);
		if (power[index] < 0 && power[index] + deg > -1) throw "logarithms_not_supported";
		for (size_t i = 0; i < deg; i++)
		{
			power[index]++;
			c /= power[index];
		}
	}
	bool IsExist() { return c == 0; }
	int GetPow(int order) { return power[order]; }
	int GetPow(char _x) {
		string unknowns("xyznk");
		return power[unknowns.find(_x)];
	}
	double Result(const vector<double>& _res) {
		double res = c;
		for (size_t i = 0; i < power.size(); i++)
			res *= pow(_res[i], power[i]);
		return res;
	}
	void Print() {
		cout << "\t" << c;
		for (size_t i = 0; i < power.size(); i++)
			cout << "\t" << power.at(i);
		cout << endl;
	}

	friend ostream& operator<< (ostream& out, const Monom& _monom) {
		out << _monom.c;
		string unknows = "xyznk";
		for (size_t i = 0; i < _monom.power.size(); i++)
			out << unknows[i] << _monom.power[i];
		return out;
	}
};

#endif
