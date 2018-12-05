#include "Queue.h"
using namespace std;

template <class classtype>
Queue <classtype>::Queue()
{
	this->maxSizeOfQueue = 1000;
}

template <class classtype>
Queue <classtype>::Queue(int maxSize)
{
	this->maxSizeOfQueue = maxSize;
}

template <class classtype>
ITEM Queue <classtype>::AddItemToQueue(classtype item)
{
	if (isQueueFull() == QUEUE_IS_FULL)
		return ITEM_FAILED_TO_ADD;
	queueList.push_back(item);
	return ITEM_ADDED_TO_QUEUE;
}

 template <class classtype>
 classtype Queue <classtype>::GetItemFirstInQueue()
{
	 if (isQueueEmpty() == QUEUE_IS_EMPTY)
	 {
		 //if (!std::is_integral<classtype>::value)
		 //{
			// return nullptr;
		 //}
		 //else
			// return NULL;
		 throw underflow_error("Queue is Empty");
	 }
		 
	 classtype temp = queueList.front();
	 queueList.erase(queueList.begin());
	 return temp;
}

 template <class classtype>
 int Queue <classtype>::GetNumberOfItemsInQueue()
 {
	 return queueList.size();
 }


 template <class classtype>
 classtype Queue <classtype>::PeekAtFirstItemInQueue()
 {
	 return queueList.front();
 }

 template <class classtype>
 QUEUE Queue <classtype>::isQueueFull()
 {
	 if (queueList.size() < maxSizeOfQueue)
		 return QUEUE_HAS_SPACE;
	 return QUEUE_IS_FULL;
 }

 template <class classtype>
 QUEUE Queue <classtype>::isQueueEmpty()
 {
	 if (queueList.size() == 0)
		 return QUEUE_IS_EMPTY;
	 return QUEUE_IS_NOT_EMPTY;
 }

 template <class classtype>
 classtype Queue <classtype>::PeekAtLastItemInQueue()
 {
	 return queueList.back();
 }

template <class classtype>
Queue <classtype>::~Queue()
{
}
