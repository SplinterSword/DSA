#include <iostream>
using namespace std;
class Base
{
};
class Derived : public Base
{
};
int main()
{
    Base *base_ptr = new Derived;
    Base *derived_ptr = dynamic_cast<Base *>(base_ptr);
    if (derived_ptr != NULL)
        cout << "It is working";
    else
        cout << "cannot cast Base* to Derived*";
    return 0;
}