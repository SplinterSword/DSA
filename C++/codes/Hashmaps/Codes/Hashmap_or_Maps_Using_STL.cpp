#include <iostream>
#include <map> // functions take T.C. = O(log(n));
#include <unordered_map> // functions take T.C. = O(1) (basically hashmaps);
using namespace std;


int main()
{
    // creation
    unordered_map<string,int> m;

    // insertion
    //1
    pair<string,int> p = make_pair("Babbar",3);
    m.insert(p);

    //2
    pair<string,int> pair2("love",2);
    m.insert(pair2);

    //3
    m["mera"] = 1; // this create as it doesn't exist.

    // what will happen
    m["mera"] = 2; // Just updates not create 

    //Search
    cout << m["mera"] << endl;
    cout << m.at("Babbar") << endl;

    cout << m["unknowKey"] << endl; //this creates an entry coressponding to 0.
    cout << m.at("unknowKey") << endl; // this gives an error if not present.

    //size
    cout << m.size() <<endl;

    // to check presence
    cout << m.count("bro") << endl;
    cout << m.count("love") << endl;

    //erase
    m.erase("love");
    cout << m.size() << endl;


    // to access all element.
    for (auto i:m)
    {
        cout << i.first << " " << i.second << endl;
    }

    //iterator
    unordered_map<string,int> :: iterator it = m.begin();

    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it ++;
    }

    return 0;
}