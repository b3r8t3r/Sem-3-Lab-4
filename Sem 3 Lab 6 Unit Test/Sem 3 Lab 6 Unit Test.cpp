#include "pch.h"
#include "CppUnitTest.h"
#include <FracNum.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Sem3Lab6UnitTest
{
	TEST_CLASS(FracNum_Arithmetic_Operator_Overload)
	{
	public:
		
		TEST_METHOD(Sum)
		{
				FracNum a(2, 3), b(4, 5), sum(22, 15);
				Assert::IsTrue(a + b == sum);
				a = { -15,1 }, sum = { -71,5 };
				Assert::IsTrue(a + b == sum);
				a = { 0,5 };
				Assert::IsTrue(a + b == b);

				int x = 5;
				a = { 2,3 }, sum = { 17,3 };
				Assert::IsTrue(a + x == sum);
				a = { -15,1 }, sum = { -10,1 };
				Assert::IsTrue(a + x == sum);
				a = { 0,5 }, sum = { 5,1 };
				Assert::IsTrue(a + x == sum);
		}

		TEST_METHOD(Sub) {
			FracNum a(2, 3), b(4, 5), sub(-2, 15);
			Assert::IsTrue(a - b == sub);
			a = { -7, 9 }, sub = { -71,45 };
			Assert::IsTrue(a - b == sub);
			a = { 0, 2 }, sub = { -4,5 };
			Assert::IsTrue(a - b == sub);

			int x = 5;
			a = { 2, 3 }, sub = { -13,3 };
			Assert::IsTrue(a - x == sub);
			a = { -7, 9 }, sub = { -52,9 };
			Assert::IsTrue(a - x == sub);
			a = { 0, 2 }, sub = { -5,1 };
			Assert::IsTrue(a - x == sub);
		}

		TEST_METHOD(Mul) {
			FracNum a(2, 3), b(4, 5), mul(8, 15);
			Assert::IsTrue(a * b == mul);
			a = { -7, 9 }, mul = { -28,45 };
			Assert::IsTrue(a * b == mul);
			a = { 0, 2 }, mul = { 0,1 };
			Assert::IsTrue(a * b == mul);

			int x = 5;
			a = { 2,3 }, mul = { 10, 3 };
			Assert::IsTrue(a * x == mul);
			a = { -7, 9 }, mul = { -35,9 };
			Assert::IsTrue(a * x == mul);
			a = { 0, 2 }, mul = { 0,1 };
			Assert::IsTrue(a * x == mul);
		}

		TEST_METHOD(Div) {
			FracNum a(2, 3), b(4, 5), div(5, 6);
			Assert::IsTrue(a / b == div);
			a = { 7, 9 }, div = { 35,36 };
			Assert::IsTrue(a / b == div);
			a = { 0, 2 }, div = { 0,1 };
			Assert::IsTrue(a / b == div);

			int x = 5;
			a = { 2,3 }, div = { 2,15 };
			Assert::IsTrue(a / x == div);
			a = { 7, 9 }, div = { 7,45 };
			Assert::IsTrue(a / x == div);
			a = { 0, 2 }, div = { 0,1 };
			Assert::IsTrue(a / x == div);
		}
		TEST_METHOD(Pow) {
			int x = 2;
			FracNum a(2, 3), power(4, 9);
			Assert::IsTrue((a ^ x) == power);
			a = { -7, 9 }, power = { 49,81 };
			Assert::IsTrue((a ^ x) == power);
			a = { 0, 2 }, power = { 0,1 };
			Assert::IsTrue((a ^ x) == power);

			x = -1;
			a = { 3, 11 }, power = { 11,3 };
			Assert::IsTrue((a ^ x) == power);

			x = 0;
			a = { 3, 11 }, power = { 1,1 };
			Assert::IsTrue((a ^ x) == power);
		}
	};

	TEST_CLASS(FracNum_Logical_Operator_Overload) {
		TEST_METHOD(More) {
			FracNum a(2, 3), b(4, 5);
			bool result = 0;
			Assert::IsTrue((a > b) == result);
			a = { 5,6 }, b = { 5,6 }, result = 0;
			Assert::IsTrue((a > b) == result);
			a = { 4,5 }, b = { 2,3 }, result = 1;
			Assert::IsTrue((a > b) == result);
		}
		TEST_METHOD(MoE) {
			FracNum a(2, 3), b(4, 5);
			bool result = 0;
			Assert::IsTrue((a >= b) == result);
			a = { 5,6 }, b = { 5,6 }, result = 1;
			Assert::IsTrue((a >= b) == result);
			a = { 4,5 }, b = { 2,3 }, result = 1;
			Assert::IsTrue((a >= b) == result);
		}
		TEST_METHOD(Equal) {
			FracNum a(2, 3), b(4, 5);
			bool result = 0;
			Assert::IsTrue((a == b) == result);
			a = { 5,6 }, b = { 5,6 }, result = 1;
			Assert::IsTrue((a == b) == result);
			a = { 4,5 }, b = { 2,3 }, result = 0;
			Assert::IsTrue((a == b) == result);
		}
		TEST_METHOD(NEqual) {
			FracNum a(2, 3), b(4, 5);
			bool result = 1;
			Assert::IsTrue((a != b) == result);
			a = { 5,6 }, b = { 5,6 }, result = 0;
			Assert::IsTrue((a != b) == result);
			a = { 4,5 }, b = { 2,3 }, result = 1;
			Assert::IsTrue((a != b) == result);
		}
		TEST_METHOD(LoE) {
			FracNum a(2, 3), b(4, 5);
			bool result = 1;
			Assert::IsTrue((a <= b) == result);
			a = { 5,6 }, b = { 5,6 }, result = 1;
			Assert::IsTrue((a <= b) == result);
			a = { 4,5 }, b = { 2,3 }, result = 0;
			Assert::IsTrue((a <= b) == result);
		}
		TEST_METHOD(Less) {
			FracNum a(2, 3), b(4, 5);
			bool result = 1;
			Assert::IsTrue((a < b) == result);
			a = { 5,6 }, b = { 5,6 }, result = 0;
			Assert::IsTrue((a < b) == result);
			a = { 4,5 }, b = { 2,3 }, result = 0;
			Assert::IsTrue((a < b) == result);
		}
	};
}
