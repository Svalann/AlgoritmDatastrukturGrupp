//#pragma once
//class LinkedList
//{
//public:
//	LinkedList();
//	~LinkedList();
//};

#pragma once
#include <vector>
using namespace std;


template <class classtype>
class LinkedList
{
private:
    vector <classtype> aLinkedList;
public:
    LinkedList();
    int CountLinkedList();
    //add to first
    //insertvalfri
    //get valfri på index
    //deletepå

    ~LinkedList();
};

