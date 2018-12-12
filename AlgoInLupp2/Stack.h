#ifndef _STACK_H
#define _STACK_H
#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"

using namespace std;

template <class T>
class Stack
{
    private:
        int _size;
        Node<T> *_top;

    public:
        Stack() : _size (0), _top(NULL) {};
        Stack(const Stack<T> &);
        ~Stack() { this->clear(); };

        int size() const { return this->_size; };
        bool empty() const { return this->_size == 0; };
        void push(T);
        void pop();
        T top() const { return this->_top->getKey(); };
        void clear();
    
};

template <class T>
Stack<T>::Stack(const Stack<T> &_in)
{
    if(_in._top)
    {
        this->clear();
        this->_top = new Node<T>(_in._top->getKey());
        Node<T> *copyaux = _in._top->getNext();
        Node<T> *thisaux = this->_top;

        while(copyaux)
        {
            Node<T> *newNode = new Node<T>(copyaux->getKey());
            thisaux->setNext(newNode);
            thisaux = thisaux->getNext();
            copyaux = copyaux->getNext();
        }
    }
    this->_size = _in._size;
}

template <class T>
void Stack<T>::push(T data)
{
    Node<T> *newNode = new Node<T>(data);
    newNode->setNext(this->_top);
    this->_top = newNode;
    _size++; 
}

template <class T>
void Stack<T>::pop()
{
    Node<T> *popData;
    popData = this->_top;
    this->_top = this->_top->getNext();
    delete popData;
    _size--;
}

template <class T>
void Stack<T>::clear()
{
    if(!this->empty())
        while(this->_size)
            this->pop();
}

#endif

