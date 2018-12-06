#ifndef _STACK_H
#define _STACK_H
#pragma once
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
        void invert();
        T top() const { return this->_top->getKey(); };
        void clear();

        void loadFile(string);

        template<class Ts>
        friend std::ostream& operator<<(std::ostream&, const Stack<Ts> &);
    
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
void Stack<T>::invert()
{
    T data;
    Stack<T> *aux = new Stack<T>();
        while(!this->empty())
        {
            data = this->top();
            this->pop();
            aux->push(data);
        }
    this->_top = aux->_top;
    this->_size = aux->_size;
}

template <class T>
void Stack<T>::clear()
{
    if(!this->empty())
        while(this->_size)
            this->pop();
}

template<class T>
std::ostream& operator<<(std::ostream& out, const Stack<T> &Stack)
{
    Node<T> *Node;
    Node = Stack._top;
    out << "\n";
    for (int i = 0; i < Stack._size; i++, Node = Node->getNext())
        out << Node->getKey() << "\n";
    return out;
}

template<typename T>
void Stack<T>::loadFile(string file)
{
    T line;
    ifstream in;
    in.open(file.c_str());
 
    if (!in.is_open())
        cout << "can´t not open file : " << file << endl;
    else
        while (in >> line)
            this->push(line);
    in.close();
}

#endif
