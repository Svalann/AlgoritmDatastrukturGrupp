#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_
#include <iostream>
#include "Binode.h"

template<class T>
class DoubleLinkedList
{
    private:
        Binode<T> *_first, *_last;
        int _size;

    public:
        DoubleLinkedList() : _first(NULL), _last(NULL), _size(0) {};
        DoubleLinkedList(const DoubleLinkedList&);
        ~DoubleLinkedList() { Clear(); };
        void Clear();
        bool Empty() const { return _size == 0; };
        int GetSize() const { return _size; };
        void RemoveAtPosition(int index);        
        T GetAtPosition (int index);
        void InsertAtPosition(int index, T d);
        
        
};
