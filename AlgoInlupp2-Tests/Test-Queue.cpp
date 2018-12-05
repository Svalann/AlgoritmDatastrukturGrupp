#include "gtest/gtest.h"
#include "..\AlgoInLupp2\Queue.h"

class QueueFixture : public testing::Test 
{
public:
	class TestClass
	{
	public:
		string SayHello()
		{
			return "Hello";
		}
	};

	Queue<int> intQueue;
	Queue<float> floatQueue;
	Queue<string> stringQueue;
	Queue<TestClass> classQueue;

	void SetUpInt()
	{
		intQueue.AddItemToQueue(10);
		intQueue.AddItemToQueue(2);
		intQueue.AddItemToQueue(-18);
		intQueue.AddItemToQueue(0);
	}

	void SetUpString()
	{
		stringQueue.AddItemToQueue("First");
		stringQueue.AddItemToQueue("Second");
		stringQueue.AddItemToQueue("Test");
		stringQueue.AddItemToQueue("Test2");
	}

	void SetUpFloat()
	{
		floatQueue.AddItemToQueue(1.0);
		floatQueue.AddItemToQueue(-201.34);
		floatQueue.AddItemToQueue(0.199);
		floatQueue.AddItemToQueue(3.14);
	}

	void SetUpClass()
	{
		TestClass nr1, nr2, nr3, nr4;
		classQueue.AddItemToQueue(nr1);
		classQueue.AddItemToQueue(nr2);
		classQueue.AddItemToQueue(nr3);
		classQueue.AddItemToQueue(nr4);
	}

};



TEST_F(QueueFixture, QueueCanHandleInts)
{
	SetUpInt();
	EXPECT_EQ(4, intQueue.GetNumberOfItemsInQueue());
}
TEST_F(QueueFixture, QueueCanHandleStrings)
{
	SetUpString();
	EXPECT_EQ(4, stringQueue.GetNumberOfItemsInQueue());
}
TEST_F(QueueFixture, QueueCanHandleFloats)
{
	SetUpFloat();
	EXPECT_EQ(4, floatQueue.GetNumberOfItemsInQueue());
}
TEST_F(QueueFixture, QueueCanHandleClasses)
{
	SetUpClass();
	EXPECT_EQ(4, classQueue.GetNumberOfItemsInQueue());
}

TEST_F(QueueFixture, IfOneItemIsAddedSizeOfQueueIsOneLarger)
{
	SetUpInt();
	intQueue.AddItemToQueue(12);

	EXPECT_EQ(5, intQueue.GetNumberOfItemsInQueue());
}


TEST_F(QueueFixture, IfItemIsAddedItsLastInQueue)
{
	SetUpString();
	stringQueue.AddItemToQueue("Last");
	EXPECT_EQ("Last", stringQueue.PeekAtLastItemInQueue());
}

TEST_F(QueueFixture, ItemRetrievedShouldBeTheFirstInQueue)
{
	SetUpString();
	string temp = stringQueue.GetItemFirstInQueue();
	EXPECT_EQ("First", temp);
}

TEST_F(QueueFixture, AfterItemIsRetrievedNextInQueueShouldBeFirst)
{
	SetUpString();
	stringQueue.GetItemFirstInQueue();
	string temp = stringQueue.PeekAtFirstItemInQueue();
	EXPECT_EQ("Second", temp);
}

TEST_F(QueueFixture, IfTwoItemsIsRetrievedFromQueueSizeShouldDecreaseTwo)
{
	SetUpInt();
	int temp1 = intQueue.GetItemFirstInQueue();
	int temp2 = intQueue.GetItemFirstInQueue();
	EXPECT_EQ(2, intQueue.GetNumberOfItemsInQueue());
}

TEST_F(QueueFixture, WhenAddingItemItShouldGet_ITEM_ADDED_TO_QUEUE)
{
	SetUpString();
	ITEM test = stringQueue.AddItemToQueue("Test");
	EXPECT_EQ(ITEM_ADDED_TO_QUEUE, test);
}

TEST_F(QueueFixture, IfQueueIsFullWhenAddingShouldReturn_ITEM_FAILED_TO_ADD)
{
	Queue <string> stringQueue(1);
	stringQueue.AddItemToQueue("Test");
	EXPECT_EQ(ITEM_FAILED_TO_ADD, stringQueue.AddItemToQueue("Test2"));
}

TEST_F(QueueFixture, IfQueueIsEmptyShouldReturn_QUEUE_IS_EMPTY)
{
	Queue <string> stringQueue(1);
	stringQueue.AddItemToQueue("Test");
	stringQueue.GetItemFirstInQueue();
	EXPECT_EQ(QUEUE_IS_EMPTY, stringQueue.isQueueEmpty());
}

TEST_F(QueueFixture, IfQueueHasItemsShouldReturn_QUEUE_IS_NOT_EMPTY)
{
	SetUpFloat();
	floatQueue.GetItemFirstInQueue();
	floatQueue.GetItemFirstInQueue();
	floatQueue.GetItemFirstInQueue();
	EXPECT_EQ(QUEUE_IS_NOT_EMPTY, floatQueue.isQueueEmpty());
}

TEST_F(QueueFixture, WhenGettingClassItShouldBeAbleToRetrieveFunctions)
{
	SetUpClass();
	string stringFromClass = classQueue.GetItemFirstInQueue().SayHello();
	EXPECT_EQ("Hello", stringFromClass);
}


TEST_F(QueueFixture, WhenTryingToGetItemFromEmptyListShouldThrowError)
{
	Queue <string> stringQueue(1);
	stringQueue.AddItemToQueue("Test");
	stringQueue.GetItemFirstInQueue();
	EXPECT_THROW(stringQueue.GetItemFirstInQueue(), std::underflow_error);
}
