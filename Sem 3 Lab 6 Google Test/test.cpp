#include "pch.h"
#include "..\Sem 3 Lab 4\FracNum.h"

TEST(FracNum_Operator_Overload, Sum) {
	FracNum a(2,3), b(4,5), sum(22,15);
	EXPECT_EQ(a + b, sum);
	a = { -15,1 }, sum = {-71,5};
	EXPECT_EQ(a + b, sum);
	a = { 0,5 };
	EXPECT_EQ(a + b, b);
	
	int x = 5;

	a = { 2,3 }, sum = {17,3};
	EXPECT_EQ(a + x, sum);
	a = { -15,1 }, sum = { -10,1 };
	EXPECT_EQ(a + x, sum);
	a = { 0,5 }, sum = {5,1};
	EXPECT_EQ(a + x, sum);
}

TEST(FracNum_Operator_Overload, Sub) {
	FracNum a(2, 3), b(4, 5), sub(-2,15);
	EXPECT_EQ(a - b, sub);
	a = { -7, 9 }, sub = { -71,45 };
	EXPECT_EQ(a - b, sub);
	a = { 0, 2 }, sub = {-4,5};
	EXPECT_EQ(a - b, sub);

	int x = 5;
	a = { 2, 3 }, sub = {-13,3};
	EXPECT_EQ(a - x, sub);
	a = { -7, 9 }, sub = { -52,9 };
	EXPECT_EQ(a - x, sub);
	a = { 0, 2 }, sub = { -5,1 };
	EXPECT_EQ(a - x, sub);
}

TEST(FracNum_Operator_Overload, Mul) {
	FracNum a(2, 3), b(4, 5), mul(8, 15);
	EXPECT_EQ(a * b, mul);
	a = { -7, 9 }, mul = { -28,45 };
	EXPECT_EQ(a * b, mul);
	a = { 0, 2 }, mul = { 0,1 };
	EXPECT_EQ(a * b, mul);

	int x = 5;
	a = { 2,3 }, mul = { 10, 3 };
	EXPECT_EQ(a * x, mul);
	a = { -7, 9 }, mul = { -35,9 };
	EXPECT_EQ(a * x, mul);
	a = { 0, 2 }, mul = { 0,1 };
	EXPECT_EQ(a * x, mul);

}

TEST(FracNum_Operator_Overload, Div) {
	FracNum a(2, 3), b(4, 5), div(5, 6);
	EXPECT_EQ(a / b, div);
	a = { 7, 9 }, div = { 35,36 };
	EXPECT_EQ(a / b, div);
	a = { 0, 2 }, div = { 0,1 };
	EXPECT_EQ(a / b, div);

	int x = 5;
	a = { 2,3 }, div = { 2,15 };
	EXPECT_EQ(a / x, div);
	a = { 7, 9 }, div = { 7,45 };
	EXPECT_EQ(a / x, div);
	a = { 0, 2 }, div = { 0,1 };
	EXPECT_EQ(a / x, div);
}

TEST(FracNum_Operator_Overload, Pow) {
	FracNum a(2, 3), power(8, 15);
	int x = 2;
	a = { 2,3 }, power = { 4,9 };
	EXPECT_EQ(a ^ x, power);
	a = { -7, 9 }, power = { 49,81 };
	EXPECT_EQ(a ^ x, power);
	a = { 0, 2 }, power = { 0,1 };
	EXPECT_EQ(a ^ x, power);

	x = -1;
	a = { 3, 11 }, power = { 11,3 };
	EXPECT_EQ(a ^ x, power);
	
	x = 0;
	a = { 3, 11 }, power = { 1,1 };
	EXPECT_EQ(a ^ x, power);
}

TEST(FracNum_Operator_Overload, More) {
	FracNum a(2, 3), b(4, 5);
	bool result = 0;
	ASSERT_EQ(result, a>b);
	a = {5,6}, b = {5,6}, result = 0;
	ASSERT_EQ(result, a > b);
	a = { 4,5 }, b = { 2,3 }, result = 1;
	ASSERT_EQ(result, a > b);
}

TEST(FracNum_Operator_Overload, MoE) {
	FracNum a(2, 3), b(4, 5);
	bool result = 0;
	ASSERT_EQ(result, a >= b);
	a = { 5,6 }, b = { 5,6 }, result = 1;
	ASSERT_EQ(result, a >= b);
	a = { 4,5 }, b = { 2,3 }, result = 1;
	ASSERT_EQ(result, a >= b);
}

TEST(FracNum_Operator_Overload, Equal) {
	FracNum a(2, 3), b(4, 5);
	bool result = 0;
	ASSERT_EQ(result, a == b);
	a = { 5,6 }, b = { 5,6 }, result = 1;
	ASSERT_EQ(result, a == b);
	a = { 4,5 }, b = { 2,3 }, result = 0;
	ASSERT_EQ(result, a == b);
}

TEST(FracNum_Operator_Overload, NEqual) {
	FracNum a(2, 3), b(4, 5);
	bool result = 1;
	ASSERT_EQ(result, a != b);
	a = { 5,6 }, b = { 5,6 }, result = 0;
	ASSERT_EQ(result, a != b);
	a = { 4,5 }, b = { 2,3 }, result = 1;
	ASSERT_EQ(result, a != b);
}

TEST(FracNum_Operator_Overload, LoE) {
	FracNum a(2, 3), b(4, 5);
	bool result = 1;
	ASSERT_EQ(result, a <= b);
	a = { 5,6 }, b = { 5,6 }, result = 1;
	ASSERT_EQ(result, a <= b);
	a = { 4,5 }, b = { 2,3 }, result = 0;
	ASSERT_EQ(result, a <= b);
}

TEST(FracNum_Operator_Overload, Less) {
	FracNum a(2, 3), b(4, 5);
	bool result = 1;
	ASSERT_EQ(result, a < b);
	a = { 5,6 }, b = { 5,6 }, result = 0;
	ASSERT_EQ(result, a < b);
	a = { 4,5 }, b = { 2,3 }, result = 0;
	ASSERT_EQ(result, a < b);
}