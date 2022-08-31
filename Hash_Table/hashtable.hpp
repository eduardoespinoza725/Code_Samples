// *******************************************************************************************
// * Name: Assignment 6 Hash Tables
// * Description: Implement a hash table ADT and other supporting user interfaces; develop
// * a simple password server program.
// * Author: Eduardo Espinoza
// * Date: July 15, 2022
// *******************************************************************************************

#include <list>
#include <vector>
#include <functional>
#include <iterator>
#include <utility>
#include <fstream>
#include <iostream>
#include <string>
#include "hashtable.h"
#include "base64.h"
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
// * https://www.geeksforgeeks.org/c-program-hashing-chaining/
// ***************************************************************************************************
template <typename K, typename V>
HashTable<K, V>::HashTable(size_t size)
{
    this->bucket = prime_below(size);
    htable = new vector<list<pair<K, V>>>[bucket];
}

// ***************************************************************************************************
// * Constructor: destructor
// * Description: Call clear() to delete all items in the hash table.
// * Parameter Description:
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
HashTable<K, V>::~HashTable()
{
    clear();
}

// ***************************************************************************************************
// * Function: contains()
// * Description: Check if key k is in the hash table.
// * Parameter Description: A string passed in that the funtion will check if it is in the hashtable.
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// * https://www.geeksforgeeks.org/c-program-hashing-chaining/
// ***************************************************************************************************
template <typename K, typename V>
bool HashTable<K, V>::contains(const K & k)
{
    key = myhash(k);
    for(auto iterator = htable[key].begin(); iterator != htable[key].end(); iterator++)
    {
        if(iterator->front().first == k)
        {
            return true;
        }
    }
    return false;
}

// ***************************************************************************************************
// * Function: match()
// * Description: Check if key-value pair is in the hash table.
// * Parameter Description: A string pair, first is the username, second is the password.
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
bool HashTable<K, V>::match(const std::pair<K, V> & kv)
{
    key = myhash(kv.first);
    for(auto iterator = htable[key].begin(); iterator != htable[key].end(); iterator++)
    {
        if(iterator->front().first == kv.first && iterator->front().second == kv.second)
            return true;
    }
    return false;
}

// ***************************************************************************************************
// * Function: insert()
// * Description: add the key-value pair kv into the hash table. Don't add if kv is already in
// * the hash table. If the key is the hash table but with a different value, the value should
// * be updated to the new one with kv. Return true if kv is inserted or the value is updated;
// * return false otherwise (i.e., if kv is in the hash table).
// * Parameter Description: A string pair, first is the username, second is the password.
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// * https://www.geeksforgeeks.org/c-program-hashing-chaining/
// ***************************************************************************************************
template <typename K, typename V>
bool HashTable<K, V>::insert(const std::pair<K, V> & kv)
{
    list<pair<string, string>> templist;

    key = myhash(kv.first);

    if(htable->size() > bucket)
        rehash();
    // If username and password are already in hash table, do nothing.
    if(match(kv))
    {
        return false;
    }
    // If key is already in hash table: update password to new password entered.
    else if(contains(kv.first))
    {
        remove(kv.first);
        templist.push_back(kv);
        htable[key].push_back(templist);
        return true;
    }
    else
    {
        templist.push_back(kv);
        htable[key].push_back(templist);
        return true;
    }
    return false;
}

// ***************************************************************************************************
// * Function: insert()
// * Description: Move version of insert.
// * Parameter Description: A string pair, first is the username, second is the password.
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
bool HashTable<K, V>::insert(std::pair<K, V> && kv)
{
    insert(htable->begin(), std::move(kv));
    return true;
}

// ***************************************************************************************************
// * Function: remove()
// * Description: Delete the key k and the corresponding value if it is in the hash table. Return
// * true if k is deleted, return false otherwise (i.e., if key k is not in the hash table).
// * Parameter Description: A string pair, first is the username, second is the password.
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
bool HashTable<K, V>::remove(const K & k)
{
    key = myhash(k);
    if(contains(k))
    {
        for(auto i = htable[key].begin(); i != htable[key].end(); i++)
        {
            htable[key].erase(i);
            return true;
        }
    }
    return false;
}

// ***************************************************************************************************
// * Function: clear()
// * Description: Delete all elements in the hash table by calling private member function makeEmpty()
// * Parameter Description:
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
void HashTable<K, V>::clear()
{
    if(bucket != 0)
        makeEmpty();
    else
        cout << "Empty List" << endl;
}

// ***************************************************************************************************
// * Function: dump()
// * Description: display all entries in the hash table. If an entry contains multiple key-value pairs,
// * separate them by a semicolon character (:)
// * Parameter Description:
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// * https://www.geeksforgeeks.org/c-program-hashing-chaining/
// ***************************************************************************************************
template <typename K, typename V>
void HashTable<K, V>::dump()
{
    for (int i = 0; i < bucket; i++)
    {
        cout << i;
        for (auto x : htable[i])
            cout << " : " << "[" << x.front().first << " | " << x.front().second << "]";
        cout << endl;
    }
}

