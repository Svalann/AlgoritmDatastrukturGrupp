#ifndef _BINODE_H_
#define _BINODE_H_
#include <iostream>

template<class T>
class Binode
{
    private:
        T _key;
        Binode *_prev, *_next;

    public:
        Binode() : _prev(NULL), _next(NULL) {};
        Binode(const Binode& _in) : _key(_in._key), _prev(NULL), _next(NULL) {};
        Binode(T e) : _key(e), _prev(NULL), _next(NULL) {};

        void setKey(T e) { _key = e; };
        void setPrev(Binode *_in) { _prev = _in; };
        void setNext(Binode *_in) { _next = _in; };

        T getKey() const { return _key; };
        Binode *getPrev() const { return _prev; };
        Binode *getNext() const { return _next; };

        static void swap(Binode *, Binode *);
    };

template<class T>
void Binode<T>::swap(Binode *a, Binode *b)
{
    T aux = a->_key;
    a->_key = b->_key;
    b->_key = aux;
}

#endif

