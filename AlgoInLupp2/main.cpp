#include <iostream>	
#include <Windows.h>
#include "Queue.h"
#include "Stack.h"
#include "DoubleLinkedList.h"
#include "LinkedList.h"
#include <iostream>
using namespace std; 




void testStack(Stack<int> stack)
{
    cout << "Stack integer size = " << stack.size() << endl; 

    if(stack.empty())
        cout << "Stack integer is Empty" << endl;
    else 
        cout << "Stack integer is not Empty" << endl;

    for(int i = 0; i < 10; i++)
    {
        stack.push(i);
        cout << stack.top() << endl;
    }

    if(stack.empty())
        cout << "Stack integer is Empty" << endl;
    else 
        cout << "Stack integer is not Empty" << endl;

    cout << "Stack integer size = " << stack.size() << endl;
}


int main(int argc, char **argv)
{
    Stack<int> stack = Stack<int>();    

    testStack(stack);    
    return 0;
}

