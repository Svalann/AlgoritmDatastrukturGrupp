#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_
#include <iostream>
#include "Binode.h"

template<class T>
class DoublyLinkedList
{
    private:
        Binode<T> *_first, *_last;
        int _size;

    public:
        DoublyLinkedList() : _first(NULL), _last(NULL), _size(0) {};
        DoublyLinkedList(const DoublyLinkedList&);
        ~DoublyLinkedList() { Clear(); };
        void Clear();
        bool Empty() const { return _size == 0; };
        int GetSize() const { return _size; };
        void RemoveAtPosition(int index);        
        T GetAtPosition (int index);
        void InsertAtPosition(int index, T d);
        
        
};
