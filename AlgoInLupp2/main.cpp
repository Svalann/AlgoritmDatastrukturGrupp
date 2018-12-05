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
	Queue<string> test;
	test.AddItemToQueue("10");
	test.AddItemToQueue("3");
	int l = test.GetNumberOfItemsInQueue();
	cout << l << endl;
	string s = test.GetItemFirstInQueue();
	cout << s << endl;
	s = test.GetItemFirstInQueue();
	cout << s << endl;
	s = test.GetItemFirstInQueue();
	l = test.GetNumberOfItemsInQueue();
	cout << l << endl;
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