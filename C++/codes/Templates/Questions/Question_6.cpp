#include <iostream>
using namespace std;
template <class T,class U>
void minsize(T a,U b)
{
    int size=sizeof(a)>sizeof(b)?a:b;
    if (sizeof(a)==sizeof(b))
    {
        cout<<"Both have the same size\n";
        return;
    }
    cout<<size<<endl;
    return;
}

int main()
{
    minsize(4,5);
    minsize('a',5);
    minsize(5,'b');
    return 0;
}