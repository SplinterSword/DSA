#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    try  // try is the keyword which is used for exception handling where you write the code where you think that code can give an exception.
    {
        if (y == 0)
        {
            throw y; //throw is used to throw values which is catched by the catch block and this exits the catch block.
        }
        else
        {
            cout<<x/y<<endl;
        }
    }
    catch (int j) //catch block have only one arguement which is the data type it has to catch.
    {
        cout<<"Value of denominator can't be zero\n";
    }
    catch (float j) //there can be multiple catch block for different datatypes thrown by the try block.
    {
        cout<<"Float\n";
    }
    catch(...) //... arguement is used to create a default catch block which will handle all the datatype thrown at it by the try block. It should be after all the catch blocks if there is catch blocks for different datatypes.
    {
        cout<<"Default catch block\n";
    }

    return 0;
}