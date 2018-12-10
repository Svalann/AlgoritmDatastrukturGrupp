#pragma once
#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_
#include <iostream>
#include "Binode.h" // Create new Binode header file

template<class T>
class DoubleLinkedList
{
    private:
        Binode<T> *_first, *_last;
        int _size;

    public:
        DoubleLinkedList() : _first(NULL), _last(NULL), _size(0) {};
        DoubleLinkedList(const DoubleLinkedList&);
        ~DoubleLinkedList() { clear(); };

        bool empty() const { return _size == 0; };
        int size() const { return _size; };
        bool sorted() const;
        T front() const;
        T back() const;

        void pushFront(T);
        void pushBack(T);
        void popFront();
        void popBack();
        void erase(int);
        void change(T, int);
        void clear();
        void invert();
        void sort();
        void bubblesort();
        void quicksort();
	
	void operator=(const DoubleLinkedList &);
        bool operator>(const DoubleLinkedList &) const;
        bool operator<(const DoubleLinkedList &) const;
        bool operator==(const DoubleLinkedList &) const;
        bool operator>=(const DoubleLinkedList &) const;
        bool operator<=(const DoubleLinkedList &) const;
        
        template<class Ts>
        friend std::ostream& operator<<(std::ostream&, const DoubleLinkedList<Ts> &);
	   
	
    private:
        void quicksort(int, int, Binode<T>*, Binode<T>*);
        Binode<T>* quicksortDivide(int, int, Binode<T>*, Binode<T>*, int&);
        
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
bool DoubleLinkedList<T>::sorted() const
{
    bool flag = true;
    if (!this->empty())
    {
        Binode<T> *current = this->_first;
        Binode<T> *next = current->getNext();
        int i = 0;

        do
        {
            if (current->getKey() > next->getKey())
                flag = false;

            current = next;
            next = next->getNext();
            i++;
        } while (i < this->_size && next && flag);
    }
    return flag;
}

template<class T>
T DoubleLinkedList<T>::front() const
{
    if (this->_first)
        return this->_first->getKey();
    
    throw "Empty list";
}

template<class T>
T DoubleLinkedList<T>::back() const
{
    if(this->_last)
        return this->_last->getKey();
    
    throw "Empty list";
}

template<class T>
void DoubleLinkedList<T>::pushFront(T data)
{
    Binode<T> *add = new Binode<T>(data);
    
    if(this->_size == 0)
        this->_last = add;
    else
    {
        add->setNext(this->_first);
        this->_first->setPrev(add);
    }

    this->_first = add;
    this->_size++;
}

template<class T>
void DoubleLinkedList<T>::pushBack(T data)
{
    Binode<T> *add = new Binode<T>(data);
    
    if(this->_size == 0)
        this->_first = add;
    else
    {
        add->setPrev(this->_last);
        this->_last->setNext(add);
    }
    
    this->_last = add;
    this->_size++;
}

template<class T>
void DoubleLinkedList<T>::popFront()
{
    if (!this->empty())
    {
        Binode<T> *aux = this->_first;
        this->_first = aux->getNext();
        this->_first->setPrev(NULL);
        this->_size--;
        delete aux;
    }
    else
        throw "Empty list";
}
template<class T>
void DoubleLinkedList<T>::popBack()
{
	
	///continue
#endif
