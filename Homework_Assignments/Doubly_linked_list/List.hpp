#ifndef List_hpp
#define List_hpp
#include <iostream>
#include <string>
#include "List.h"
using namespace std;

// ******************************************************
// * Nested class const_iterator implementation
// ******************************************************

// ***************************************************************************************************
// * Constructor: Default
// * Description: Create a default const_iterator with current set to 0
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
List<T>::const_iterator::const_iterator() : current(nullptr)
{}

// ***************************************************************************************************
// * Operator Overload: *
// * Description: returns a reference to the corresponding element in the list by calling
// * retrieve() member function.
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
const T & List<T>::const_iterator::operator*() const
{
    return const_iterator::retrieve();
}

// ***************************************************************************************************
// * Operator Overload: ++
// * Description: Prefix increment
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator++()
{
    this->current = this->current->next;
    return * this;
}

// ***************************************************************************************************
// * Operator Overload: ++
// * Description: Postfix increment
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int)
{
    return ++(*this);
}

// ***************************************************************************************************
// * Operator Overload: --
// * Description: Prefix decrement
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator--()
{
    this->current = current->prev;
    return * this;
}

// ***************************************************************************************************
// * Operator Overload: --
// * Description: Postfix decrement
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int)
{
    return --(*this);
}

// ***************************************************************************************************
// * Operator Overload: ==
// * Description: Checks if a const_iterator is equal to the current node
// * Parameter Description: A const_iterator reference
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
bool List<T>::const_iterator::operator==(const const_iterator &rhs) const
{
    return current == rhs.current;
}

// ***************************************************************************************************
// * Operator Overload: !=
// * Description: Checks if a const_iterator is not equal to the current node
// * Parameter Description: A const_iterator reference
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
bool List<T>::const_iterator::operator!=(const const_iterator &rhs) const
{
    return !(*this == rhs);
}

// ***************************************************************************************************
// * Function: retrieve
// * Description: return a reference to the corresponding element in the list
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
T & List<T>::const_iterator::retrieve() const
{
    return current->data;
}


// ***************************************************************************************************
// * Constructor: Node
// * Description: one-parameter constructor.
// * Parameter Description: A given node that is set to current pointer.
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
List<T>::const_iterator::const_iterator(Node *p) : current{p}
{}

// ******************************************************
// * Nested class iterator implementation
// ******************************************************

// ***************************************************************************************************
// * Constructor: default
// * Description: zero parameter constructor.
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
List<T>::iterator::iterator() : iterator(0)
{}

// ***************************************************************************************************
// * Operator Overload: *
// * Description: returns a reference to the corresponding element in the list by calling
// * retrieve() member function.
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
T & List<T>::iterator::operator*()
{
    return const_iterator::retrieve();
}

// ***************************************************************************************************
// * Operator Overload: *
// * Description: returns a reference to the corresponding element in the list
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
const T & List<T>::iterator::operator*() const
{
    return const_iterator::operator*();
}

// ***************************************************************************************************
// * Operator Overload: ++
// * Description: Prefix increment
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
typename List<T>::iterator & List<T>::iterator::operator++()
{
    this->current = this->current->next;
    return * this;
}

// ***************************************************************************************************
// * Operator Overload: ++
// * Description: Postfix increment
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
typename List<T>::iterator List<T>::iterator::operator++(int)
{
    return ++(*this);
}

// ***************************************************************************************************
// * Operator Overload: --
// * Description: Prefix decrement
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
typename List<T>::iterator & List<T>::iterator::operator--()
{
    this->current = this->current->next;
    return * this;
}

// ***************************************************************************************************
// * Operator Overload: --
// * Description: Postfix decrement
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
typename List<T>::iterator List<T>::iterator::operator--(int)
{
    return --(*this);
}

// ***************************************************************************************************
// * Constructor: Node
// * Description: one-parameter constructor.
// * Parameter Description: A given node that is set to current pointer.
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
List<T>::iterator::iterator(Node *p) : const_iterator{p}
{}

// ***********************************************************
// * List class implementation
// ***********************************************************

// ***************************************************************************************************
// * Constructor: default
// * Description: zero parameter constructor.
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
List<T>::List()
{
    init();
}

