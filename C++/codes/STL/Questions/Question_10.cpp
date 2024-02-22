#include <iostream>
#include <map>
using namespace std;


int main()
{
    map<int,string> students;
    students[200]="Alice";
    students[201]="John";
    map<int,string> :: iterator iter=students.find(201);
    if(iter==students.end())
    {
        cout<<"Value not found.";
        return 0;
    }
    cout<<"Value found\n";
    cout<<iter->first<<"-"<<iter->second;
    return 0;
}
