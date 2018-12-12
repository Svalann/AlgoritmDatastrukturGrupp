
#include "LinkedList.h"
using namespace std;

template <class classtype>
LinkedList <classtype>::LinkedList()
{

    this->head = nullptr;

}


template <class classtype>
void LinkedList <classtype>::AddFirst(T data)
{

    Node *temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
}


template <class classtype>
void LinkedList <classtype>::AddLast(T data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    if (head == nullptr)
    {
        head = temp;
        return;
    }
    Node *temp2 = new Node;
    temp2 = head;
    while (temp2->next != nullptr) {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}



template <class classtype>
void LinkedList <classtype>:InsertPosition(T data, int index)    // FÅR INTE DENNA FUNKTION ATT FUNGERA
{
    Node *temp1 = new Node;
    temp1->data = data;
    temp1->next = nullptr;

    if (index == 0)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    Node *temp2 = head;

    for (int i = 0; i < index; i++)

    {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}



template <class classtype>
void LinkedList <classtype>::RemovePosition(int index)
{
    Node *temp1 = head;

    if (index == 0)

    {
        head = temp1->next;
        delete temp1;
        return;
    }

    int i;

    for (int i = 0; i < index - 2; i++)

    {
        temp1 = temp1->next;
    }

    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}



template <class classtype>
void LinkedList <classtype>::Print()
{
    Node *temp = head;

    while (temp != nullptr)

    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }

    std::cout << std::endl;
}

template <class classtype>
T LinkedList <classtype>::GetNode(int index)

{
    Node *current = head;
    int count{};
    while (current != nullptr)
    {
        if (count == index)
            return(current->data);
        count++;
        current = current->next;
    }
    assert(0);
}

template <class classtype>
int LinkedList <classtype>::GetSize()

{
    int count{};
    Node *temp = head;
    while (temp != nullptr)
    {
        ++count;
        temp = temp->next;
    }
    return count;
}






