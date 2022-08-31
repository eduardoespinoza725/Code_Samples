#ifndef STACK_H
#define STACK_H
// ********************************************************************
// * Name: Stack Class                                                *
// * Description: A template Stack class designed to be used with     *
// * any simple C++ type to include floating point, double            *
// * floating point, character, and Boolean.                          *
// * The stack pointer, as is the convention, points to the last      *
// * or highest element in the array. So if you allocate 100          *
// * elements of type "T" then the first empty element will be 99.    *
// * Author: Eduardo Espinoza                                         *
// * Date: May 19, 2022                                               *
// ********************************************************************
#include <iostream>
using namespace std;

const int DEFAULTSIZE=100;
template <typename T> class Stack;
template <typename T> ostream & operator <<(ostream & os,  Stack<T> &obj);
template <typename T>
class Stack {
public:
    Stack();                    // Default Constructor, stack is size 100.
    Stack(const int size);      // Constructor, creates stack of size "size"
    Stack(const Stack & Obj);   // Copy constructor
    ~Stack();                   // Destructor
    bool Full();                // Return true if the stack is full
    bool Empty();               // Return true if the stack is empty
    int Size();                 // Return the size of the stack
    int Number();               // Return the number of elements stored
    T Top();                    // Returns the top element, does not pop it
    bool Push (const T item);   // Put an item on the stack
    bool Pop();                 // Pop an item off and display to std out
    Stack<T> &operator = (Stack<T> & s); // = operator overload.
    friend ostream &operator << <T>(ostream & os, Stack<T> &s);

protected:
    T * _stack;                 // The "stack"
    int _size;                  // The number of elements the stack can hold
    int _top;                   // Points to the first empty node
    int _number;                // The number of elements in the stack.
};

// ***************************************************************************************************
// * Constructor: Default
// * Description: This is the default constructor. Sets stack to default values
// * Parameter Description:
// * Date: May 19, 2022
// * Author: Eduardo Espinoza
// * References: COP 3330 Assignment 7, Dr. David A Gaitros
// ***************************************************************************************************
template <typename T>
Stack<T>::Stack()
{
    _size = DEFAULTSIZE;
    _stack = new T [_size];
    _top = 0;
    _number = 0;
}

// ***************************************************************************************************
// * Constructor:
// * Description: Constructor allocates space for the stack using a number passed in. Constructor
// * uses template to allow for values of any type to be used in the stack.
// * Parameter Description: An integer value passed in by main driver and used to allocate the size
// * Date: May 19, 2022
// * Author: Eduardo Espinoza
// * References: COP 3330 Assignment 7, Dr. David A Gaitros
// ***************************************************************************************************
template <typename T>
Stack<T>::Stack(const int size)
{
    if(size < 1) _size = DEFAULTSIZE;
    else _size = size;
    _stack = new T [_size];
    _top = 0;
    _number = 0;
}


// ***************************************************************************************************
// * Constructor: Copy
// * Description: Constructor allocates space for a new stack using an object passed in. Uses template
// * to allow for values of any type to be in the stack.
// * Parameter Description: A stack object
// * Date: May 19, 2022
// * Author: Eduardo Espinoza
// * References: COP 3330 Assignment 7, Dr. David A Gaitros
// ***************************************************************************************************
template <typename T>
Stack<T>::Stack(const Stack & Obj)
{
    _size = Obj._size;
    _stack = new T [_size];
    _stack = Obj._stack;
    _top = Obj._top;
    _number = Obj._number;
}

// ***************************************************************************************************
// * Constructor: Deconstructor
// * Description: Deconstructor deletes the stack and sets it to NULL;
// * Parameter Description:
// * Date: May 19, 2022
// * Author: Eduardo Espinoza
// * References: COP 3330 Assignment 7, Dr. David A Gaitros
// ***************************************************************************************************
template <typename T>
Stack<T>::~Stack()
{
    if(_top > 0)
    {
        delete [] _stack;
        _stack = NULL;
    }
}

// ***************************************************************************************************
// * Function: Full
// * Description: Function returns true if the Stack is full, false otherwise. Function checks if
// * top and stack are equal or if the number of elements in the stack are equal to size.
// * Parameter Description:
// * Date: May 19, 2022
// * Author: Eduardo Espinoza
// * References: COP 3330 Assignment 7, Dr. David A Gaitros
// ***************************************************************************************************
template <typename T>
bool Stack<T>::Full()
{
    if(_top == _size || _number == _size) return true;
    else return false;
}

// ***************************************************************************************************
// * Function: Empty
// * Description: Function return true if the Stack is empty, false otherwise
// * Parameter Description:
// * Date: May 19, 2022
// * Author: Eduardo Espinoza
// * References: COP 3330 Assignment 7, Dr. David A Gaitros
// ***************************************************************************************************
template <typename T>
bool Stack<T>::Empty()
{
    if(_top == 0) return true;
    else return false;
}

