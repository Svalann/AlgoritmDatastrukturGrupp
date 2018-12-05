#include "Queue.h"
using namespace std;

template <class classtype>
Queue <classtype>::Queue()
{
	
}

template <class classtype>
void Queue <classtype>::AddItemToQueue(classtype item)
{
	queueList.push_back(item);
}

 template <class classtype>
 classtype Queue <classtype>::GetItemFirstInQueue()
{
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
Queue <classtype>::~Queue()
{
}
