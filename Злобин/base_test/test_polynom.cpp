#include "polynom.cpp"
#include <gtest.h>

TEST(Polynom, can_create_polynom)
{
	ASSERT_NO_THROW(Polynom p());
}

TEST(Polynom, can_create_polynom_by_string)
{
	string s = "5x1y2z3 7x2y4z6";
	ASSERT_NO_THROW(Polynom p(s, 3));
}

TEST(Polynom, can_copy_polynom)
{
	string s = "5x1y2z3 7x2y4z6";
	Polynom p(s, 3);
	ASSERT_NO_THROW(Polynom p1(p));
}

TEST(Polynom, can_insert)
{
	string s1 = "5x1y2z3 7x2y4z6";
	string s2 = "3x1y1z1";
	Polynom p(s1, 3);
	Monom m(s2, 3);
	ASSERT_NO_THROW(p.Insert(m));
}

TEST(Polynom, can_do_operation_plus)
{
	string s1 = "5x1y2z3";
	string s2 = "5x1y3z3";
	Polynom p1(s1, 3), p2(s2, 3);
	ASSERT_NO_THROW(p1 + p2);
}

TEST(Polynom, can_do_operation_minus)
{
	string s1 = "5x1y2z3";
	string s2 = "5x1y3z3";
	Polynom p1(s1, 3), p2(s2, 3);
	ASSERT_NO_THROW(p1 - p2);
}

TEST(Polynom, can_do_operation_multiplication_with_monom)
{
	string s1 = "5x1y2z3";
	string s2 = "5x1y3z3";
	Polynom p(s1, 3);
	Monom m(s2, 3);
	ASSERT_NO_THROW(p * m);
}

TEST(Polynom, can_do_operation_multiplication)
{
	string s1 = "5x1y2z3";
	string s2 = "5x1y3z3";
	Polynom p1(s1, 3), p2(s2, 3);
	ASSERT_NO_THROW(p1 * p2);
}

TEST(Polynom, can_do_operation_division)
{
	string s1 = "5x1y2z3";
	string s2 = "5x1y3z3";
	Polynom p(s2, 3);
	Monom m(s1, 3);
	ASSERT_NO_THROW(p / m);
}

TEST(Polynom, can_take_the_differential)
{
	string s = "5x1y2z3 7x2y4z6";
	Polynom p(s, 3);
	ASSERT_NO_THROW(p.Differential('y', 2));
}

TEST(Polynom, can_take_the_integral)
{
	string s = "5x1y2z3 7x2y4z6";
	Polynom p(s, 3);
	ASSERT_NO_THROW(p.Integral('x', 2));
}