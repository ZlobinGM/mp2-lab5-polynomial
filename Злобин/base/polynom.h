#ifndef __POLYNOM_H__
#define __POLYNOM_H__

#include "list.h"
#include "monom.h"
#include <iostream>

using namespace std;

class Polynom : public List<Monom>
{
	int total_unknowns;
public:
	Polynom() : total_unknowns(0), List() {}
	Polynom(int _total_unkowns) : total_unknowns(_total_unkowns), List() {}
	Polynom(const Monom& _monom) : total_unknowns(_monom.power.size()), List(_monom) {}
	Polynom(string s, int _total_unkowns);
	Polynom(const Polynom& _polynom):total_unknowns(_polynom.total_unknowns), List(_polynom) {}

	Polynom operator+ (const Polynom& _polynom);
	Polynom operator- (const Polynom& _polynom);
	Polynom operator*(const Monom& _monom) const;
	Polynom operator* (const Polynom& _polynom);
	Polynom operator/ (const Monom& _monom);

	void Insert(const Monom& m);
	void Differential(char _x, int deg);
	void Integral(char _x, int deg);
	double Result(const vector<double>& _res);
	void GetTable();
};
#endif
