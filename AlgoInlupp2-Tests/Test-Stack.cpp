#include "pch.h"
#include "gtest/gtest.h"
#include "..\AlgoInLupp2\Stack.h"

class StackFixture : public testing::Test
{
public:
	class TestClass
	{
	public:
		std::string SayHello()
		{
			return "Hello";
		}
	};

	Stack<int> intStack;
	Stack<float> floatStack;
	Stack<std::string> stringStack;
	Stack<TestClass> classStack;

	void SetUpInt()
	{
		intStack.AddItemToStack(10);
		intStack.AddItemToStack(2);
		intStack.AddItemToStack(-18);
		intStack.AddItemToStack(0);
	}

	void SetUpString()
	{
		stringStack.AddItemToStack("First added, last in stack");
		stringStack.AddItemToStack("Second added, third in stack");
		stringStack.AddItemToStack("Third added, second in stack");
		stringStack.AddItemToStack("Last added, first in stack");
	}

	void SetUpFloat()
	{
		floatStack.AddItemToStack(1.0);
		floatStack.AddItemToStack(-201.34);
		floatStack.AddItemToStack(0.199);
		floatStack.AddItemToStack(3.14);
	}

	void SetUpClass()
	{
		TestClass nr1, nr2, nr3, nr4;
		classStack.AddItemToStack(nr1);
		classStack.AddItemToStack(nr2);
		classStack.AddItemToStack(nr3);
		classStack.AddItemToStack(nr4);
	}

};



TEST_F(StackFixture, StackCanHandleInts)
{
	SetUpInt();
	EXPECT_EQ(4, intStack.GetNumberOfItemsInStack());
}
TEST_F(StackFixture, StackCanHandleStrings)
{
	SetUpString();
	EXPECT_EQ(4, stringStack.GetNumberOfItemsInStack());
}
TEST_F(StackFixture, StackCanHandleFloats)
{
	SetUpFloat();
	EXPECT_EQ(4, floatStack.GetNumberOfItemsInStack());
}
TEST_F(StackFixture, StackCanHandleClasses)
{
	SetUpClass();
	EXPECT_EQ(4, classStack.GetNumberOfItemsInStack());
}

TEST_F(StackFixture, IfOneItemIsAddedSizeOfStackIsOneLarger)
{
	SetUpInt();
	intStack.AddItemToStack(12);

	EXPECT_EQ(5, intStack.GetNumberOfItemsInStack());
}

TEST_F(StackFixture, ItemRetrievedShouldBeLastAddedInStack)
{
	SetUpString();
	std::string temp = stringStack.GetItemFromStack();
	EXPECT_EQ("Last added, first in stack", temp);
}

TEST_F(StackFixture, AfterItemIsRetrievedNextInStackShouldBeFirst)
{
	SetUpString();
	stringStack.GetItemFromStack();
	std::string temp = stringStack.PeekAtFirstItemInStack();
	EXPECT_EQ("Third added, second in stack", temp);
}

TEST_F(StackFixture, IfTwoItemsIsRetrievedFromStackSizeShouldDecreaseTwo)
{
	SetUpInt();
	int temp1 = intStack.GetItemFromStack();
	int temp2 = intStack.GetItemFromStack();
	EXPECT_EQ(2, intStack.GetNumberOfItemsInStack());
}

TEST_F(StackFixture, WhenAddingItemItShouldGet_ITEM_SUCCESFULLY_ADDED)
{
	SetUpString();
	ITEM test = stringStack.AddItemToStack("Test");
	EXPECT_EQ(ITEM_SUCCESFULLY_ADDED, test);
}

TEST_F(StackFixture, IfStackIsFullWhenAddingShouldReturn_ITEM_FAILED_TO_ADD)
{
	Stack <std::string> stringStack(1);
	stringStack.AddItemToStack("Test");
	EXPECT_EQ(ITEM_FAILED_TO_ADD, stringStack.AddItemToStack("Test2"));
}

TEST_F(StackFixture, IfStackIsEmptyShouldReturnTrue)
{
	Stack <std::string> stringStack(1);
	stringStack.AddItemToStack("Test");
	stringStack.GetItemFromStack();
	EXPECT_EQ(true, stringStack.isStackEmpty());
}

TEST_F(StackFixture, IfStackHasItemsShouldReturn_false)
{
	SetUpFloat();
	floatStack.GetItemFromStack();
	floatStack.GetItemFromStack();
	floatStack.GetItemFromStack();
	EXPECT_EQ(false, floatStack.isStackEmpty());
}

TEST_F(StackFixture, WhenGettingClassItShouldBeAbleToRetrieveFunctions)
{
	SetUpClass();
	std::string stringFromClass = classStack.GetItemFromStack().SayHello();
	EXPECT_EQ("Hello", stringFromClass);
}

TEST_F(StackFixture, WhenTryingToGetItemFromEmptyListShouldThrowError)
{
	Stack <std::string> stringStack(1);
	stringStack.AddItemToStack("Test");
	stringStack.GetItemFromStack();
	EXPECT_THROW(stringStack.GetItemFromStack(), std::underflow_error);
}

