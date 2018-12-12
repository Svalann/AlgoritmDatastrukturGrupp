#include "pch.h"
#include "gtest/gtest.h"
#include "..\AlgoInLupp2\Stack.h"

TEST(TestStack, When2ItemsIsPushedSizehouldBe2) {
	Stack<int> intStack;
	intStack.push(12);
	intStack.push(1);

	EXPECT_EQ(2, intStack.size());
}
