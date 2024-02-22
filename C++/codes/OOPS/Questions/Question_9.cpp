#include <iostream>
using namespace std;

class primary
{
    public:
    void operator == (primary b)
    {
        cout<<"Equal to\n";
    }
    void operator << (primary b)
    {
        cout<<"bitwise to right\n";
    }
    void operator >> (primary b)
    {
        cout<<"bitwise to left\n";
    }
    void operator > (primary b)
    {
        cout<<"greater than\n";
    }
};

int main()
{
    primary a,b;
    a==b;
    a>>b;
    a>b;
    a<<b;
    return 0;
}