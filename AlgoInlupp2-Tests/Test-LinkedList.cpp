#include "pch.h"
#include "gtest/gtest.h"
#include "..\AlgoInLupp2\LinkedList.h"

TEST(TestLinked, testingGetSize) {

    LinkedList<int> theList;
    theList.AddFirst(1);

    EXPECT_EQ(1,theList.GetSize());
}

TEST(TestLinked, testingRemove) {

	LinkedList<int> theList;
	theList.AddFirst(1);
	theList.AddFirst(2);
	theList.RemovePosition(0);

	EXPECT_EQ(1, theList.GetSize());
}

TEST(TestLinked, testingGetNode) {

	LinkedList<int> theList;
	theList.AddFirst(1);
	theList.AddFirst(2);
	theList.AddFirst(3);


	EXPECT_EQ(3, theList.GetNode(0));
}

TEST(TestLinked, testingAddLast) {

	LinkedList<int> theList;
	theList.AddFirst(1);
	theList.AddFirst(2);
	theList.AddFirst(3);
	theList.AddLast(10);


	EXPECT_EQ(10, theList.GetNode(3));
}

