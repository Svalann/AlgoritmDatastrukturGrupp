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
    {
        Binode<T> *newNode, *current, *next;
        newNode = new Binode<T>(data);
        
        if (this->Empty())
        {
            this->_first = newNode;
            this->_last = newNode;
        }
        else if (index == 1)
        {
            newNode->setNext(this->_first);
            this->_first->setPrev(newNode);
            this->_first = newNode;
        }
        else if (index == this->GetSize() + 1)
        {
            this->_last->setNext(newNode);
            newNode->setPrev(this->_last);
            this->_last = newNode;
        }
        else
        {
            current = this->_first;
            next = current->getNext();
            for (int i = 2; i < index; i++)
            {
                current = next;
                next = next->getNext();
            }
            current->setNext(newNode);
            newNode->setPrev(current);
            newNode->setNext(next);
        }
        this->_size++;
    }
}

template<class T>
void DoubleLinkedList<T>::RemoveAtPosition(int index)
{
    if (Empty())
        throw "Empty list";
    else if (index < 1 || index > this->_size + 1)
        throw "Index out of bounds";
    else
    {
        Binode<T> *aux;
        if (index == 1)
        {
            aux = this->_first;
            this->_first = aux->getNext();
            this->_first->setPrev(NULL);
        }
        else if (index == this->_size)
        {
            aux = this->_last;
            this->_last = aux->getPrev();
            this->_last->setNext(NULL);
        }
        else
        {
            Binode<T> *pivot = this->_first;
            for (int i = 1; i < index; i++)
                pivot = pivot->getNext();
            
            aux = pivot;
            aux->getNext()->setPrev(aux->getPrev());
            aux->getPrev()->setNext(aux->getNext());
        }
        delete aux;
        this->_size--;
    }
}

template<class T>
T DoubleLinkedList<T>::GetAtPosition(int pos)
{
    if (pos < 1 || pos > this->_size + 1)
        throw "Index Invalid";
    else
    {
        if (pos == 1)
            return _first->getKey();
        else if (pos == this->_size)
            return _last->getKey();
        else
        {
            Binode<T> *current = _first;
            for (int i = 1; i < pos; i++)
                current = current->getNext();
            return current->getKey();
        }
    }
}

template<class T>
void DoubleLinkedList<T>::Clear()
{
    Binode<T> *pivot = this->_first;
    Binode<T> *aux;
    while (pivot)
    {
        aux = pivot;
        pivot = pivot->getNext();
        delete aux;
    }
    this->_first = NULL;
    this->_last = NULL;
    this->_size = 0;
}

#endif


