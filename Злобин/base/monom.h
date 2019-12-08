#ifndef __MONOM_H__
#define __MONOM_H__

#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Monom
{
	double c;
	vector<int> pow; 
	Monom() : c(0), pow(0) {}
	Monom(double _c, const vector<int>& _pow) : c(_c), pow(_pow) {}
	Monom(string m, int total_unkowns) :pow(total_unkowns) {
		string unknowns("xyznk"), tmp, _x;
		size_t pos;
		for (size_t i = m.length()-1; i >= 0; i--)
			if (pos = unknowns.find(m[i]) != string::npos)
				m.insert(pos, " ");
		stringstream s(m);
		s >> tmp;
		c = stod(tmp);
		for (size_t i = 0; i < pow.size(); i++)
		{
			s >> _x >> tmp;
			if (unknowns.find(tmp) != string::npos) {
				s << tmp;
				tmp = "1";
			}
			pow[unknowns.find(_x)] = stoi(tmp);
		}
	}

	bool operator< (const Monom& _monom)
	{
		if (pow.size() != _monom.pow.size()) throw "not_equal";
		for (size_t i = 0; i < pow.size(); i++)	{
			if (pow[i] == _monom.pow[i]) continue;
			else
				return (pow[i] < _monom.pow[i]) ? true : false;
		}
		return false;
	}
	bool operator> (const Monom& _monom)
	{
		if (pow.size() != _monom.pow.size()) throw "not_equal";
		for (size_t i = 0; i < pow.size(); i++) {
			if (pow[i] == _monom.pow[i]) continue;
			else
				return (pow[i] > _monom.pow[i]) ? true : false;
		}
		return false;
	}
	bool operator<= (const Monom& _monom) { return !(*this > _monom); }
	bool operator>= (const Monom& _monom) { return !(*this < _monom); }
	bool operator== (const Monom& _monom)
	{
		if (pow.size() != _monom.pow.size()) throw "not_equal";
		for (size_t i = 0; i < pow.size(); i++) {
			if (pow[i] != _monom.pow[i]) return false;
		}
		return true;
	}

	void Differential(char _x, int deg) {
		string unknowns("xyznk");
		int index = unknowns.find(_x);
		if (pow[index] < deg) {
			c = 0;
			for each (int d in pow) { d = 0; }
			return;
		}
		for (size_t i = 0; i < deg; i++)
		{
			c *= pow[index];
			pow[index]--;
		}
	}
	void Integral(char _x, int deg) {
		string unknowns("xyznk");
		int index = unknowns.find(_x);
		for (size_t i = 0; i < deg; i++)
		{
			pow[index]++;
			c /= pow[index];
		}
	}
	bool IsExist() { return c == 0; }
	int GetPow(int order) { return pow[order]; }
	int GetPow(char _x) {
		string unknowns("xyznk");
		return pow[unknowns.find(_x)];
	}
};

#endif
