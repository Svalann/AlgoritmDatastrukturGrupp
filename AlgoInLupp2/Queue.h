#pragma once
#include <vector>
using namespace std;


typedef enum
{
	ITEM_ADDED_TO_QUEUE,
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
	Queue();
	Queue(int maxSize);
	ITEM AddItemToQueue(classtype item);
	classtype GetItemFirstInQueue();
	int GetNumberOfItemsInQueue();
	classtype PeekAtFirstItemInQueue();
	classtype PeekAtLastItemInQueue();
	QUEUE isQueueFull();
	QUEUE isQueueEmpty();
	~Queue();
};