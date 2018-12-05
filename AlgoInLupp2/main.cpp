#include <iostream>	
#include <string>
#include <sstream>
#include <vector> 
#include <algorithm>
#include <Windows.h>
#include "Queue.h"
#include "Queue.cpp"
#include "Stack.h"
#include "DoubleLinkedList.h"
#include "LinkedList.h"

using namespace std; 

void TestQueue()
{
	Queue<int> test;
	test.AddItemToQueue(2);
	test.AddItemToQueue(1);
	test.AddItemToQueue(16);
	test.GetItemFirstInQueue();
	cout << test.GetNumberOfItemsInQueue();
}

int main()
{
	while (true)
	{
		TestQueue();
		cout << endl;  system("pause");
	}
	return 0;
}