// ***************************************************************************************************
// * Function: size()
// * Description: Return the size of the HashTable (the number of username/password pairs in the table).
// * Parameter Description:
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
size_t HashTable<K, V>::size()
{
    int count = 0;
    for (int i = 0; i < bucket; i++)
    {
        for (auto x : htable[i])
            count++;
    }
    return count;
}

// ***************************************************************************************************
// * Function: load()
// * Description: Load a password file into the HashTable object. Each line contains a pair of
// * username and an un-encrypted password. Read in the name and encrypt the password and populate
// * the hash table.
// * Parameter Description: Name of file to open
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
bool HashTable<K, V>::load(const char * filename)
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
                if(insert(temppair))
                    cout << "User " << temppair.first << " successfully added to table." << endl;
                else
                    cout << "Adding user failed." << endl;
            }
            else if(data == "r")
            {
                getline(Datafile,data);
                if(remove(data))
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

                if(insert(temppair))
                    cout << "User " << temppair.first << " password successfully updated." << endl;
                else
                    cout << "User not found" << endl;
            }
            else if(data == "f")
            {
                getline(Datafile,data);
                temppair.first = data;

                if(contains(temppair.first))
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
                bucket = prime_below(sizedata);
                htable = new vector<list<pair<K, V>>>[bucket];
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
// * Description: Write all elements in the hash table into a file with name filename. Similar to the
// * file format in the load function, each line contains a pair of key-value pair, separated by a
// * white space.
// * Parameter Description: Name for output file.
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
bool HashTable<K, V>::write_to_file(const char * filename)
{
    ofstream Datafile;
    Datafile.open(filename);
    for (int i = 0; i < bucket; i++)
    {
        Datafile << i;
        for (auto x : htable[i])
            Datafile << " --> " << "[" << x.front().first << " | " << x.front().second << "]";
        Datafile << endl;
    }
    Datafile.close();
    return true;
}

// ***************************************************************************************************
// * Function: makeEmpty()
// * Description: Delete all elements in the hash table.
// * Parameter Description:
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
void HashTable<K, V>::makeEmpty()
{
    while(bucket != 0)
    {
        htable->clear();
        bucket--;
    }
}

// ***************************************************************************************************
// * Function: rehash()
// * Description: Rehash function. Called when the number of elements in the hash table is greater
// * than the size of the vector.
// * Parameter Description:
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
void HashTable<K, V>::rehash()
{
    int oldsize = bucket;
    bucket *= 2;
    bucket = prime_below(bucket);

    //create new table
    HashTable newTable[bucket];

    // place data from old table to new table.
    for(int i = 0; i < oldsize; i++)
    {
        for(auto iterator = htable[key].begin(); iterator != htable[key].end(); iterator++)
        {
            newTable->insert(iterator->front());
        }
    }
    htable->clear();
}

// ***************************************************************************************************
// * Function: myhash()
// * Description: Return the index of the vector entry where k should be stored.
// * Parameter Description: A String username.
// * Date: July 15, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
size_t HashTable<K, V>::myhash(const K & k)
{
    size_t hashVal = 0;

    for(char ch : k)
        hashVal = 37 * hashVal + ch;
    return hashVal % bucket;
}


// returns largest prime number <= n or zero if input is too large
// This is likely to be more efficient than prime_above(), because
// it only needs a vector of size n
template <typename K, typename V>
unsigned long HashTable<K, V>::prime_below (unsigned long n)
{
    if (n > max_prime)
    {
        std::cerr << "** input too large for prime_below()\n";
        return 0;
    }
    if (n == max_prime)
    {
        return max_prime;
    }
    if (n <= 1)
    {
        std::cerr << "** input too small \n";
        return 0;
    }

    // now: 2 <= n < max_prime
    std::vector <unsigned long> v (n+1);
    setPrimes(v);
    while (n > 2)
    {
        if (v[n] == 1)
            return n;
        --n;
    }

    return 2;
}

//Sets all prime number indexes to 1. Called by method prime_below(n)
template <typename K, typename V>
void HashTable<K, V>::setPrimes(std::vector<unsigned long>& vprimes)
{
    int i = 0;
    int j = 0;

    vprimes[0] = 0;
    vprimes[1] = 0;
    int n = vprimes.capacity();

    for (i = 2; i < n; ++i)
        vprimes[i] = 1;

    for( i = 2; i*i < n; ++i)
    {
        if (vprimes[i] == 1)
            for(j = i + i ; j < n; j += i)
                vprimes[j] = 0;
    }
}

