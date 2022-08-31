#include <iostream>
#include "map.h"
using namespace std;

int main() {
    Map<char, int> mymap;
    Map<string, int> myStringMap;
    Map<string, int> myIntMap;
    char *filename;

    cout << "Insert filename: ";
    cin >> filename;


    mymap.getLetters(filename);
    mymap.printstats();

    myStringMap.getWords(filename);
    myStringMap.printstats();

    myIntMap.getNums(filename);
    myIntMap.printstats();

    return 0;
}
