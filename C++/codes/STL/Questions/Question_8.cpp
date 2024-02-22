#include <iostream>

#include <map> // for map operations
using namespace std;
int main()
{
    // declaring map
    // of char and int
    map<char, int> mp;
    // declaring iterators
    map<char, int>::iterator it;
    map<char, int>::iterator it1;
    map<char, int>::iterator it2;

    // inserting values
    mp['a'] = 5;
    mp['b'] = 10;
    mp['c'] = 15;
    mp['h'] = 20;
    mp['k'] = 30;
    // using lower_bound() to search for 'b'
    // key found
    // "it" has address of key value pair.
    it = mp.lower_bound('b');
    if (it == mp.end())
        cout << "Key-value pair not present in map";
    else
        cout << "Key-value pair returned : "
             << it->first << "->" << it->second;
    cout << endl;
    // using lower_bound() to search for 'd'
    // key not found
    // "it1" has address of next greater key.
    // key - 'h'
    it1 = mp.lower_bound('d');
    if (it1 == mp.end())
        cout << "Key-value pair not present in map";
    else
        cout << "Key-value pair returned : "
             << it1->first << "->" << it1->second;
    cout << endl;
    // using lower_bound() to search for 'p'
    // key not found
    // "it2" has address of next greater key.
    // all keys are smaller, hence returns mp.end()
    it2 = mp.lower_bound('p');

    if (it2 == mp.end())
        cout << "Key-value pair not present in map";
    else
        cout << "Key-value pair returned : "
             << it2->first << "->" << it2->second;
    return 0;
}