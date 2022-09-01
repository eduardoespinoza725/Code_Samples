// *******************************************************************************************
// * Name: Assignment 5 Binary Trees
// * Description: Implements a binary expression tree and its using it to convert
// * postfix expressions into infix expressions using recursive functions.
// * Author: Eduardo Espinoza
// * Date: July 08, 2022
// *******************************************************************************************
#ifndef BET_HPP
#define BET_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include "bet.h"
using namespace std;

// *******************************************************************************************************
// ********************************************** Pubilic ************************************************
// *******************************************************************************************************

// ***************************************************************************************************
// * Constructor: default
// * Description: zero parameter constructor. Sets root node to nullptr
// * Parameter Description:
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
BET<T>::BET()
{
    root = nullptr;
}

// ***************************************************************************************************
// * Constructor: One parameter
// * Description: Creates a binary tree using the string tokens passed in from the parameter.
// * Parameter Description: A string with tokens separated by spaces.
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
BET<T>::BET(const string & postfix) : root{nullptr}
{
    root = createTree(postfix, root);
}

// ***************************************************************************************************
// * Constructor: Copy
// * Description: Makes appropriate deep copy of the tree.
// * Parameter Description: A binary expression tree.
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
BET<T>::BET(const BET & t) : root{nullptr}
{
    root = clone(t.root);
}

// ***************************************************************************************************
// * Destructor:
// * Description: Cleans up all dynamic space in the tree by calling makeEmpty().
// * Parameter Description:
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
BET<T>::~BET()
{
    makeEmpty();
}

// ***************************************************************************************************
// * Function: buildFromPostfix()
// * Description: Creates a binary tree using a postfix expression.
// * If the node is not empty will delete nodes and create new tree otherwise it will create a new tree
// * or return false.
// * Parameter Description: "postfix" parameter is a string containing a postfix expression.
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
bool BET<T>::buildFromPostfix(const string & postfix)
{
    if(root != nullptr)
    {
        makeEmpty();
        root = createTree(postfix, root);
        return true;
    }
    else if(root == nullptr)
    {
        root = createTree(postfix, root);
        return true;
    }
    else
        return false;
}

// ***************************************************************************************************
// * Operator overload: =
// * Description: Makes appropriate deep copy.
// * Parameter Description: A binary tree.
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
const BET<T> & BET<T>::operator=(const BET & t)
{
    root = clone(t.root);
    return * this;
}

// ***************************************************************************************************
// * Function: printInfixExpression()
// * Description: Converts postfix expression to infix epression by passing the tree to a recursive function.
// * Parameter Description:
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
void BET<T>::printInfixExpression()
{
    if(empty())
        cout << "empty" << endl;
    else
    {
        printInfixExpression(root);
        cout << endl;
    }
}

// ***************************************************************************************************
// * Function: printPostfixExpression()
// * Description: Prints out the postfix form of an expression using a recursive function.
// * Parameter Description:
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
void BET<T>::printPostfixExpression()
{
    if(empty())
        cout << "empty" << endl;
    else
    {
        printPostfixExpression(root);
        cout << endl;
    }
}

// ***************************************************************************************************
// * Function: makeEmpty()
// * Description: Passes the tree to a recursive function to delete all nodes.
// * Parameter Description:
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
void BET<T>::makeEmpty()
{
    makeEmpty(root);
}

// ***************************************************************************************************
// * Function: size()
// * Description: Returns the number of nodes in the tree using a recursive function.
// * Parameter Description:
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
size_t BET<T>::size()
{
    return size(root);
}

// ***************************************************************************************************
// * Function: leaf_nodes()
// * Description: Returns the number of leaf nodes by calling a recursive function.
// * Parameter Description:
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
size_t BET<T>::leaf_nodes()
{
    return leaf_nodes(root);
}

// ***************************************************************************************************
// * Function: empty()
// * Description: return true if the tree is empty. Return false otherwise
// * Parameter Description:
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
bool BET<T>::empty() const
{
    if(root == nullptr)
        return true;
    else return false;
}

// *******************************************************************************************************
// ********************************************** Private ************************************************
// *******************************************************************************************************


