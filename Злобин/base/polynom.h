#ifndef __POLYNOM_H__
#define __POLYNOM_H__

#include "list.h"
#include "monom.h"

using namespace std;

class Polynom : public List<Monom>
{
public:
	Polynom();
};
#endif
