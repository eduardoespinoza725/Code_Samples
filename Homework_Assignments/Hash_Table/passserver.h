#ifndef PASSSERVER_H
#define PASSSERVER_H
#include <list>
#include <iostream>
#include <vector>
#include <functional>
#include <utility>
#include <fstream>
#include "base64.h"
#include "hashtable.h"
#include <initializer_list>
using namespace std;
using namespace cop4530;

static const unsigned int MAXSIZE = 255;

// ** Adaptor class **
class PassServer : public HashTable<string, string>
{
public:
    explicit PassServer(size_t size = 101);  // Create a hash table of the specified size
                                    // Just need to pass this size to the constructor
                                    // of the HashTable.

    ~PassServer();      // Need to decide what you should do based on design of
                        // PassServer (develop adapter class based on the adaptee
                        // call HashTable) No memory leaks.

    bool addUser(std::pair<string, string> & kv);   // Add a new user and password.
                                                    // The password is in plaintext,
                                                    // encrypt before inserting

    bool addUser(std::pair<string, string> && kv);  // Move version

    bool removeUser(const string & k);      // Delete existing user with username k.

    // Change an existing user's password.
    // Note: that both passwords passed in are in plaintext. Encrypt before interacting
    // with hash table. If the user is not in htable, return false.
    // If p.second does not match the current password and the old password are
    // the same (cannot update password)
    bool changePassword(const pair<string, string> & p , const string & newpassword);

    bool find(const string & user); // Check if user exists in hash table

    void dump() override;    // Show the structure and contents of HashTable object to screen.
                    // Same format as the dump() in hashtable.h

    size_t size() override;  // Return the size of the HashTable (the number of username/password
                    // pairs in the table.

    bool load(const char * filename) override;   // load a password file into the HashTable object
                                        // Each line contains a pair of username and
                                        // un-encrypted password. Read in the name and
                                        // encrypt the pword and populate the hash table.

    bool write_to_file(const char * filename) override;  // Unecrypt the pword from the hash table
                                                // and save the username and pword
                                                // combinations into a file.
                                                // Same format as in write_to_file() in
                                                // hashtable.h

private:
    HashTable<string, string> * passserver;

    static string encrypt(const string & str);
    static string decrypt(const string & str);
};

#endif //PASSSERVER_H
