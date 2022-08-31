// *******************************************************************************************
// * Name: Assignment 6 Hash Tables
// * Description: Implement a hash table ADT and other supporting user interfaces; develop
// * a simple password server program.
// * Author: Eduardo Espinoza
// * Date: July 15, 2022
// *******************************************************************************************
#include <list>
#include <iterator>
#include <utility>
#include <iostream>
#include <string>
#include "base64.h"
#include "passserver.h"
#include "hashtable.h"
using namespace std;
using namespace cop4530;

// ***************************************************************************************************
// * Constructor: default
// * Description: Create a hash table and sets the size of the table using the parameter passed in
// * or defaults to 101
// * Parameter Description: Size of the hash table.
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
PassServer::PassServer(size_t size)
{
    passserver = new HashTable<string, string>(size);
}

// ***************************************************************************************************
// * Constructor: Destructor
// * Description: Deletes hash table by calling clear from hashtable.h.
// * Parameter Description:
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
PassServer::~PassServer()
{
    passserver->clear();
}

// ***************************************************************************************************
// * Function: addUser()
// * Description: Add a new username and password. The password passed in is in plaintext, it is
// * encrypted before insertion.
// * Parameter Description: A string pair, first is the username, second is the password.
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
bool PassServer::addUser(std::pair<string, string> &kv)
{
    kv.second = encrypt(kv.second);
    bool tf = passserver->insert(kv);
    return tf;
}

// ***************************************************************************************************
// * Function: addUser()
// * Description: Move version of addUser.
// * Parameter Description: A string pair, first is the username, second is the password.
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
bool PassServer::addUser(std::pair<string, string> && kv)
{
    kv.operator=(kv);
    return true;
}

// ***************************************************************************************************
// * Function: removeUser()
// * Description: Delete an existing user with username k.
// * Parameter Description: A string containing username.
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
bool PassServer::removeUser(const string &k)
{
    if(find(k))
    {
        passserver->remove(k);
        return true;
    }
    else
        return false;
}

// ***************************************************************************************************
// * Function: changePassword()
// * Description: change an existing user's password. Note that both passwords passed in are in
// * plaintext. They are encrypted before interacting with the hash table. If the user is not in the
// * hash table, return false. If p.second does not match the current password, return false. Also
// * return false if the new password and the old password are the same.
// * Parameter Description: A string pair containing username and password.
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
bool PassServer::changePassword(const pair<string, string> &p, const string &newpassword)
{
    pair<string, string> temp;
    string old = p.second;

    temp.first = p.first;
    temp.second = encrypt(p.second);

    if(!passserver->match(temp))
    {
        cout << "Username and password don't match" << endl;
    }
    else if(old == newpassword)
    {
        cout << "New password cannot be the same as old password." << endl;
        return false;
    }
    else if(find(p.first))
    {

        temp.first = p.first;
        temp.second = newpassword;
        bool tf = addUser(temp);

        return tf;
    }
    return false;

}

// ***************************************************************************************************
// * Function: find()
// * Description: Check if a user exists (if user is in the hash table).
// * Parameter Description: A string containing username.
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
bool PassServer::find(const string & user)
{

    if(passserver->contains(user))
        return true;
    return false;
}

// ***************************************************************************************************
// * Function: dump()
// * Description: Show the structure and contents of the HashTable object to the screen. Same format
// * as the dump() function in the HashTable class template.
// * Parameter Description:
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
void PassServer::dump()
{
    passserver->dump();
}

// ***************************************************************************************************
// * Function: size()
// * Description: Return the size of the HashTable (the number of username/password pairs in the table).
// * Parameter Description:
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
size_t PassServer::size()
{
    return passserver->size();
}

