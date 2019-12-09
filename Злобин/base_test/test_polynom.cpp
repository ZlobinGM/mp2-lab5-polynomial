#include "polynom.cpp"
#include <gtest.h>

TEST(Polynom, can_create_monom)
{
	ASSERT_NO_THROW(Polynom p());
}

TEST(Polynom, can_create_monom_by_string)
{
	string s = "5x1y2z3";
	ASSERT_NO_THROW(Polynom p(s, 3));
}

TEST(Polynom, can_copy_monom)
{
	string s = "5x1y2z3";
	Polynom p(s, 3);
	ASSERT_NO_THROW(Polynom p1(p));
}

TEST(Polynom, can_insert)
{
	string s1 = "5x1y2z3";
	string s2 = "5x1y3z3";
	Polynom m1(s1, 3), m2(s2, 3);
	EXPECT_EQ(1, m1 < m2);
}

TEST(Polynom, can_do_operation_plus)
{
	string s1 = "5x1y2z3";
	string s2 = "5x1y3z3";
	Polynom m1(s1, 3), m2(s2, 3);
	EXPECT_EQ(1, m1 < m2);
}

TEST(Polynom, can_do_operation_minus)
{
	string s1 = "5x3y3z3";
	string s2 = "2x3y3z3";
	Polynom m1(s1, 3), m2(s2, 3);
	EXPECT_EQ(0, m1 < m2);
}

TEST(Polynom, can_do_operation_multiplication)
{
	string s1 = "5x3y3z3";
	string s2 = "2x3y3z3";
	Polynom m1(s1, 3), m2(s2, 3);
	EXPECT_EQ(1, m1 == m2);
}