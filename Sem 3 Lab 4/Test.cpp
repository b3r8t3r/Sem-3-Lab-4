#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "..\..\Sem 3 Lab 6 Lib Files\FracNum\FracNum.h"


BOOST_AUTO_TEST_SUITE(FracNum_Arithmetic_Operator_Overload)
BOOST_AUTO_TEST_CASE(Sum)
{
	FracNum a(2, 3), b(4, 5), sum(22, 15);
	BOOST_CHECK_EQUAL(a + b, sum);
	a = { -15,1 }, sum = { -71,5 };
	BOOST_CHECK_EQUAL(a + b, sum);
	a = { 0,5 };
	BOOST_CHECK_EQUAL(a + b, b);

	int x = 5;
	a = { 2,3 }, sum = { 17,3 };
	BOOST_CHECK_EQUAL(a + x, sum);
	a = { -15,1 }, sum = { -10,1 };
	BOOST_CHECK_EQUAL(a + x, sum);
	a = { 0,5 }, sum = { 5,1 };
	BOOST_CHECK_EQUAL(a + x, sum);
}

BOOST_AUTO_TEST_CASE(Sub) {
	FracNum a(2, 3), b(4, 5), sub(-2, 15);
	BOOST_CHECK_EQUAL(a - b, sub);
	a = { -7, 9 }, sub = { -71,45 };
	BOOST_CHECK_EQUAL(a - b, sub);
	a = { 0, 2 }, sub = { -4,5 };
	BOOST_CHECK_EQUAL(a - b, sub);

	int x = 5;
	a = { 2, 3 }, sub = { -13,3 };
	BOOST_CHECK_EQUAL(a - x, sub);
	a = { -7, 9 }, sub = { -52,9 };
	BOOST_CHECK_EQUAL(a - x, sub);
	a = { 0, 2 }, sub = { -5,1 };
	BOOST_CHECK_EQUAL(a - x, sub);
}

BOOST_AUTO_TEST_CASE(Mul) {
	FracNum a(2, 3), b(4, 5), mul(8, 15);
	BOOST_CHECK_EQUAL(a * b, mul);
	a = { -7, 9 }, mul = { -28,45 };
	BOOST_CHECK_EQUAL(a * b, mul);
	a = { 0, 2 }, mul = { 0,1 };
	BOOST_CHECK_EQUAL(a * b, mul);

	int x = 5;
	a = { 2,3 }, mul = { 10, 3 };
	BOOST_CHECK_EQUAL(a * x, mul);
	a = { -7, 9 }, mul = { -35,9 };
	BOOST_CHECK_EQUAL(a * x, mul);
	a = { 0, 2 }, mul = { 0,1 };
	BOOST_CHECK_EQUAL(a * x, mul);
}

BOOST_AUTO_TEST_CASE(Div) {
	FracNum a(2, 3), b(4, 5), div(5, 6);
	BOOST_CHECK_EQUAL(a / b, div);
	a = { 7, 9 }, div = { 35,36 };
	BOOST_CHECK_EQUAL(a / b, div);
	a = { 0, 2 }, div = { 0,1 };
	BOOST_CHECK_EQUAL(a / b, div);

	int x = 5;
	a = { 2,3 }, div = { 2,15 };
	BOOST_CHECK_EQUAL(a / x, div);
	a = { 7, 9 }, div = { 7,45 };
	BOOST_CHECK_EQUAL(a / x, div);
	a = { 0, 2 }, div = { 0,1 };
	BOOST_CHECK_EQUAL(a / x, div);
}

BOOST_AUTO_TEST_CASE(Pow) {
	int x = 2;
	FracNum a(2, 3), power(4, 9);
	BOOST_CHECK_EQUAL(a ^ x, power);
	a = { -7, 9 }, power = { 49,81 };
	BOOST_CHECK_EQUAL(a ^ x, power);
	a = { 0, 2 }, power = { 0,1 };
	BOOST_CHECK_EQUAL(a ^ x, power);

	x = -1;
	a = { 3, 11 }, power = { 11,3 };
	BOOST_CHECK_EQUAL(a ^ x, power);

	x = 0;
	a = { 3, 11 }, power = { 1,1 };
	BOOST_CHECK_EQUAL(a ^ x, power);
}

BOOST_AUTO_TEST_CASE(More) {
	FracNum a(2, 3), b(4, 5);
	bool result = 0;
	BOOST_CHECK_EQUAL(a > b, result);
	a = { 5,6 }, b = { 5,6 }, result = 0;
	BOOST_CHECK_EQUAL(a > b, result);
	a = { 4,5 }, b = { 2,3 }, result = 1;
	BOOST_CHECK_EQUAL(a > b, result);
}

BOOST_AUTO_TEST_CASE(MoE) {
	FracNum a(2, 3), b(4, 5);
	bool result = 0;
	BOOST_CHECK_EQUAL(a >= b, result);
	a = { 5,6 }, b = { 5,6 }, result = 1;
	BOOST_CHECK_EQUAL(a >= b, result);
	a = { 4,5 }, b = { 2,3 }, result = 1;
	BOOST_CHECK_EQUAL(a >= b, result);
}

BOOST_AUTO_TEST_CASE(Equal) {
	FracNum a(2, 3), b(4, 5);
	bool result = 0;
	BOOST_CHECK_EQUAL(a == b, result);
	a = { 5,6 }, b = { 5,6 }, result = 1;
	BOOST_CHECK_EQUAL(a == b, result);
	a = { 4,5 }, b = { 2,3 }, result = 0;
	BOOST_CHECK_EQUAL(a == b, result);
}

BOOST_AUTO_TEST_CASE(NEqual) {
	FracNum a(2, 3), b(4, 5);
	bool result = 1;
	BOOST_CHECK_EQUAL(a != b, result);
	a = { 5,6 }, b = { 5,6 }, result = 0;
	BOOST_CHECK_EQUAL(a != b, result);
	a = { 4,5 }, b = { 2,3 }, result = 1;
	BOOST_CHECK_EQUAL(a != b, result);
}

BOOST_AUTO_TEST_CASE(LoE) {
	FracNum a(2, 3), b(4, 5);
	bool result = 1;
	BOOST_CHECK_EQUAL(a <= b, result);
	a = { 5,6 }, b = { 5,6 }, result = 1;
	BOOST_CHECK_EQUAL(a <= b, result);
	a = { 4,5 }, b = { 2,3 }, result = 0;
	BOOST_CHECK_EQUAL(a <= b, result);
}

BOOST_AUTO_TEST_CASE(Less) {
	FracNum a(2, 3), b(4, 5);
	bool result = 1;
	BOOST_CHECK_EQUAL(a < b, result);
	a = { 5,6 }, b = { 5,6 }, result = 0;
	BOOST_CHECK_EQUAL(a < b, result);
	a = { 4,5 }, b = { 2,3 }, result = 0;
	BOOST_CHECK_EQUAL(a < b, result);
}

BOOST_AUTO_TEST_SUITE_END()