// ***************************************************************************************************
// * Function: load()
// * Description: Load a password file into the HashTable object. Each line contains a pair of username
// * and an un-encrypted password. Read in the name and encrypt the password and populate the hash table.
// * Parameter Description: Name of file to open
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
bool PassServer::load(const char *filename)
{
    list<pair<string, string>> templist;
    pair<string, string> temppair;
    ifstream Datafile;
    Datafile.open(filename);
    if(Datafile)
    {
        string data;
        int sizedata;

        while (getline(Datafile, data))
        {
            if (data == "a")
            {
                getline(Datafile,data);
                temppair.first = data;

                getline(Datafile,data);
                temppair.second = data;

                if(addUser(temppair))
                    cout << "User " << temppair.first << " successfully added to table." << endl;
                else
                    cout << "Adding user failed." << endl;
            }
            else if(data == "r")
            {
                getline(Datafile,data);
                if(removeUser(data))
                    cout << "User " << temppair.first << " removed successfully" << endl;
                else
                    cout << "Removed failed" << endl;
            }
            else if(data == "c")
            {
                getline(Datafile,data);
                temppair.first = data;

                getline(Datafile,data);
                temppair.second = data;

                if(addUser(temppair))
                    cout << "User " << temppair.first << " password successfully updated." << endl;
                else
                    cout << "User not found" << endl;
            }
            else if(data == "f")
            {
                getline(Datafile,data);
                temppair.first = data;

                if(find(temppair.first))
                    cout << "User " << temppair.first << " found" << endl;
                else
                    cout << "User " << temppair.first << " not found" << endl;
            }
            else if(data == "d")
            {
                cout << "\nNow displaying hash table: " << endl;
                dump();
                cout << endl;
            }
            else if(data == "s")
            {
                cout << "Hash table size: ";
                cout << size() << endl;
            }
            else if(data == "w")
            {
                cout << "\n** Now writing hash table data to file **" << endl;
                getline(Datafile,data);
                string outputfile = data;
                write_to_file("outtest1");
            }
            else if(data == "x")
            {
                cout << "\n ** Goodbye ** " << endl;
                break;
            }
            else if(isdigit(data[0]))
            {
                sizedata = stoi(data);
                passserver = new HashTable<string, string>(sizedata);
            }
            else
                cout << "\n ** Invalid input, try agian **\n" << endl;

        }
    }
    Datafile.close();
    return true;
}

// ***************************************************************************************************
// * Function: write_to_file()
// * Description: Un-encrypt the password from the data structrure and save the username and password
// * combination into a file. Same format as the write_to_file() function in the HashTable class template.
// * Parameter Description: Name for output file.
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
bool PassServer::write_to_file(const char *filename)
{
    passserver->write_to_file(filename);
    return true;
//    ofstream Datafile;
//    Datafile.open(filename);
//    for (int i = 0; i < bucket; i++)
//    {
//        Datafile << i;
//        for (auto x : htable[i])
//            Datafile << " --> " << "[" << x.front().first << " | " << x.front().second << "]";
//        Datafile << endl;
//    }
//    Datafile.close();
//    return true;
}

// ***************************************************************************************************
// * Function: encrypt()
// * Description: Encrypt the parameter str and return the encrypted string.
// * Parameter Description: String contianing password.
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
string PassServer::encrypt(const string &str)
{
    BYTE charin[MAXSIZE];
    BYTE charout[MAXSIZE];
    for(int i = 0; i < str.length(); i++)
    {
        if (str[i] == '\0')
            break;
        else
            charin[i] = str[i];
    }
    base64_encode(charin, charout, strlen(charin), 1);
    return charout;
}
// ***************************************************************************************************
// * Function: decrypt()
// * Description: Decrypt the parameter str and return the decrypted string.
// * Parameter Description: String contianing password.
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
string PassServer::decrypt(const string &str)
{
    BYTE charin[MAXSIZE];
    BYTE charout[MAXSIZE];
    for(int i = 0; i < str.length(); i++)
    {
        if (str[i] == '\0')
            break;
        else
            charout[i] = str[i];
    }
    base64_decode(charout, charin, strlen(charout));
    return charin;
}