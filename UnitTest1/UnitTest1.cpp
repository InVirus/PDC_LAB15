#include "pch.h"
#include "CppUnitTest.h"
#include "../PDC_LAB15/Source.cpp"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestIsSafeSimplified)
        {
            n = 4;
            board = { 1, 3, -1, -1 };

            Assert::IsTrue(isSafe(2, 0), L"Функція isSafe повинна повернути true для (2, 0).");
            Assert::IsFalse(isSafe(2, 1), L"Функція isSafe повинна повернути false для (2, 1).");
            Assert::IsFalse(isSafe(2, 3), L"Функція isSafe повинна повернути false для (2, 3).");
        }

        TEST_METHOD(TestIsSafeForDifferentBoardSizes)
        {
            n = 8;
            board = { 0, 4, 7, 5, 2, 6, 1, -1 };

            Assert::IsTrue(isSafe(7, 3), L"Функція isSafe повинна повернути true для (7, 3).");
            Assert::IsFalse(isSafe(7, 1), L"Функція isSafe повинна повернути false для (7, 1).");
        }
    };
}
