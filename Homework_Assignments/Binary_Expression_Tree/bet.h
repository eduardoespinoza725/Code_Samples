// *******************************************************************************************
// * Name: Assignment 5 Binary Trees
// * Description: Implements a binary expression tree and its using it to convert
// * postfix expressions into infix expressions using recursive functions.
// * Author: Eduardo Espinoza
// * Date: July 08, 2022
// *******************************************************************************************
#ifndef BET_H
#define BET_H
#include <iostream>
#include <stack>
using namespace std;

// ******************************************************************************
// * Include in this file are:
// * 1. BET
// * 2. BinaryNode struct (Nested inside of BET class)
// ******************************************************************************

template <typename T> class BET;

// ************************************************************
// * Class: BET
// ************************************************************
template <typename T>
class BET
{

private:
    // ************************************************************
    // * Nested Struct: BinaryNode
    // ************************************************************
    struct BinaryNode
    {
        T element;
        BinaryNode * left;
        BinaryNode * right;

        // Binary Node constructors
        BinaryNode()
        {
            left = nullptr;
            right = nullptr;
        }

        BinaryNode(const T & e, BinaryNode * left, BinaryNode * right)
        {
            this->element = e;
            this->left = left;
            this->right = right;
        }

        explicit BinaryNode(const T & e)
        {
            this->element = e;
            left = nullptr;
            right = nullptr;
        }
    };  // end struct BinaryNode

public:
    // ************************************************************
    // * Class: BET
    // * Member Functions
    // ************************************************************
    BET();                                          // default
    explicit BET(const string & postfix);           // One param, postfix = postfix expression(the tree)
    BET(const BET &);                               // Copy
    ~BET();                                         // Destructor

    bool buildFromPostfix(const string & postfix);
    const BET & operator = (const BET &);
    void printInfixExpression();
    void printPostfixExpression();
    void makeEmpty();
    size_t size();
    size_t leaf_nodes();
    bool empty() const;

private:

    // ************************************************************
    // * Class: BET
    // * Private Helper Functions
    // ************************************************************
    BinaryNode * root;

    BinaryNode * createTree(const string & x, BinaryNode * t);
    void printInfixExpression(BinaryNode * n);
    void printPostfixExpression(BinaryNode * n);
    void makeEmpty(BinaryNode * & t);
    BinaryNode * clone(BinaryNode * t)const;
    size_t size(BinaryNode * t);
    size_t leaf_nodes(BinaryNode * t);
    bool IsItanOperator(string token);
    size_t Precedence(T instr);


};  // end class BET

#include "bet.hpp"
#endif //BET_H