// ***************************************************************************************************
// * Function: Size
// * Description: Function returns the size of the stack (the amount that was allocated).
// * Parameter Description:
// * Date: May 19, 2022
// * Author: Eduardo Espinoza
// * References: COP 3330 Assignment 7, Dr. David A Gaitros
// ***************************************************************************************************
template <typename T>
int Stack<T>::Size()
{
    return _size;
}

// ***************************************************************************************************
// * Function: Number
// * Description: Returns the number of elements stored in the stack.
// * Parameter Description:
// * Date: May 19, 2022
// * Author: Eduardo Espinoza
// * References: COP 3330 Assignment 7, Dr. David A Gaitros
// ***************************************************************************************************
template <typename T>
int Stack<T>::Number()
{
    for (int i = 0; i < _top; i++)
        _number++;
    return _number;
}

// ***************************************************************************************************
// * Function: Top
// * Description: Function returns the top element but does not remove it from the Stack. It returns
// * a copy to the calling routine.
// * Parameter Description:
// * Date: May 19, 2022
// * Author: Eduardo Espinoza
// * References: COP 3330 Assignment 7, Dr. David A Gaitros
// ***************************************************************************************************
template <typename T>
T Stack<T>::Top()
{
    T top = _stack[_top - 1];
    return top;
}

// ***************************************************************************************************
// * Function: Push
// * Description: Function puts an element on the Stack, Issues an error message if you try to Push
// * an element on a full stack.
// * Parameter Description: An item of any type is accepted and added to the stack
// * Date: May 19, 2022
// * Author: Eduardo Espinoza
// * References: COP 3330 Assignment 7, Dr. David A Gaitros
// ***************************************************************************************************
template <typename T>
bool Stack<T>::Push(const T item)
{
    if(!Full())
    {
        _stack[_top++] = item;
        return true;
    }
    else
    {
        cout << "Error pushing, Stack Full" << endl;
        return false;
    }
}

// ***************************************************************************************************
// * Function: Pop
// * Description: Function Prints the top element from a stack and removes it from the stack.
// * Issues an error message if the stack is empty.
// * Parameter Description:
// * Date: May 19, 2022
// * Author: Eduardo Espinoza
// * References: COP 3330 Assignment 7, Dr. David A Gaitros
// ***************************************************************************************************
template <typename T>
bool Stack<T>::Pop()
{
    T value;

    if(Empty())
    {
        cout << "Stack Empty" << endl;
        return false;
    }
    else
    {
        value = _stack[--_top];
        return true;
    }
}

// ***************************************************************************************************
// * Assignment operator overload =
// * Description: Similar to the copy constructor it copies the content of one stack to another
// * essentially making a copy of it.
// * Parameter Description: Accepts a stack object
// * Date: May 19, 2022
// * Author: Eduardo Espinoza
// * References: COP 3330 Assignment 7, Dr. David A Gaitros
// ***************************************************************************************************
template <typename T>
Stack<T> & Stack<T>::operator = (Stack<T> & s)
{
    _size = s._size;
    _stack = new T [_size];
    _top = s._top;
    _top -= 1;
    
    for(int i = 0; i < _size; i++)
    {
        _stack[++_top] = s._stack[s._top++];
    }
    return * this;
}

// ***************************************************************************************************
// * Assignment operator overload <<
// * Description: Prints out the entire contents of the stack. Prints a message if the stack is empty.
// * Prints out the status of the stack.
// * Parameter Description: Accepts a stack object
// * Date: May 19, 2022
// * Author: Eduardo Espinoza
// * References: COP 3330 Assignment 7, Dr. David A Gaitros
// ***************************************************************************************************
template <typename T>
ostream & operator << (ostream & os, Stack<T> & s)
{
    if(s.Empty())
    {
        os << "Stack is Empty" << endl;
    }
    else
    {
        os << "Stack Not Empty" << endl;
    }
    os << "The top element is: " << s.Top() << endl;
    os << "Size of stack: " << s.Size() << endl;
    os << "The number of elements it can hold is: " << s.Number() << endl;
    
    if(s.Full())
    {
        os << "Stack is Full" << endl;
    }
    else
    {
        os << "Stack not Full" << endl;
    }
    
    os << "Popping the top element before we print it out" << endl;
    s.Pop();
    os << "The contents of the stack is: ";
    for(int i = 0; i < s._size; i++)
    {
        if(s._top > 0)
        {
            os << s._stack[--s._top] << " ";
        }
    }
    return os;
}

#include "stack.h"
#endif
