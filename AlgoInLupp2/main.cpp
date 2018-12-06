#include <iostream>	
#include <Windows.h>
#include "Queue.h"
#include "Queue.cpp"
#include "Stack.h"
#include "DoubleLinkedList.h"
#include "LinkedList.h"
#include <iostream>
using namespace std; 



int main(int argc, char **argv)
{
    Stack<int> *stack = new Stack<int>();
    Stack<float> stackFloat;

    for(int i = 0; i < 10; i++)
    {
        stack->push(i);
    }
    
    cout << "size of Stack integer = " << stack->size() << endl;
    cout << "Stack Float = " << *stack << endl;
    
    if(stackFloat.empty())
        cout << "Stack Float is Empty" << endl;
    else 
        cout << "Stack Float is not Empty" << endl;

    for(int i = 0; i < 10; i++)
    {
        stackFloat.push(0.5f);
    }
    
    cout << "Stack Float = " << stackFloat << endl;    
    
    stackFloat.pop();
    cout << "Stack Float = " << stackFloat << endl;  
    cout << "Stack Float size = " << stackFloat.size() << endl;

    stack->invert();
    cout << "Stack integer = " << *stack << endl;  
    cout << "Stack integer size = " << stack->size() << endl;

    delete stack;
    return 0;
}


	while (true)
	{
		cout << endl;  system("pause");
	}
	return 0;
}
