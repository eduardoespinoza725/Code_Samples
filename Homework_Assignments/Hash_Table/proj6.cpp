#include <list>
#include <vector>
#include <functional>
#include <iterator>
#include <utility>
#include <fstream>
#include <iostream>
#include <string>
#include "base64.h"
#include "passserver.h"
#include "hashtable.h"
using namespace std;
using namespace cop4530;

// ***************************************************************************************************
// * Driver:
// * Description: Uses menu() to give user options and calls functions, depending on the user input,
// * to fill the hashtable.
// * Parameter Description:
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************

void Menu();

int main() {
    const char * filename = "test1.txt";
    char userinput;
    string userdata;
    pair<string, string> mypair;
    string newPassword;
    PassServer myps;


    Menu();

    cin >> userinput;

    while(userinput != 'x')
    {
        if(userinput == 'l')
        {
            myps.load(filename);
        }
        else if(userinput == 'a')
        {
            cout << "\nEnter string 1: ";
            cin >> mypair.first;
            cout << "Enter string 2: ";
            cin >> mypair.second;
            myps.addUser(mypair);


        }
        else if(userinput == 'r')
        {
            cout << "\nEnter username to remove: ";
            cin >> userdata;
            if(myps.removeUser(userdata))
                cout << "User removed successfully";
            else
                cout << "Removed failed";
        }
        else if(userinput == 'c')
        {
            pair<string, string> temppair;

            cout << "\nEnter current username: ";
            cin >> mypair.first;

            cout << "Enter old password: ";
            cin >> mypair.second;

            cout << "Enter new password: ";
            cin >> newPassword;

            if(myps.changePassword(mypair, newPassword))
                cout << "User password successfully updated.";
            else
                cout << "Error" << endl;
        }
        else if(userinput == 'f')
        {
            cout << "\nEnter username to find: ";
            cin >> mypair.first;

            if(myps.find(mypair.first))
                cout << "User " << mypair.first << " found";
            else
                cout << "No user found";
        }
        else if(userinput == 'd')
        {
            cout << "\nNow displaying hash table: " << endl;
            myps.dump();
        }
        else if(userinput == 's')
        {
            cout << "\nHash table size: ";
            cout << myps.size();
        }
        else if(userinput == 'w')
        {
            cout << "** Now writing hash table data to file **" << endl;
            myps.write_to_file("outtest1");
        }
        else if(userinput == 'x')
        {
            cout << "\nGoodbye" << endl;
        }
        else
            cout << "\n ** Invalid input, try agian **" << endl;

        cout << "\nEnter choice: ";
        cin >> userinput;
    }

    return 0;
}

void Menu()
{
    cout << "\n\n";
    cout << "l - Load From File" << endl;
    cout << "a - Add User" << endl;
    cout << "r - Remove User" << endl;
    cout << "c - Change User Password" << endl;
    cout << "f - Find User" << endl;
    cout << "d - Dump HashTable" << endl;
    cout << "s - HashTable Size" << endl;
    cout << "w - Write to Password File" << endl;
    cout << "x - Exit program" << endl;
    cout << "\nEnter choice : ";
}

