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
    if (!this->empty())
    {
        Binode<T> *aux = this->_last;
        this->_last = aux->getPrev();
        this->_last->setNext(NULL);
        this->_size--;
        delete aux;
    }
    else
        throw "Empty list";
}

template<class T>
void DoubleLinkedList<T>::erase(int index)
{
    if (empty())
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
void DoubleLinkedList<T>::change(T data, int index)
{
    if (this->empty())
        throw "Empty List';
    else if (index < 1 || index > this->_size + 1)
        throw "Index out of bounds";
    else
    {
	        
        if (index == 1)
            this->_first->setKey(data);
        else if (index == this->_size)
            this->_last->setKey(data);
        else
        {
            Binode<T> *pivot = this->_first;
            for (int i = 1; i < index; i++)
                pivot = pivot->getNext();
            
            pivot->setKey(data);
        }
    }
}
template<class T>
void DoubleLinkedList<T>:clear()
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

template<class T>
void DoubleLinkedList<T>::invert()
{
    Binode<T> *current = this->_first;
    Binode<T> *temp = NULL;

    if (current)
        this->_last = this->_first;

    while (current)
    {
        temp = current->getPrev();
        current->setPrev(current->getNext());
        current->setNext(temp);
        current = current->getPrev();
    }
    
    if (temp)
        this->_first = temp->getPrev();
}
template<class T>
void DoubleLinkedList<T>::sort()
{
    if (this->_size <= 20)
        this->bubblesort();
    else
        this->quicksort();
}

template<class T>
void DoubleLinkedList<T>::bubblesort()
{
    if (!this->sorted())
    {
        for(int p = 0, n = _size; p < n - 1; p++)
        {
            Binode<T> *pivot = this->_first;
            Binode<T> *next = pivot->getNext();
            for (int j = 0; j < n - p - 1; j++)
            {
                if (pivot->getKey() > next->getKey())
                    Binode<T>::swap(pivot, next);
                
                pivot = next;
                next = next->getNext();
            }
        }
    }
}

template<class T>
void DoubleLinkedList<T>::quicksort()
{
    if (!this->sorted())
    {
        quicksort(1, _size, this->_first, this->_last);
    }
}

template<class T>
void DoubleLinkedList<T>::quicksort(int start, int end, Binode<T>* nStart, Binode<T>* nEnd)
{
    int pivot;
    Binode<T> *nPivot = NULL;

    if (start < end)
    {
        nPivot = quicksortDivide(start, end, nStart, nEnd, pivot);

        // Recursive calls from here
        quicksort(start, pivot - 1, nStart, nPivot->getPrev());

        quicksort(pivot + 1, end, nPivot->getNext(), nEnd);
    }
}

template<class T>
Binode<T>* DoubleLinkedList<T>::quicksortDivide(int start, int end, Binode<T>* nStart, Binode<T>* nEnd, int& pivot)
{
    int left, right;
    Binode<T> *nLeft, *nRight;

    T ppivot = nStart->getKey();
    left = start;
    right = end;
    nLeft = nStart;
    nRight = nEnd;

    while (left < right)
    {
        while (nRight->getKey() > ppivot)
        {
            nRight = nRight->getPrev();
            right--;
        }

        while ((left < right) && (nLeft->getKey() <= ppivot))
        {
            nLeft = nLeft->getNext();
            left++;
        }

        if (left < right)
            Binode<T>::swap(nLeft, nRight);
    }

    Binode<T>::swap(nRight, nStart);

    pivot = right;
    return nRight;
}

template<class T>
void DoubleLinkedList<T>::operator=(const DoubleLinkedList<T> &_in)
{
    if (this != &_in)
    {
        this->clear();
        Binode<T> *_inIterator = _in._first;
        Binode<T> *thisIterator = this->_first;
        Binode<T> *newNode;
        
        for (int i = 1; i <= _in._size; i++, _inIterator = _inIterator->getNext())
        {
            newNode = new Binode<T>();
            newNode->setKey(_inIterator->getKey());

            if (i == 1)
            {
                this->_first = newNode;
                thisIterator = newNode;
            }
            else
            {
                thisIterator->setNext(newNode);
                newNode->setPrev(thisIterator);
                thisIterator = thisIterator->getNext();
            }
        }
        this->_last = newNode;
        this->_size = _in._size;
    }
}

template<class T>
bool DoubleLinkedList<T>::operator>(const DoubleLinkedList<T> &_in) const
{
    if (this != &_in)
        return (this->_size > _in._size);

    return false;
}

template<class T>
bool DoubleLinkedList<T>::operator<(const DoubleLinkedList<T> &_in) const
{
    return !(*this > _in);
}

template<class T>
bool DoubleLinkedList<T>::operator==(const DoubleLinkedList<T> &_in) const
{
    if (this != &_in)
    {
        if (this->_size == _in._size)
        {
            Binode<T> *thisIterator = this->_first;
            Binode<T> *vPivot = _in._first;
            bool isEqual;
            int i = 1;

            do
            {
                isEqual = (thisIterator->getKey() == vPivot->getKey());
                i++;
                thisIterator = thisIterator->getNext();
                vPivot = vPivot->getNext();
            } while(i <= this->_size && isEqual);

            return isEqual;
        }

        return false;
    }


	
	///continue
#endif
