#ifndef __MONOM_H__
#define __MONOM_H__

#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

struct Monom
{
	double c;
	vector<int> power; 
	Monom() : c(0), power(0) {}
	Monom(double _c, const vector<int>& _power) : c(_c), power(_power) {}
	Monom(string m, int total_unkowns) :power(total_unkowns) {
		string unknowns("xyznk"), tmp, _x;
		m.push_back(' ');
		for (size_t i = m.length() - 1; 0 <= i; i--)
			if (unknowns.find(m[i]) != string::npos) {
				m.insert(i + 1, " ");
				m.insert(i, " ");
			}
		stringstream s(m);
		vector<string> v;
		while (s >> tmp) v.push_back(tmp);
		c = stod(v.at(0));
		for (size_t i = 1; i < v.size(); i++)
		{
			_x = v.at(i);
			if (i + 1 == v.size() || unknowns.find(tmp) != string::npos) {
				tmp = "1";
				power[unknowns.find(_x)] = stoi(tmp);
				continue;
			}
			tmp = v.at(++i);
			power[unknowns.find(_x)] = stoi(tmp);
		}
	}
	Monom(const Monom& _monom) :c(_monom.c), power(_monom.power) {}

	bool operator< (const Monom& _monom)
	{
		if (power.size() != _monom.power.size()) throw "not_equal";
		for (size_t i = 0; i < power.size(); i++)	{
			if (power[i] == _monom.power[i]) continue;
			else
				return (power[i] < _monom.power[i]) ? true : false;
		}
		return false;
	}
	bool operator> (const Monom& _monom)
	{
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
	bool operator== (const Monom& _monom)
	{
		if (power.size() != _monom.power.size()) throw "not_equal";
		for (size_t i = 0; i < power.size(); i++) {
			if (power[i] != _monom.power[i]) return false;
		}
		return true;
	}

	void Differential(char _x, int deg) {
		string unknowns("xyznk");
		int index = unknowns.find(_x);
		if (power[index] < deg) {
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
};

#endif
