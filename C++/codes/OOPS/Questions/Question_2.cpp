#include <iostream>
using namespace std;
class base
{
public:
    char fname[20];
    char surname[20];

public:
    virtual void calculate()
    {
        cout << "enter fname:";
        cin >> fname;
        cout << "enter surname";
        cin >> surname;
    }

    void display()
    {
        cout << "welcome" << fname << surname << endl;
    }
};
class derived : public base
{
public:
    void calculate()
    {
        cout << "enter derived_fname:";
        cin >> fname;

        cout << "enter derived_ surname";
        cin >> surname;
    }

    void display()
    {
        cout << "welcome to derived" << fname << surname << endl;
    }
};
int main()
{
    base *a;
    a=new derived;
    a->calculate();
    a->display();
    delete a;
    return 0;
}