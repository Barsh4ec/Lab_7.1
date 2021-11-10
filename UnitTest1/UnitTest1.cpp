#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int j = 2;
			int i = 2;
			int a[2][2] = { {2, -3}, {1, -1} };
			
			int k = 0;
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
					if (!(a[i][j] > 0 && i || j % 2 != 0))
						k++;
			}
			Assert::AreEqual(k, 1);
		}
	};
}