// ***************************************************************************************************
// * Function: createTree()
// * Description: Creates a binary expression tree using string. Each string token is separated by
// * space using <sstream> library. A stack is used to help.
// * Parameter Description: A postfix expression and the current tree.
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// * https://www.techiedelight.com/expression-tree/
// ***************************************************************************************************
// Uses the <sstream> library.
template <typename T>
typename BET<T>::BinaryNode * BET<T>::createTree(const string & x, BinaryNode * t)
{
    stack<BinaryNode *> s;
    BinaryNode * a;
    BinaryNode * b;
    istringstream ss(x);
    string word; // for storing each word

    // Traverse through all words
    // while loop till we get
    // strings to store in string word
    while (ss >> word)
    {
        // pass the read word
        if (IsItanOperator(word))
        {
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            // Construct a new binary tree whose root is the operator and whole
            // left and right children point to a and b
            t = new BinaryNode(word, b, a);
            s.push(t);
        }
        else
        {
            t = new BinaryNode(word);
            s.push(t);
        }
    }
    return t;
}

// ***************************************************************************************************
// * Recursive Function: printInfixExpression()
// * Description: Prints to the standard output the corresponding infix expression. Adds parentheses
// * depending on the precedence of the operators. Inorder traversal is used to traverse the tree.
// * Parameter Description: The current tree.
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
void BET<T>::printInfixExpression(BinaryNode * n)
{
    if(n != nullptr)
    {
        if(IsItanOperator(n->element))
        {
            // Skip the root of tree to avoid having an extra "(" at beginning
            if(n == root && Precedence(root->element) < Precedence(root->left->element))
                ;
            else if(IsItanOperator(n->left->element) && Precedence(n->left->element) < Precedence(n->element))
                cout << "( ";
        }

        printInfixExpression(n->left);

        if(n == root && Precedence(n->element) == 2)
            cout << ") ";

        cout << n->element << " ";
        printInfixExpression(n->right);

        if(IsItanOperator(n->element))
            if (n == root && Precedence(n->element) >= Precedence(n->left->element))
                cout << ") ";
    }
}

// ***************************************************************************************************
// * Recursive Function: printPostfixExpression()
// * Description: Prints to the standard output the corresponding postfix expression.
// * Postorder traversal is used to traverse the tree.
// * Parameter Description: The current tree.
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
void BET<T>::printPostfixExpression(BinaryNode * n)
{
    if(n != nullptr)
    {
        printPostfixExpression(n->left);
        printPostfixExpression(n->right);
        cout << n->element << " ";
    }

}

// ***************************************************************************************************
// * Recursive Function: makeEmpty()
// * Description: Delete all the nodes in the tree pointed to by t.
// * Parameter Description: The current tree.
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
void BET<T>::makeEmpty(BinaryNode * & t)
{
    if(t != nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

// ***************************************************************************************************
// * Recursive Function: makeEmpty()
// * Description: Clones all nodes in the tree pointed to by t.
// * Parameter Description: The current tree.
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
typename BET<T>::BinaryNode * BET<T>::clone(BinaryNode *t)const
{
    if (t == nullptr)
        return nullptr;
    else
        return new BinaryNode{t->element, clone(t->left), clone(t->right)};
}

// ***************************************************************************************************
// * Recursive Function: size()
// * Description: Returns the number of nodes in the subtree pointed by t.
// * Parameter Description: The current tree.
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// * https://www.geeksforgeeks.org/write-a-c-program-to-calculate-size-of-a-tree/
// ***************************************************************************************************
template <typename T>
size_t BET<T>::size(BinaryNode * t)
{
    if(t == nullptr)
        return 0;
    return (1 + size(t->left) + size(t->right));
}

// ***************************************************************************************************
// * Recursive Function: size()
// * Description: Returns the number of leaf nodes in the subtree pointed by t.
// * Parameter Description: The current tree.
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// * https://www.geeksforgeeks.org/write-a-c-program-to-get-count-of-leaf-nodes-in-a-binary-tree/
// ***************************************************************************************************
template <typename T>
size_t BET<T>::leaf_nodes(BinaryNode * t)
{
    if(t == nullptr)
        return 0;
    if(t->left == nullptr && t->right == nullptr)
        return 1;
    else
        return leaf_nodes(t->left) + leaf_nodes(t->right);
}

// ***************************************************************************************************
// * Function: IsItanOperator()
// * Description: Checks if node contains  + - * / ()
// * Parameter Description: The current node
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
bool BET<T>::IsItanOperator(string token)
{
    if(token == "+" || token == "-" || token == "*" || token == "/" || token == "(" || token == ")")
        return true;
    return false;
}

// ***************************************************************************************************
// * Function: Precedence()
// * Description: Checks if the current node contains certain operators and their ranking
// * Parameter Description: The current node
// * Date: July 08, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename T>
size_t BET<T>::Precedence(const T instr)
{
    if(instr == "*" || instr == "/")
        return 2;
    else if(instr == "+" || instr == "-")
        return 1;
    else
        return 0;
}

#endif //BET_HPP
