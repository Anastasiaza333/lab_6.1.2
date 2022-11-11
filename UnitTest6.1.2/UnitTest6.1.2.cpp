#include "pch.h"
#include "CppUnitTest.h"
#include "../Project6.1.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest612
{
	TEST_CLASS(UnitTest612)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{ 
			const int SIZE = 7;
			int b[7] = { -14, -12,-10,-8,-6,-4,-2 };
			int s = 0;
			int i = 0;
			s = sum(b,0,i,SIZE);
			Assert::AreEqual(s,-56);

		}
	};
}
