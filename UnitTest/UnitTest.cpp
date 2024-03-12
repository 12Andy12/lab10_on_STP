#include "pch.h"
#include "CppUnitTest.h"
#include "../ModernCodingPolinom/Polinom.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestGetMaxDegree)
		{
			Polinom a;
			a.add(Member(1, 0));
			a.add(Member(2, 1));
			int res = a.getMaxDegree();
			int expected = 1;
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(TestGetCooef)
		{
			Polinom a;
			a.add(Member(1, 0));
			a.add(Member(2, 1));
			int res = a.getCooef(1);
			int expected = 2;
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(TestGetElement)
		{
			Polinom a;
			a.add(Member(1, 0));
			a.add(Member(2, 1));
			Member res = a.getElement(1);
			int expected1 = 2;
			int expected2 = 1;
			Assert::AreEqual(expected1, res.getCooef());
			Assert::AreEqual(expected2, res.getDegree());
		}

		TEST_METHOD(TestGetData)
		{
			Polinom a;
			a.add(Member(1, 0));
			a.add(Member(2, 1));
			string res = to_string(a);
			string expected = "1 + 2x";
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(TestClear)
		{
			Polinom a;
			a.add(Member(1, 0));
			a.add(Member(2, 1));
			a.clear();
			string res = to_string(a);
			string expected = "";
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(TestAdd)
		{
			Polinom a(4, 1);
			a.add(Member(5, 2));
			a.add(Member(3, 0));
			Polinom b(1, 0);
			b.add(Member(2, 1));

			Polinom c;
			c = a + b;
			string res = to_string(c);
			string expected = "4 + 6x + 5x^2";
			Assert::AreEqual(expected, res);
		}


		TEST_METHOD(TestDif)
		{
			Polinom a(4, 1);
			a.add(Member(5, 2));
			a.add(Member(3, 0));
			Polinom b(1, 0);
			b.add(Member(2, 1));

			Polinom c;
			c = a - b;
			string res = to_string(c);
			string expected = "2 + 2x + 5x^2";
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(TestMul)
		{
			Polinom a(4, 1);
			a.add(Member(5, 2));
			a.add(Member(3, 0));
			Polinom b(1, 0);
			b.add(Member(2, 1));

			Polinom c;
			c = a * b;
			string res = to_string(c);
			string expected = "3 + 10x + 13x^2 + 10x^3";
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(TestDiff)
		{
			Polinom a(4, 1);
			a.add(Member(5, 2));
			a.add(Member(3, 0));

			Polinom c;
			c = a.diff();
			string res = to_string(c);
			string expected = "4 + 10x";
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(TestCalc)
		{
			Polinom a(4, 1);
			a.add(Member(5, 2));
			a.add(Member(3, 0));

		
			double res = a.calc(2);
			double expected = 3 + 8 + 20;
			Assert::AreEqual(expected, res);
		}
	};
}
