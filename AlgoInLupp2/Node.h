
#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>

template<class T>
class Node
{
    private:
        T _data;
        Node *_next;

    public:
        //Constructor
        Node() : _next(NULL) { };
        Node(const Node& _in) : _data(_in._data), _next(NULL) { };
        //Copy Constructor
        Node(T _in) : _data(_in), _next(NULL) { };
        //Destroy
        ~Node() { };
        
        void setKey(T _in) { _data = _in; };
        void setNext(Node *n) { _next = n; };
       
        T getKey() const { return _data; };
        Node* getNext() const { return _next; };

        
        bool operator>(const Node &_in);
        bool operator<(const Node &_in);
        bool operator==(const Node &_in);
        bool operator>=(const Node &_in);
        bool operator<=(const Node &_in);

       
        static void swap(Node *_inA, Node *_inB);
};


template<class T>
bool Node<T>::operator>(const Node<T> &a)
{
    if (this != &a)
        return (this->key() > a.key());

    return false;
}


template<class T>
bool Node<T>::operator<(const Node<T> &a )
{
    if (this != &a)
        return (this->key() < a.key());

    return false;
}


template<class T>
bool Node<T>::operator==(const Node<T> &a)
{
    return (this->key() == a.key());
}


template<class T>
bool Node<T>::operator>=(const Node<T> &a)
{
    return (*this > a || *this == a);
}


template<class T>
bool Node<T>::operator<=(const Node<T> &a)
{
    return (*this < a || *this == a);
}


template<class T>
void Node<T>::swap(Node<T> *a, Node<T> *b)
{
    T aux = a->_data;
    a->_data = b->_data;
    b->_data = aux;
}

#endif
