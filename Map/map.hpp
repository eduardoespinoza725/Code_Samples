// *******************************************************************************************
// * Name: Assignment 7 WORD COUNT AND THE STL OF YOUR CHOICE.
// * Description: Implement a program that will read input (from standard input) until
// * end of input is reached ("end of file"), which will count the number of times each word,
// * number, and character appears in the input.
// * Author: Eduardo Espinoza
// * Date: July 22, 2022
// *******************************************************************************************
#ifndef MAP_HPP
#define MAP_HPP
#include "map.h"
#include <map>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <iterator>
using namespace std;

// ***************************************************************************************************
// * Constructor: default
// * Description: Default constructor for map<>
// * Parameter Description:
// * Date: July 22, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
Map<K,V>::Map()
= default;

// ***************************************************************************************************
// * Constructor: Destructor
// * Description: Call Clear() to empty the map<>
// * Parameter Description:
// * Date: July 22, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
Map<K,V>::~Map()
{
    Clear();
}

// ***************************************************************************************************
// * Constructor: Insert()
// * Description: Insert pair values. It will not insert a duplicate key. Automatically puts them in
// * order using the map<> built in insert()
// * Parameter Description: A letter, word, or number passed in.
// * Date: July 22, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
void Map<K,V>::Insert(const K key)
{
    int v = 1;
    if (mymap.find(key)->first == key)
    {
        int count = mymap[key];
        ++count;
        update(key, count);
    } else {
        mymap.insert({key, v});
    }
}

// ***************************************************************************************************
// * Constructor: printstats()
// * Description: Transfers over all data to a vector pair and sorts the data by largest total.
// * Parameter Description:
// * Date: July 22, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
void Map<K,V>::printstats()
{
    vector<pair<K,V>> myvec(mymap.begin(), mymap.end());
    //Sort(myvec);

    cout << "\n  T O P  T E N  L I S T " << endl;

    for(int i = 0; i < 10; i++)
    {
        if(i == myvec.size())
            break;
        cout << i + 1 << "->" << " Value: " << myvec[i].first << endl;
        cout << "\tAppears: " << myvec[i].second << " time(s)\n" << endl;
    }
    cout << endl;

//    while(!myvec.empty())
//        myvec.clear();
}

// ***************************************************************************************************
// * Constructor: update()
// * Description: Using key, locate value and replace it with the new value.
// * Parameter Description: A key and value pair.
// * Date: July 22, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
void Map<K,V>::update(const K key, const V value)
{
    // This uses operator [] and operator =
    mymap[key] = value;
}

// ***************************************************************************************************
// * Constructor: getLetters()
// * Description: Opens a file and reads in every individual letter the file holds and inserts them
// * into a map
// * Parameter Description: Filename.
// * Date: July 22, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
bool Map<K,V>::getLetters(char *filename)
{
    ifstream Datafile;
    Datafile.open(filename);

    if(Datafile)
    {
        string data;

        while(getline(Datafile, data))
        {
            // Read in char only
            for(char letter : data)
            {
                // if there is a space, skip over it.
                if (letter == ' ')
                    continue;
                // All elements will be in lowercase.
                else if (isalpha(letter))
                {
                    Insert(tolower(letter));
                }
            }
        }
    }
    Datafile.close();
    return true;
}

// ***************************************************************************************************
// * Constructor: getWords()
// * Description: Opens a file and reads in every individual word the file holds and inserts them
// * into a map
// * Parameter Description: Filename.
// * Date: July 22, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
bool Map<K,V>::getWords(char *filename)
{
    string a;
    ifstream Datafile;
    Datafile.open(filename);

    if(Datafile)
    {
        string data;

        while(getline(Datafile, data))
        {
            for( char word : data)
            {
                // Read in string words only
                if(isalpha(word))
                {
                    // When reading in, it captures one letter at a time
                    // Concatincate every letter to assemble the word.
                    a += word;
                }
                // Included this because every time a symbol is read
                // an empty space is created and inserted into map.
                // This prevents empty spaces from inserting.
                else if(a.empty())
                    a.clear();

                // Every time a space or a non alpha character is read in, insert.
                else if(word == ' ' || !isalpha(word))
                {
                    for(char & i : a)
                        // All elements in lowercase.
                        i = tolower(i);
                    Insert(a);
                    // Delete the word and start over with a new word.
                    a.clear();
                }
            }
        }
    }
    Datafile.close();
    return true;
}

// ***************************************************************************************************
// * Constructor: getNumbers()
// * Description: Opens a file and reads in every individual number the file holds and inserts them
// * into a map
// * Parameter Description: Filename.
// * Date: July 22, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
bool Map<K,V>::getNums(char *filename)
{
    string a;
    ifstream Datafile;
    Datafile.open(filename);

    if(Datafile)
    {
        string data;

        while(getline(Datafile, data))
        {
            for( char num : data)
            {
                // Read in string digits only
                if(isdigit(num))
                {
                    // Concatinate until a letter, space, or symbol is read.
                    a += num;
                }

                // Included this because every time a symbol is read
                // an empty space is created and inserted into map.
                // This prevents empty spaces from inserting.
                else if(a.empty())
                    a.clear();

                // Every time a space or a letter is read in, insert.
                else if(num == ' ' || isalpha(num))
                {
                    Insert(a);
                    // Delete the number and start over with a new number.
                    a.clear();
                }
            }
        }
    }
    Datafile.close();
    return true;
}

// ***************************************************************************************************
// * Constructor: clear()
// * Description: Delete all elements inside of the map.
// * Parameter Description:
// * Date: July 22, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// ***************************************************************************************************
template <typename K, typename V>
void Map<K,V>::Clear()
{
    while(mymap.size() != 0)
        mymap.clear();
}

// ***************************************************************************************************
// * Constructor: Sort() NOTE: IS NOT WORKING IN LINPROG, HAD TO COMMENT IT OUT TO COMPILE.
// * Description: Using vector sort, sort all elements in the vector to be in descending oder.
// * Parameter Description: A vector.
// * Date: July 22, 2022
// * Author: Eduardo Espinoza
// * References: Dr. David A. Gaitros, Mark A. Weiss Data Structures and Algorithm Analysis in C++
// * https://stackoverflow.com/questions/34403415/print-map-values-in-descending-order-in-c
// ***************************************************************************************************
template <typename K, typename V>
void Map<K,V>::Sort(vector<pair<K, V>> & v)
{
    sort(v.begin(), v.end(), [](const auto & lhs, const auto & rhs)
    {
        if(lhs.second == rhs.second)
            return lhs.first < rhs.first;
        return lhs.second > rhs.second;
    });
}

#endif
