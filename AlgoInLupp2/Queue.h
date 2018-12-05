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
	void AddToQueue();
	classtype GetFirstInQueue();
	int GetNumberOfItemsInQueue();
	~Queue();
};