// ***************************************************************************************************
// * Constructor: Copy
// * Description: Copy constructor. Creates a new list using elements in existing list rhs
// * Parameter Description: rhs list
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
List<T>::List(const List<T> & rhs)
{
    init();
    for(const_iterator i = rhs.begin(); i != rhs.end(); ++i)
        push_back(*i);
}

// ***************************************************************************************************
// * Constructor: Move
// * Description: Move constructor.
// * Parameter Description: rhs list
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
List<T>::List(List<T> && rhs) : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail}
{
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}

// ***************************************************************************************************
// * Constructor:
// * Description: Constructor creates a list with the parameters passed in.
// * Parameter Description: A list with num elements, all initialized with value val.
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
List<T>::List(int num, const T & val)
{
    init();
    for(int i = 0; i < num; ++i)
        push_front(val);
}

// ***************************************************************************************************
// * Constructor:
// * Description:  construct a List with elements from another list between start and end.
// * Parameter Description: A list will be created using start and uses end to stop
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
List<T>::List(const_iterator start, const_iterator end)
{
    init();
    for(const_iterator i = start; i != end; i++)
    {
        push_front(*i);
    }
}

// ***************************************************************************************************
// * Constructor:
// * Description: Construct a List with elements from another list between start and end.
// * Parameter Description: A list will be created using start and uses end to stop
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// * //https://www.journaldev.com/37427/initializer-lists-in-c-plus-plus
// ***************************************************************************************************
template <typename T>
List<T>::List(std::initializer_list<T> iList)
{
    init();
    for (auto i = iList.begin(); i != iList.end(); ++i)
        push_back(*i);
}

// ***************************************************************************************************
// * Destructor:
// * Description: Properly reclaims all dynamically allocated memory by calling clear()
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
List<T>::~List()
{
    clear();
    delete head;
    delete tail;
}

// ***************************************************************************************************
// * Assignment Operator: =
// * Description: Copy assingment operator
// * Parameter Description: A list object.
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
const List<T> & List<T>::operator=(const List & rhs)
{
    List copy = rhs;
    std::swap(* this, copy);
    return * this;
}

// ***************************************************************************************************
// * Assignment Operator: =
// * Description: Move assingment operator
// * Parameter Description: A list object.
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
List<T> & List<T>::operator=(List && rhs)
{
    std::swap(theSize, rhs.theSize);
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);
    return * this;
}

// ***************************************************************************************************
// * Assignment Operator: =
// * Description: assign the initializer list data to be the calling object's new data
// * Parameter Description: List data
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
List<T> & List<T>::operator=(std::initializer_list<T> iList)
{
    init();
    for (auto i = iList.begin(); i != iList.end(); ++i)
        push_back(*i);
    return * this;
}

// ***************************************************************************************************
// * Function: size()
// * Description: Returns the number of elements in the List.
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
int List<T>::size() const
{
    return theSize;
}

// ***************************************************************************************************
// * Function: empty()
// * Description: Returns true if no element is in the list; otherwise, returns false.
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
bool List<T>::empty() const
{
    return size() == 0;
}

// ***************************************************************************************************
// * Function: clear()
// * Description: Deletes all the elements in the list.
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
void List<T>::clear()
{
    while(!empty())
        pop_front();
}

// ***************************************************************************************************
// * Function: reverse()
// * Description: Reverses the order of the elements in the list.
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// * https://www.chegg.com/homework-help/questions-and-answers/analyze-worst-case-run-time-complexities-member-functions-reverse-removeif--give-complexit-q67458525
// ***************************************************************************************************
template <typename T>
void List<T>::reverse()
{
    if(!empty())
    {
        auto current_ptr=head;
        while(current_ptr != nullptr)
        {
            std::swap(current_ptr->next, current_ptr->prev);
            current_ptr=current_ptr->prev;
        }
    }
    std::swap(head, tail);
}

// ***************************************************************************************************
// * Function: front()
// * Description: Returns a reference to the first element in the list.
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
T & List<T>::front()
{
    if(empty())
    {
        std::cerr << "Error: Empty List" << endl;
    }
    return * begin();
}

// ***************************************************************************************************
// * Function: front()
// * Description: Returns a reference to the first element in the list.
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
const T & List<T>::front() const
{
    if(empty())
    {
        std::cerr << "Error: Empty List" << endl;
    }
    return * begin();
}

