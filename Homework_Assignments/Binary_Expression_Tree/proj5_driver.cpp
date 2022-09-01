#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "bet.h"
using namespace std;

int main(void)
{
    BET<string> myinfix1;
    BET<string> myinfix2("4 5 + 5 6 + /");
    BET<string> myinfix3;
    BET<string> myinfix4(myinfix2);
    myinfix2.printInfixExpression();
    cout <<"Number of Leaf Nodes  in myinfix2: "<<myinfix2.leaf_nodes() <<endl;
    cout <<"Size of myinfix2: "<<myinfix2.size() <<endl;
    string instr;
    cout<<"Enter in a postfix notation: ";
    getline(cin, instr);
    myinfix1.buildFromPostfix(instr);
    myinfix1.printInfixExpression();
    cout <<"Number of Leaf Nodes in myinfx1: " <<myinfix1.leaf_nodes()<<endl;
    cout <<"Size of myinfix1: "<<myinfix1.size()<<endl;
    cout <<" Testing the assignment operator= overload" <<endl;
    myinfix3=myinfix2;
    cout<<"Size of myinfix3 (copied from myinfx2) is: " <<myinfix3.size()<<endl;
    myinfix3.printInfixExpression();
    cout <<" Testing the copy constructor, creating myinfix4. " <<endl;
    cout<<"Size of myinfix4 is: " <<myinfix4.size()<<endl;
    myinfix4.printInfixExpression();

    return 0;
}

