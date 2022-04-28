#include "pch.h"
#include "CppUnitTest.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "../Lab4.4/Lab4.4.cpp"
#pragma warning(disable : 4996)



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab44
{
	TEST_CLASS(UnitTestLab44)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			char f[6] = "f.dat";
			int t = addToFileC(f, 5, 4, 3, 4);
			Assert::AreEqual(0, t);
		}
	};
}
