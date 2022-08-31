#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <map>          // Map stl
#include <iterator>     // Iterator for moving thur list
#include <vector>
#include <utility>
#include <iterator>
using namespace std;

template <typename K, typename V>
class Map
{
public:
    Map();
    ~Map();
    void Insert(K key);
    void printstats();
    void update(K key, V value);            // update key with value.
    bool getLetters(char *filename);
    bool getWords(char *filename);
    bool getNums(char *filename);

private:
    map<K,V> mymap;
    void Clear();
    void Sort(vector<pair<K, V>> & v);
};
#include "map.hpp"
#endif //MAP_H
