
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
        //Methods Setters
        void setKey(T _in) { _data = _in; };
        void setNext(Node *n) { _next = n; };
        //Methods Getters
        T getKey() const { return _data; };
        Node* getNext() const { return _next; };

        //swap method
        static void swap(Node *_inA, Node *_inB);
};


#endif

