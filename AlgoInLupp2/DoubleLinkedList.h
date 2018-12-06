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
	
	///continue
