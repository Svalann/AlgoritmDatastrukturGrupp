#pragma once
#include <vector>
using namespace std;


typedef enum
{
	ITEM_SUCCESFULLY_ADDED,
	ITEM_FAILED_TO_ADD
}ITEM;


typedef enum
{
	QUEUE_IS_EMPTY,
	QUEUE_IS_NOT_EMPTY,
	QUEUE_IS_FULL,
	QUEUE_HAS_SPACE
}QUEUE;

template <class classtype>
class Queue
{
private:
	vector <classtype> queueList;
	int maxSizeOfQueue;
public:
	Queue()
	{
		this->maxSizeOfQueue = 1000;
	}

	Queue(int maxSize)
	{
		this->maxSizeOfQueue = maxSize;
	}

	ITEM AddItemToQueue(classtype item)
	{
		if (isQueueFull() == QUEUE_IS_FULL)
			return ITEM_FAILED_TO_ADD;
		queueList.push_back(item);
		return ITEM_SUCCESFULLY_ADDED;
	}

	classtype GetItemFirstInQueue()
	{
		if (isQueueEmpty() == QUEUE_IS_EMPTY)
			throw underflow_error("Queue is Empty");
		classtype temp = queueList.front();
		queueList.erase(queueList.begin());
		return temp;
	}

	int GetNumberOfItemsInQueue()
	{
		return queueList.size();
	}

	classtype PeekAtFirstItemInQueue()
	{
		return queueList.front();
	}

	QUEUE isQueueFull()
	{
		if (queueList.size() < maxSizeOfQueue)
			return QUEUE_HAS_SPACE;
		return QUEUE_IS_FULL;
	}

	QUEUE isQueueEmpty()
	{
		if (queueList.size() == 0)
			return QUEUE_IS_EMPTY;
		return QUEUE_IS_NOT_EMPTY;
	}

	classtype PeekAtLastItemInQueue()
	{
		return queueList.back();
	}

	~Queue()
	{
	}

};