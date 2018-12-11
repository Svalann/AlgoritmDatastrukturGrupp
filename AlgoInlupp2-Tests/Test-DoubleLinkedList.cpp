#include "gtest/gtest.h"
#include "..\AlgoInLupp2\DoubleLinkedList.h"



class DoubleLinkedListFixture : public testing::Test
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

	DoubleLinkedList<int> intList;
	DoubleLinkedList<float> floatList;
	DoubleLinkedList<std::string> stringList;
	DoubleLinkedList<TestClass> classList;

	void SetUpInt()
	{
		intList.AddItemLast(10);
		intList.AddItemLast(2);
		intList.AddItemLast(-18);
	}

	void SetUpString()
	{
		stringList.AddItemLast("Head");
		stringList.AddItemLast("Second");
		stringList.AddItemLast("Tail");
	}

	void SetUpFloat()
	{
		floatList.AddItemLast(1.0);
		floatList.AddItemLast(-201.34);
		floatList.AddItemLast(0.199);
	}

	void SetUpClass()
	{
		TestClass nr1, nr2, nr3;
		classList.AddItemLast(nr1);
		classList.AddItemLast(nr2);
		classList.AddItemLast(nr3);
	}

};

TEST_F(DoubleLinkedListFixture, HeadShouldBeTheFirstItemAddedWithAddItemLast) {
	SetUpInt();
	EXPECT_EQ(10, intList.GetFirstItem());
}

TEST_F(DoubleLinkedListFixture, TailShouldBeTheLastItemAddedWithAddItemLast) {
	SetUpInt();
	EXPECT_EQ(-18, intList.GetLastItem());
}

TEST_F(DoubleLinkedListFixture, WhenAddingItemAtPosition1ItsNextShouldPointToPrevious1) {
	SetUpString();
	stringList.AddItemBeforePosition("Before second", 1);
	EXPECT_EQ("Before second", stringList.GetItemAtPosition(1));
	EXPECT_EQ("Second", stringList.GetItemAtPosition(2));
	EXPECT_EQ("Head", stringList.GetFirstItem());
}

TEST_F(DoubleLinkedListFixture, WhenAddingItemWithAddItemBeforePositionSizeOfListShouldIncrease) {
	SetUpString();
	stringList.AddItemBeforePosition("New Head", 0);
	EXPECT_EQ(4, stringList.GetSizeOfList());
}

TEST_F(DoubleLinkedListFixture, WhenAddingItemAtHeadPositionItShouldBeNewHead) {
	SetUpString();
	stringList.AddItemBeforePosition("New Head", 0);
	EXPECT_EQ("New Head", stringList.GetItemAtPosition(0));
	EXPECT_EQ("New Head", stringList.GetFirstItem());
	EXPECT_EQ("Head", stringList.GetItemAtPosition(1));
}

TEST_F(DoubleLinkedListFixture, WhenAddingItemAtTailPositionItShouldBePreviousToTail) {
	SetUpString();
	stringList.AddItemBeforePosition("Before tail", 2);
	EXPECT_EQ("Tail", stringList.GetLastItem());
	EXPECT_EQ("Tail", stringList.GetItemAtPosition(3));
	EXPECT_EQ("Before tail", stringList.GetItemAtPosition(2));
}

TEST_F(DoubleLinkedListFixture, WhenUsingIntOperatorItemAtPositionIsReturned) {
	SetUpInt();
	int test = intList[2];
	EXPECT_EQ(-18, test);
}

TEST_F(DoubleLinkedListFixture, WhenUsingStringOperatorItemAtPositionIsReturned) {
	SetUpString();
	std::string test = stringList[0];
	EXPECT_EQ("Head", test);
}

TEST_F(DoubleLinkedListFixture, WhenUsingOperatorToReplaceValueAtPositionItShouldReturnTheNewValue) {
	SetUpString();
	stringList[0] = "New Head";
	EXPECT_EQ("New Head", stringList[0]);
}

TEST_F(DoubleLinkedListFixture, WhenUsingOperatorWithIntItsValuesCanBeAddedTogether) {
	SetUpInt();
	int test = intList[0] + intList[1];
	EXPECT_EQ(12, test);
}

TEST_F(DoubleLinkedListFixture, WhenUsingOperatorWithStringItsValuesCanBeAddedTogether) {
	SetUpString();
	std::string test = stringList[1] + stringList[2];
	EXPECT_EQ("SecondTail", test);
}

TEST_F(DoubleLinkedListFixture, WhenAddingLastToListSizeIncreases) {
	SetUpFloat();
	floatList.AddItemLast(3.122);
	EXPECT_EQ(4, floatList.GetSizeOfList());
}

