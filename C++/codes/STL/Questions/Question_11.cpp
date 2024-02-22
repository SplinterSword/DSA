#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string,int> my_map;
    my_map["Cow"]=1;
    my_map["Cat"]=2;
    my_map["lion"]=3;
    map<string,int> :: iterator iter=my_map.find("Cat");
    my_map.erase(iter);
    for(iter=my_map.begin();iter!=my_map.end();iter++)
    {
        cout<<iter->first<<"-"<<iter->second<<endl;
    }
    return 0;
}