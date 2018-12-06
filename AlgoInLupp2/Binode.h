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

   
};
