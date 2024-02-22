#include <iostream>
using namespace std;

int main()
{
    try
    {
        int n;
        cin>>n;
        if(n==1)
        {
            throw 1;
        }
        else if (n==2)
        {
            throw 2.00146;
        }
        else
        {
            throw "Hello world";
        }
    }
    catch(int n)
    {
        cout<<n<<endl;
    }
    catch(double n)
    {
        cout<<n<<endl;
    }
    catch(...)
    {
        cout<<"Hello World"<<endl;
    }
    return 0;
}