// ***************************************************************************************************
// * Function: front()
// * Description: Returns a reference to the last element in the list.
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
T & List<T>::back()
{
    if(empty())
    {
        std::cerr << "Error: Empty List" << endl;
    }
    return * end();
}

// ***************************************************************************************************
// * Function: front()
// * Description: Returns a reference to the last element in the list.
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************

template <typename T>
const T & List<T>::back() const
{
    if(empty())
    {
        std::cerr << "Error: Empty List" << endl;
    }
    return * end();
}

// ***************************************************************************************************
// * Function: push_front()
// * Description: Insert a new object as the first element into the list.
// * Parameter Description: An object of type T
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// * https://stackoverflow.com/questions/22086330/trouble-adding-an-item-to-the-back-of-a-doubly-linked-list
// ***************************************************************************************************
template <typename T>
void List<T>::push_front(const T & val)
{
    insert(begin(), val);
}

// ***************************************************************************************************
// * Function: push_front()
// * Description: Insert a new object as the first element into the list. Move version
// * Parameter Description: An object of type T
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
void List<T>::push_front(T && val)
{
    insert(begin(), std::move(val));
}

// ***************************************************************************************************
// * Function: push_back()
// * Description: Insert a new object as the last element into the list.
// * Parameter Description: An object of type T
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// * https://stackoverflow.com/questions/22086330/trouble-adding-an-item-to-the-back-of-a-doubly-linked-list
// ***************************************************************************************************
template <typename T>
void List<T>::push_back(const T & val)
{
    Node* newNode = new Node();

    newNode->data = val;
    newNode->prev = tail;
    newNode->next = nullptr;

    if (tail != nullptr)
        tail->next = newNode;

    tail = newNode;
    theSize++;
}

// ***************************************************************************************************
// * Function: push_back()
// * Description: Insert a new object as the last element into the list. Move version
// * Parameter Description: An object of type T
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
void List<T>::push_back(T && val)
{
    insert(end(), std::move(val));
}

// ***************************************************************************************************
// * Function: pop_front()
// * Description: Deletes the first element in the list
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// * https://www.alphacodingskills.com/cpp/ds/cpp-delete-the-first-node-of-the-doubly-linked-list.php
// ***************************************************************************************************
template <typename T>
void List<T>::pop_front()
{
    if(head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head != nullptr)
            head->prev = nullptr;
        theSize--;
    }
}

// ***************************************************************************************************
// * Function: pop_back()
// * Description: Deletes the last element in the list
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// * https://www.alphacodingskills.com/cpp/ds/cpp-delete-the-first-node-of-the-doubly-linked-list.php
// ***************************************************************************************************
template <typename T>
void List<T>::pop_back()
{
    if(head != nullptr)
    {
        Node * temp = tail;
        tail = tail->prev;
        delete temp;
        if(head != nullptr)
            head->prev = nullptr;
    }
    theSize--;
}


// ***************************************************************************************************
// * Function: remove()
// * Description: Deletes all nodes with value equal to val from the list.
// * Parameter Description: A values passed in of type T
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// * https://codereview.stackexchange.com/questions/251819/implementation-of-doubly-linked-list-in-c
// ***************************************************************************************************
template <typename T>
void List<T>::remove(const T & val)
{
    Node * tmp = new Node;
    tmp = head->next;
    if (tmp->data == val)
    {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        theSize--;
        delete tmp;
    }
    tmp = tmp->next;
}

// ***************************************************************************************************
// * Function: remove_if()
// * Description: Deletes all nodes for which pred returns true.
// * Parameter Description: A function object
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
template <typename PREDICATE>
void List<T>::remove_if(PREDICATE pred)
{
    for(auto itr=begin(); itr!=end(); itr++)
        if(pred(*itr))
            remove(*itr);
}

// ***************************************************************************************************
// * Function: print()
// * Description: Print all elements in a list
// * Parameter Description: An ostream ojbect and a delimiter
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
void List<T>::print(std::ostream & os, char ofc) const
{
    const_iterator i;

    if(ofc == ' ')
    {
        for(i = begin(); i  != end(); ++i)
            os << * i << ofc;
    }
    else
    {
        for(i = begin(); i != end(); ++i)
            os << * i ;
    }
}

