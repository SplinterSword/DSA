#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int,int> m;
    m[1]=2;
    m[2]=3;
    m[3]=4;
    map<int,int> :: iterator iter;
    int key,value;
    cout<<"Enter the key:";
    cin>>key;
    for(iter=m.begin();iter!=m.end();iter++)
    {
        if(iter->first==key)
        {
            cout<<"Enter a unique key.";
            return 0;
        }
    }
    cout<<"Enter the value:";
    cin>>value;
    m[key]=value;
    for(iter=m.begin();iter!=m.end();iter++)
    {
        cout<<iter->first<<"-"<<iter->second<<endl;
    }
    return 0;
}