#include "pch.h"
#include "gtest/gtest.h"
#include "..\AlgoInLupp2\LinkedList.h"

TEST(TestLinked, TestGetSize) {


    LinkedList<int> theList;
    theList.AddFirst(1);
    EXPECT_EQ(1,theList.GetSize());
}//expect throw

//TEST(TestLinked, TestGetSize) {
//
//
//    LinkedList<int> theList;
//    theList.AddFirst(1);
//    EXPECT_EQ(1, theList.GetSize());
//}//expect throw
