#include <iostream>
using namespace std;

class pragya
{
    bool prajya;
    public:
    friend void check_prajya(pragya p);
    pragya(bool p)
    {
        prajya=p;
    }
};

void check_prajya(pragya p)
{
    if (p.prajya)
    {
        cout<<"Pragya=Prajya"<<endl;
    }
    else
    {
        cout<<"Pragya is Pragya"<<endl;
    }
}

int main()
{
    pragya p(1);
    check_prajya(p);
    return 0;
}