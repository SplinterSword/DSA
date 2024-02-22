#include <iostream>
using namespace std;

class A
{
    string name,enroll;
    public:
    int getdetails()
    {
        cout<<"Enter the name: ";
        getline(cin,name);
        cout<<"Enter the eno.: ";
        getline(cin,enroll);
    }
};
class B
{
    int *marks=new int[5];
    public:
    int* getmarks()
    {
        for(int i=0;i<5;i++)
        {
            cout<<"Enter the marks of subject "<<i+1<<": ";
            cin>>marks[i];
        }
        return marks;
    }
};
class C: public A,B
{
    public:
    void total()
    {
        A::getdetails();
        int *marks=B::getmarks();
        int total=0;
        for(int i=0;i<5;i++)
        {
            total+=marks[i];
        }
        cout<<"Total= "<<total;
    }
};

int main()
{
    C a;
    a.total();
    return 0;
}