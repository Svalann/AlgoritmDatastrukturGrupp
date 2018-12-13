#include <iostream>	
#include <Windows.h>
#include "Queue.h"
#include "Stack.h"
#include "DoubleLinkedList.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

void Test(DoubleLinkedList<int> doublelinkedlist)
{
    Stack<int> stack = Stack<int>();

    if(stack.empty())
        cout << "Stack integer is Empty" << endl;
    else 
        cout << "Stack integer is not Empty" << endl;

    if(doublelinkedlist.Empty())
        cout << "doublelinkedlist integer is Empty" << endl;
    else 
        cout << "doublelinkedlist integer is not Empty" << endl;
        
    cout << "\nthe stack is filled with 10 integers" << endl;
    for(int i = 0; i < 10; i++)
    {
        stack.push(i);
    }

    cout << "\nStack is Copied in DoubleLinkedList" << endl;
    cout << "Stack integer size = " << stack.size() << endl;    
    cout << "DoubleLinkedList integer size = " << doublelinkedlist.GetSize() << endl;
    cout << "DoubleLinkedList integer = ";
    for (int i = 1; i <= 10; i++)
    {
        doublelinkedlist.InsertAtPosition(i, stack.top());
        cout << doublelinkedlist.GetAtPosition(i) << "->";
        stack.pop();
    }

    doublelinkedlist.RemoveAtPosition(5);

    cout << "\nDoubleLinkedList remove position 5" << endl;
    cout << "DoubleLinkedList integer = ";
    for (int i = 1; i <= doublelinkedlist.GetSize(); i++)
    {
        cout << doublelinkedlist.GetAtPosition(i) << "->";
    }

    if(doublelinkedlist.Empty())
        cout << "\nDoubleLinkedList integer is Empty" << endl;
    else 
        cout << "\nDoubleLinkedList integer is not Empty" << endl;
    
    cout << "DoubleLinkedList integer size = " << doublelinkedlist.GetSize() << endl;
    cout << "A END process" << endl;
}

int main(int argc, char **argv)
{
    DoubleLinkedList<int> list;

    Test(list);

    return 0;
}

