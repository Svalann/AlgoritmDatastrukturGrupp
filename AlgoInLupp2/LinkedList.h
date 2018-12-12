#pragma once

#include <iostream>
#include <sstream>
#include <assert.h>

template <typename T>
class LinkedList

{

private:
    struct Node
    {
        T data;
        Node *next;
    };

    Node *head;

public:

    LinkedList();

    void AddFirst(T data);

    void AddLast(T data);

    void InsertPosition(T data, int index; // DFENNA FUNKAR EJ, LÖS DET

    void RemovePosition(int index);

    void Print();

    T GetNode(int index);

    int GetSize();
 
};























