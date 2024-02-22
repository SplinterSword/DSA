#include <iostream>
using namespace std;

class bag
{
    bool colour;
    public:
    bag()
    {
        
    }
    bag(bool c)
    {
        colour=c;
    }
    void check_bag()
    {
        if(colour)
        {
            cout<<"Mera Bag\n";
        }
        else
        {
            cout<<"Pragya ka bag\n";
        }
    }
};

int main()
{
    bag *ptr=NULL;
    ptr=new bag;
    ptr=new bag(1);
    ptr->check_bag();
    return 0;
}