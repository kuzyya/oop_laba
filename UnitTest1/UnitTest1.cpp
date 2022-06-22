#include "pch.h"
#include "CppUnitTest.h"
#include "../vector/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestAddition)
		{
			vector <int> A, B, C;
			for (int i = 0; i < 10; i++)
			{
				A.push_back(rand());
				B.push_back(rand());
				C.push_back(A[i] + B[i]);
			}
			mathVector v1(A);
			mathVector v2(B);
			mathVector expected(C);
			Assert::IsTrue(expected == (v1 + v2));
		}

		TEST_METHOD(TestSubtraction)
		{
			vector <int> A, B, C;
			for (int i = 0; i < 10; i++)
			{
				A.push_back(rand());
				B.push_back(rand());
				C.push_back(A[i] - B[i]);
			}
			mathVector v1(A);
			mathVector v2(B);
			mathVector expected(C);
			Assert::IsTrue(expected == (v1 - v2));
		}

		TEST_METHOD(TestMultbyScalar)
		{
			vector <int> A, B, C;
			for (int i = 0; i < 10; i++)
			{
				A.push_back(rand());
				C.push_back(A[i] * 2);
			}
			mathVector v1(A);
			mathVector expected(C);
			Assert::IsTrue(expected == (v1 * 2));
		}

		TEST_METHOD(TestDotProduct)
		{
			vector <int> A, B;
			int expected = 0;
			for (int i = 0; i < 10; i++)
			{
				A.push_back(rand());
				B.push_back(rand());
				expected += A[i] * B[i];
			}
			mathVector v1(A);
			mathVector v2(B);
			Assert::IsTrue(expected == (v1 * v2));
		}
	};
}
