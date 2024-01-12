#include "pch.h"
#include "CppUnitTest.h"
#include "../TestDrivenStack/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackTesting
{
	TEST_CLASS(StackTestClass)
	{
	public:
		Stack* testStack = new Stack();
		TEST_METHOD(CreateStack)
		{
			this->testStack = new Stack();
		}

		TEST_METHOD(PushToStack) {
			this->testStack->Push(0);
		}

		TEST_METHOD(PopFromStack) {
			this->testStack->Push(0);
			this->testStack->Pop();
		}

		TEST_METHOD(Stack_Is_Empty_When_First_Initialised) {
			Stack testStack;
			Assert::IsTrue(testStack.IsEmpty());
		}

		TEST_METHOD(Stack_Is_Not_Empty_After_Pushing_a_Value) {
			Stack testStack;
			testStack.Push(0);
			Assert::IsFalse(testStack.IsEmpty());
		}

		TEST_METHOD(Stack_Cant_Pop_When_Empty) {
			Stack testStack;
			try {
			testStack.Pop();
			}
			catch (StackUnderflowError err) {
				Assert::IsTrue(true);
				return;
			}
			Assert::IsTrue(false);
		}

		TEST_METHOD(Can_Peek_At_Top_Value_In_Stack) {
			int value = 0;
			this->testStack->Push(value);
			Assert::AreEqual(value, this->testStack->Peek());
		}

		TEST_METHOD(Push_Twice_Then_Pop_Twice_Should_Follow_LiFo) {
			int arbitraryNum1 = 50;
			int arbitraryNum2 = 100;

			this->testStack->Push(arbitraryNum1);
			this->testStack->Push(arbitraryNum2);

			Assert::AreEqual(arbitraryNum2, this->testStack->Pop());
			Assert::AreEqual(arbitraryNum1, this->testStack->Pop());
		}

		TEST_METHOD(Push_Once_And_Size_Should_Be_1) {
			Stack testStack;
			testStack.Push(100);
			Assert::AreEqual(1, testStack.GetTop());
		}

		TEST_METHOD(New_Stack_And_Size_Should_Be_1) {
			Stack testStack;
			Assert::AreEqual(0, testStack.GetTop());
		}

		TEST_METHOD(Top_Var_Gets_Bigger_When_Things_Are_Added_And_Smaller_When_Deleted) {
			Stack testStack;
			Assert::AreEqual(0, testStack.GetTop());

			int arbitraryNumber = 100;
			testStack.Push(arbitraryNumber);
			Assert::AreEqual(testStack.GetTop(), 1);

			testStack.Pop();
			Assert::AreEqual(0, testStack.GetTop());
		}
	};
}
