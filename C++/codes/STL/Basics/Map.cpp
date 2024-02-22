#include <iostream>
#include <map> // header file to use map
#include <string>
using namespace std;

int main()
{
    map<string,int> marks; // this is how you declare a map. It takes 2 datatypes, 1st is the datatype of Key and 2nd is the datatype of Value.
    marks["Harry"]=98; // this is how you make a key value pair in map or dictionary.
    marks["Jack"]=88;
    marks["Rohan"]=2;
    marks.insert({{"Kozume",169},{"Kuroo",187}}); //map_variable.insert({{diffrent key-value pairs seperated by a comma}}) is also used to insert multiple key value pair at one time
    map<string,int> :: iterator iter; // this is how you declare an iterator of map.
    iter=marks.begin(); // map_variable.begin() points the iterator to the 1st key of the map.
    for(iter=marks.begin();iter!=marks.end();iter++) //map_variable.end() points the iterator to the last key of the map or dictionary.
    {
        cout<<(*iter).first<<" "<<(*iter).second<<"\n"; //(*iterator).first gives the key and (*iterator).second gives the value in the map.
    }
    cout<<"the size of the map is-"<<marks.size()<<endl; //map_variable.size() returns the size of the map i.e. the no. of key value pairs in a map or a dictionary.
    cout<<"The max size is-"<<marks.max_size()<<endl; //map_variable.max_size() returns the maximum size or no. of elements that can be entered in the map or dictionary.
    cout<<"The empty's return value is-"<<marks.empty()<<endl; //map_variable.empty() returns 1 if the map is empty otherwise it returns 0 if map or dictionary is not empty
    return 0;
} 