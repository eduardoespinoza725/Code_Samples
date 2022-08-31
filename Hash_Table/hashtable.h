#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <list>
#include <vector>
#include <functional>
#include <iterator>
#include <utility>
#include <fstream>
#include <iostream>
#include <string>
#include "base64.h"
using namespace std;

// max_prime is used by the helpful functions provided
// to you.
static const unsigned int max_prime = 1301081;
// the default_capacity is used if the initial capacity
// of the underlying vector of the hash table is zero.
static const unsigned int default_capacity = 11;

namespace cop4530
{
    template <typename K, typename V>
    class HashTable
    {
    public:
        explicit HashTable(size_t size = 101);        // Constructor. Create a hashtable, where the size of the vector
                                             // is set to prime_below(size) (where size is default to 101)
        ~HashTable();       // calls clear()

        bool contains(const K & k);                // Check if key k is in the hash table
        bool match(const std::pair<K, V> & kv);     // Check if key-value pair is in the hash table

        bool insert(const std::pair<K, V> & kv);    // Add the key value pair kv into the hash table.
//                                                    // If the key is in the hash table but with a different value
//                                                    // the value should be updated to the new one with kv. Return
//                                                    // true if kv is inserted or the value is updated; return
//                                                    // false otherwise (i.e. if kv is in the hash table)
        bool insert(std::pair<K, V> && kv);
//
        bool remove(const K & k);       // Delete the key k and the corresponing value if it is in the hash table
//                                        // Return true if k is deleted, return false otherwise(if key is not in table)
//
        void clear();    // delete all elements in the hash table, by calling makeEmpty()
        virtual void dump();     // display all entries in the hash table. If an entry contains multiple key-value pairs,
                                 // separate them by a semicolon character :
        virtual size_t size();
//
        virtual bool load(const char * filename);       // load the content of the file with name filename into hash table.
        virtual bool write_to_file(const char * filename); // write all elements into a file with name filename.

    private:
        size_t bucket;                  // size of hashtable
        unsigned long key;
        vector<list<pair<K, V>>>  * htable;

        void makeEmpty();   // delete all elements in the hash table
        void rehash();      // Called when the number of elements in the hash table is greater than size of vector.
        size_t myhash(const K & k);     // return the index of the vector entry where k should be stored.
        unsigned long prime_below(unsigned long);
        void setPrimes(vector<unsigned long> &vprimes);

    };  // End class HashTable

#include "hashtable.hpp"

}   // End namespace cop4530
#endif
