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

template<class T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList &_in)
{
    Binode<T> *_inIterator =_in._first;
    Binode<T> *prevIterator = NULL;
    Binode<T> *add = NULL;
    this->_first = NULL;
    this->_size =_in._size;

    while(_inIterator)
    {
        add = new Binode<T>(_inIterator->getKey());
        if (this->_first)
        {
            add->setPrev(prevIterator);
            prevIterator->setNext(add);
        }
        else
            this->_first = add;

        prevIterator = add;
        _inIterator = _inIterator->getNext();
    }
    this->_last = add;
}

template<class T>
void DoubleLinkedList<T>::InsertAtPosition(int index, T data)
{
    if (index < 1 || index > this->_size + 2)
        throw "Index Invalid";
    else