// ***************************************************************************************************
// * Function: begin()
// * Description: Returns iterator to the first element in the list. Returns tail if empty.
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
typename List<T>::iterator List<T>::begin()
{
    if(empty())
        return tail;
    else
        return head;
}

// ***************************************************************************************************
// * Function: begin()
// * Description: Returns iterator to the first element in the list. Returns tail if empty.
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
typename List<T>::const_iterator List<T>::begin() const
{
    if(empty())
        return tail;
    else
        return head;
}

// ***************************************************************************************************
// * Function: end()
// * Description: Returns iterator to the last element in the list.
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
typename List<T>::iterator List<T>::end()
{
    return tail;
}

// ***************************************************************************************************
// * Function: end()
// * Description: Returns iterator to the last element in the list.
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
typename List<T>::const_iterator List<T>::end() const
{
    return tail;
}

// ***************************************************************************************************
// * Function: insert()
// * Description: Insert a value val ahead of the node refered by itr.
// * Parameter Description: itr is a node reference and val is a value of type T
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// * https://stackoverflow.com/questions/22086330/trouble-adding-an-item-to-the-back-of-a-doubly-linked-list
// ***************************************************************************************************
template <typename T>
typename List<T>::iterator List<T>::insert(iterator itr, const T & val)
{
    Node* newNode = new Node();

    newNode->data = val;
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr)
        head->prev = newNode;

    head = newNode;
    theSize++;
    return itr;
}

// ***************************************************************************************************
// * Function: insert()
// * Description: Insert a value val ahead of the node refered by itr. Move Version
// * Parameter Description: itr is a node reference and val is a value of type T
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// * https://stackoverflow.com/questions/22086330/trouble-adding-an-item-to-the-back-of-a-doubly-linked-list
// ***************************************************************************************************
template <typename T>
typename List<T>::iterator List<T>::insert(iterator itr, T && val)
{
    Node* newNode = new Node();

    newNode->data = val;
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr)
        head->prev = newNode;

    head = newNode;
    theSize++;
    return itr;
}

// ***************************************************************************************************
// * Function: erase()
// * Description: Deletes node referred to by itr. The return value is an iterator to the following node.
// * Parameter Description: itr is a node reference.
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
typename List<T>::iterator List<T>::erase(iterator itr)
{
    remove(itr);
}


// ***************************************************************************************************
// * Function: erase()
// * Description: Deletes all nodes between start and end (including start but not end)
// * Parameter Description: start and end will be the range of what will be erased.
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
typename List<T>::iterator List<T>::erase(iterator start, iterator end)
{
    for(iterator itr = start; itr != end; itr++)
        pop_front();
    return end;
}

// ***************************************************************************************************
// * Function: init()
// * Description: Initialize the member variables of list
// * Parameter Description:
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
void List<T>::init()
{
    theSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

// ***************************************************************************************************
// * Operator Overload: ==
// * Description: check if two lists contain the same sequence of elements. Two lists are equal if
// * they have the same number of elements and the elements at the corresponding position are equal.
// * Parameter Description: Two list objects
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
bool operator==(const List<T> & lhs, const List<T> & rhs)
{
    typename List<T>::const_iterator i1;
    typename List<T>::const_iterator i2;

    for (i1 = lhs.begin(), i2 = rhs.begin(); (i1 != lhs.end()) && (i2 != rhs.end()); ++i1, ++i2)
    {
        if(*i1 != *i2)
            return 0;
    }

    if(i1 !=lhs.end() || i2 != rhs.end())
        return 0;
    return 1;
}

// ***************************************************************************************************
// * Operator Overload: !=
// * Description: check if two lists are not equal.
// * Parameter Description: Two list objects
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
bool operator!=(const List<T> & lhs, const List<T> &rhs)
{
    return !(*lhs == *rhs);
}

// ***************************************************************************************************
// * Operator Overload: <<
// * Description:  print out all elements in list l by calling List::print() function.
// * Parameter Description: ostream operator and a list object
// * Date: June 17, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
std::ostream & operator<<(std::ostream & os, const List<T> & l)
{
    l.print(os);
    return os;
}

#endif /* List_hpp */
