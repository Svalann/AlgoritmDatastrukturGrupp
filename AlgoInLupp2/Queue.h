#pragma once
#include <vector>
using namespace std;


template <class classtype>
class Queue
{
private:
	vector <classtype> queueList;
public:
	Queue();
	void AddItemToQueue(classtype item);
	classtype GetItemFirstInQueue();
	int GetNumberOfItemsInQueue();
	~Queue();
};



