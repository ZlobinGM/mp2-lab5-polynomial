#include "monom.h"
#include <gtest.h>

TEST(Monom, can_create_monom)
{
	ASSERT_NO_THROW(Monom m());
}

TEST(Monom, can_create_monom_by_vector)
{
	vector<int> v = { 1,2,3 };
	ASSERT_NO_THROW(Monom m(5, v));
}

TEST(Monom, can_create_monom_by_string)
{
	string s = "5x1y2z3";
	ASSERT_NO_THROW(Monom m(s, 3));
}

TEST(Monom, can_copy_monom)
{
	string s = "5x1y2z3";
	Monom m(s, 3);
	ASSERT_NO_THROW(Monom m1(m));
}

TEST(Monom, can_do_operation_less)
{
	string s1 = "5x1y2z3";
	string s2 = "5x1y3z3";
	Monom m1(s1, 3), m2(s2, 3);
	EXPECT_EQ(1, m1 < m2);
}

TEST(Monom, can_do_operation_larger)
{
	string s1 = "5x3y3z3";
	string s2 = "2x3y3z3";
	Monom m1(s1, 3), m2(s2, 3);
	EXPECT_EQ(0, m1 < m2);
}

TEST(Monom, can_do_operation_equal)
{
	string s1 = "5x3y3z3";
	string s2 = "2x3y3z3";
	Monom m1(s1, 3), m2(s2, 3);
	EXPECT_EQ(1, m1 == m2);
}

TEST(Monom, can_do_operation_multiplication)
{
	string s1 = "5x1y2z3";
	string s2 = "5x1y3z3";
	string s3 = "x2y5z6";
	Monom m1(s1, 3), m2(s2, 3), m3(s3,3);
	EXPECT_EQ(m3, m1*m2);
}

TEST(Monom, can_do_operation_division)
{
	string s1 = "5x1y2z3";
	string s2 = "5x1y3z3";
	string s3 = "x0y-1z0";
	Monom m1(s1, 3), m2(s2, 3), m3(s3, 3);
	EXPECT_EQ(m3, m1 / m2);
}

TEST(Monom, can_take_the_differential)
{
	string s1 = "5x1y2z3";
	string s2 = "x1y0z3";
	Monom m1(s1, 3), m2(s2, 3);
	m1.Differential('y', 2);
	EXPECT_EQ(m2, m1);
}

TEST(Monom, can_take_the_integral)
{
	string s1 = "5x1y2z3";
	string s2 = "x1y4z3";
	Monom m1(s1, 3), m2(s2, 3);
	m1.Integral('y', 2);
	EXPECT_EQ(m2, m1);
}

TEST(Monom, can_get_pow)
{
	string s = "5x1y2z3";
	Monom m(s, 3);
	EXPECT_EQ(2, m.GetPow('y'));
}

TEST(Monom, can_calculate)
{
	string s = "5x1y2z3";
	vector<double> v = { 1,2,3 };
	Monom m(s, 3);
	EXPECT_DOUBLE_EQ(180, m.Result(v));
}