#include <iostream>
#include <string>
using namespace std;

int main(){

    //append(Join to strings)
    string x="fam";
    string y="aily";
    x.append(y); //string_variable_name.append(string which needs to be appended) is used to append another string at the end of the string which is not the argument.
    cout<<x<<endl;
    cout<<y+x<<endl; //+ operator can also be used like append

    //clear(empty the string) and empty(check whether the string is empty or not)
    x.clear(); //clear the string
    if (x.empty()){  //string_variable_name.empty() returns true if the string is empty else returns false.
        cout<<"String is empty\n";
    }
    if (y.empty()==false){
        cout<<"String is not empty\n";
    }

    //erase(remove specific parts of the string), insert(insert string at specific points of the string) and find(finds the index no. where the starting word of the mentioned string is found in the bigger string)
    x="nincompoop";
    x.erase(3,3); //string_variable_name.erase(the index no. from which removal starts,the no. of letter you want to remove) is used to remove specific parts of the string.
    cout<<x<<endl;
    x.insert(3,"com"); //string_variable_name.insert(index no. for where the insert starts, the string you want to insert) insert the given string on the specified index no.
    cout<<x<<endl;
    cout<<x.find("poop")<<endl; //string_variable_name.find(string) finds and returns the index no. of the first letter of the argument string in the given string.

    //string1.compare(string2) gives positive if string1>string2, gives 0 if string1=string2 and gives negative no. if string1<string2.
    cout<<x.compare(y)<<endl; //according to the ascii value of the letter in the string.

    //string.length() or string.size() (returns the length of the string) and string.substr(starting index no.,no. of letter in the substr) (gives the substring of the string).
    cout<<x.length()<<endl;
    cout<<x.substr(3,3)<<endl;

    //how to access or iterate over every element of the string.
    for(int i=0;i<x.length();i++){
        cout<<x[i]<<endl; //you can access any element of the string using index no. just like arrays.
    }


    return 0;
}