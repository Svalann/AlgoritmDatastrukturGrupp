#pragma once
#include "DoubleLinkedList.h"
using namespace std;

typedef enum
{
	QUEUE_IS_EMPTY,
	QUEUE_IS_NOT_EMPTY,
	QUEUE_IS_FULL,
	QUEUE_HAS_SPACE
}QUEUE;

template <class itemType>
class Queue
{
private:
	DoubleLinkedList <itemType> queueList;

public:
	Queue()
	{
	}

	Queue(int maxSize)
	{
		queueList.SetMaxSizeOfItemsInList(maxSize);
	}

	ITEM AddItemToQueue(itemType item)
	{
		if (isQueueFull() == QUEUE_IS_FULL)
			return ITEM_FAILED_TO_ADD;
		queueList.AddItemLast(item);
		return ITEM_SUCCESFULLY_ADDED;
	}

	itemType GetItemFirstInQueue()
	{
		if (isQueueEmpty() == QUEUE_IS_EMPTY)
			throw underflow_error("Queue is Empty");
		itemType temp = queueList.GetFirstItem();
		queueList.DeleteFirst();
		return temp;
	}

	int GetNumberOfItemsInQueue()
	{
		return queueList.GetSizeOfList();
	}



	QUEUE isQueueFull()
	{
		if (queueList.isListFull())
			return QUEUE_IS_FULL;
		return QUEUE_HAS_SPACE;
	}

	QUEUE isQueueEmpty()
	{
		if (queueList.isListEmpty())
			return QUEUE_IS_EMPTY;
		return QUEUE_IS_NOT_EMPTY;
	}

	itemType PeekAtFirstItemInQueue()
	{
		return queueList.GetFirstItem();
	}

	itemType PeekAtLastItemInQueue()
	{
		return queueList.GetLastItem();
	}

	~Queue()
	{
	}
};