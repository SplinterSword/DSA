#include <iostream>
#include <fstream> //header file to enable file handling. It includes classes.
using namespace std;

/*
The useful classes for working with files in c++ are:
1. fstreambase
2. ifstream --> derived from fstreambase
3. ofstream --> derived from fstreamabase
*/

/*
In order to work with files in C++, you will have to open it. Primarily, ther are 2 ways to open a file:
1. using the constructor
2. using the member function open() of the class
*/

int main()
{
    string st="Sparsh Bhai says god is good.\n and he is also very good.";
    //Opening files using constuctor and writing into it
    ofstream out("sample.txt"); //Write Operation, ofstream class is used to open file in write mode and out here is the object variable. It creates a new file and overwrite existing file.
    out<<st;
    out.close();

    //Opening file using constructor and reading it.
    string st2;
    ifstream in("sample.txt"); //Read Operation, ofstream class is used to open file in write mode and out here is the object variable.
    in>>st2; // Only read till space or newline.
    while(in.eof()==0) //object_name.eof() checks whether file pointer is at the end of the file and returns true if it is.
    {
        getline(in,st2); //To read a whole line.
        cout<<st2<<endl;
    }
    in.close();
    //There is pointer system in the file.

    //Read and Write operation on the same file can't be performed simultaniously in the same program without closing it.

    return 0;
}