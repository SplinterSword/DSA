#include <iostream>
using namespace std;

class sweet_place
{
    bool scenery;
    public:
    friend class check_sweet_place;
    sweet_place(bool s)
    {
        scenery=s;
    }
};

class check_sweet_place
{
    bool trees;
    public:
    check_sweet_place(bool t)
    {
        trees=t;
    }
    void check(sweet_place s)
    {
        if (trees && s.scenery)
        {
            cout<<"Sweet Place\n";
        }
        else
        {
            cout<<"Not A Sweet Place\n";
        }
    }
};

int main()
{
    sweet_place s(1);
    check_sweet_place c(1);
    c.check(s);
    return 0;
}