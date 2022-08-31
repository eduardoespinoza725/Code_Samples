#ifndef List_hpp
#define List_hpp
#include "List.h"
#include <iostream>
using namespace cop4530;

// Everytime you use const_iterator or iterator add 'List<T>' in front
template <typename T>
List<T>::const_iterator::const_iterator()
{
    current = nullptr;
}

template <typename T>
List<T>::const_iterator::const_iterator(Node * p)
{
    current = p;
}

template <typename T>
T & List<T>::const_iterator::retrieve() const
{
    return this->current->data;
}

// Iterator class inherits from const_iterator, this is the syntax
// This is also an inline constructor so it is empty.
template <typename T>
List<T>::iterator::iterator(Node * p) : List<T>::const_iterator::const_iterator(p)
{}

// part of list class
template <typename T>
void List<T>::init()
{
    theSize = 0;
    head = new List::Node;      // normally we would not do this
    tail = new List::Node;      // normally we would not do this
    //head->next = tail;          // here we would put nullptr
    //tail->prev = head;          // here we would put nullptr
    head->next = nullptr;
    tail->prev = nullptr;
    head->prev = nullptr;
    tail->next = nullptr;
}

template <typename T>
List<T>::List()
{
    init();
}

template <typename T>
List<T>::List(const List & rhs)
{
    init();
}

template <typename T>
// putting typename here fixes the "List unknown" error.
typename List<T>::iterator List<T>::erase(iterator itr)
{
    List<T>::Node * p = itr.current;
    List<T>::iterator retval(p->next);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --theSize;
    return retval;
}

template <typename T>
int List<T>::size() const {return theSize;}

template <typename T>
bool List<T>::empty() const
{
    if(theSize == 0) return true;
    else return false;
}


#endif /* List_hpp */
