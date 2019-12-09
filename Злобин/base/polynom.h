#ifndef __POLYNOM_H__
#define __POLYNOM_H__

#include "list.h"
#include "monom.h"

using namespace std;

class Polynom : public List<Monom>
{
	int total_unknowns;
public:
	Polynom(string s, int _total_unkowns);

	Polynom operator+ (const Polynom& _polynom);
	Polynom operator- (const Polynom& _polynom);
	Polynom operator* (const Polynom& _polynom);

	void Insert(const Monom& m);
	void Differential(char _x, int deg);
	void Integral(char _x, int deg);
	double Result(const vector<double>& _res);
};
#endif
