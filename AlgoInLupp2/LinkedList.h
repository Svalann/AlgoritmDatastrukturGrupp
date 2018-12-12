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


template <class T>
void LinkedList <T>::AddFirst(T data)
{

    Node *temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
}


template <class T>
void LinkedList <T>::AddLast(T data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    if (head == nullptr)
    {
        head = temp;
        return;
    }
    Node *temp2 = new Node;
    temp2 = head;
    while (temp2->next != nullptr) {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}



template <class T>
void LinkedList <T> :: InsertPosition(T data, int index)    // FÅR INTE DENNA FUNKTION ATT FUNGERA
{
    Node *temp1 = new Node;
    temp1->data = data;
    temp1->next = nullptr;

    if (index == 0)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    Node *temp2 = head;

    for (int i = 0; i < index; i++)

    {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}



template <class T>
void LinkedList <T>::RemovePosition(int index)
{
    Node *temp1 = head;

    if (index == 0)

    {
        head = temp1->next;
        delete temp1;
        return;
    }

    int i;

    for (int i = 0; i < index - 2; i++)

    {
        temp1 = temp1->next;
    }

    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}



template <class T>
void LinkedList <T>::Print()
{
    Node *temp = head;

    while (temp != nullptr)

    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }

    std::cout << std::endl;
}

template <class T>
T LinkedList <T>::GetNode(int index)

{
    Node *current = head;
    int count{};
    while (current != nullptr)
    {
        if (count == index)
            return(current->data);
        count++;
        current = current->next;
    }
    assert(0);
}

template <class T>
int LinkedList <T>::GetSize()

{
    int count{};
    Node *temp = head;
    while (temp != nullptr)
    {
        ++count;
        temp = temp->next;
    }
    return count;
}




