TEST_F(DoubleLinkedListFixture, IfListIsEmptyReturnTrue) {

	EXPECT_EQ(true, classList.isListEmpty());
}

TEST_F(DoubleLinkedListFixture, IfListIsFullReturnTrue) {
	DoubleLinkedList<char> charList(1);
	charList.AddItemLast('c');
	EXPECT_EQ(true, charList.isListFull());
}

TEST_F(DoubleLinkedListFixture, WhenUsingDeleteFirstTheSizeOfListShouldDecrease) {
	SetUpClass();
	classList.DeleteFirst();
	EXPECT_EQ(2, classList.GetSizeOfList());
}

TEST_F(DoubleLinkedListFixture, WhenUsingDeleteLastTheSizeOfListShouldDecrease) {
	SetUpClass();
	classList.DeleteLast();
	EXPECT_EQ(2, classList.GetSizeOfList());
}

TEST_F(DoubleLinkedListFixture, WhenUsingDeletPositionTheSizeOfListShouldDecrease) {
	SetUpClass();
	classList.DeletePosition(1);
	EXPECT_EQ(2, classList.GetSizeOfList());
}

TEST_F(DoubleLinkedListFixture, WhenUsingDeletePositionOnHeadTheItemOnPositionOneIsNewHead) {
	SetUpString();
	stringList.DeletePosition(0);
	EXPECT_EQ("Second", stringList.GetFirstItem());
}

TEST_F(DoubleLinkedListFixture, WhenUsingDeletePositionOnTailThenItsPreviousShouldBeNewTail) {
	SetUpString();
	stringList.DeletePosition(2);
	EXPECT_EQ("Second", stringList.GetLastItem());
}

TEST_F(DoubleLinkedListFixture, WhenUsingDeleteFirstTheItemOnPositionOneIsNewHead) {
	SetUpString();
	stringList.DeleteFirst();
	EXPECT_EQ("Second", stringList.GetFirstItem());
}

TEST_F(DoubleLinkedListFixture, WhenUsingDeleteLastThenTheTailsPreviousShouldBeNewTail) {
	SetUpString();
	stringList.DeleteLast();
	EXPECT_EQ("Second", stringList.GetLastItem());
}

TEST_F(DoubleLinkedListFixture, IfAddingItemWithAddItemFirstIsSuccesfullItShouldReturn_ITEM_SUCCESFULLY_ADDED) {
	SetUpString();
	ITEM test = stringList.AddItemFirst("Tjo");
	EXPECT_EQ(ITEM_SUCCESFULLY_ADDED, test);
}

TEST_F(DoubleLinkedListFixture, IfAddingItemWithAddItemLastIsSuccesfullItShouldReturn_ITEM_SUCCESFULLY_ADDED) {
	SetUpString();
	ITEM test = stringList.AddItemLast("Tjo");
	EXPECT_EQ(ITEM_SUCCESFULLY_ADDED, test);
}

TEST_F(DoubleLinkedListFixture, IfAddingItemWitAddItemBeforePositionIsSuccesfullItShouldReturn_ITEM_SUCCESFULLY_ADDED) {
	SetUpString();
	ITEM test = stringList.AddItemBeforePosition("Tjo", 1);
	EXPECT_EQ(ITEM_SUCCESFULLY_ADDED, test);
}

TEST_F(DoubleLinkedListFixture, IfAddingItemWithAddItemFirstFailsItShouldReturn_ITEM_FAILED_TO_ADD) {
	DoubleLinkedList<char> charList(1);
	charList.AddItemLast('c');
	ITEM test = charList.AddItemFirst('f');
	EXPECT_EQ(ITEM_FAILED_TO_ADD, test);
}

TEST_F(DoubleLinkedListFixture, IfAddingItemWithAddItemLastFailsItShouldReturn_ITEM_FAILED_TO_ADD) {
	DoubleLinkedList<char> charList(1);
	charList.AddItemLast('c');
	ITEM test = charList.AddItemLast('f');
	EXPECT_EQ(ITEM_FAILED_TO_ADD, test);
}

TEST_F(DoubleLinkedListFixture, IfAddingItemWitAddItemBeforePositionFailsItShouldReturn_ITEM_FAILED_TO_ADD) {
	DoubleLinkedList<char> charList(1);
	charList.AddItemLast('c');
	ITEM test = charList.AddItemBeforePosition('f', 2);
	EXPECT_EQ(ITEM_FAILED_TO_ADD, test);
}