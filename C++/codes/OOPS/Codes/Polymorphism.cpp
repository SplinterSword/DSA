#include <iostream>

using namespace std;

//function overloading
class function_overloading
{
    public:
    void fun()
    {
        cout<<"I am a function with no arguments"<<endl;
    }
    void fun(int x)
    {
        cout<<"I am a function with int argument"<<endl;
    }
    void fun(double x)
    {
        cout<<"I am a function with double argument"<<endl;
    }
    //Each member has same name but is diffentiated by the complier with the help of datatype of the arguement or no. of arguments. This is function overloading.

    ~function_overloading()
    {
        cout<<"Destructor Called"<<endl;
    }
};

//Operator Overloading
class operator_overloading
{
    int age;
    string name;

    public:
    operator_overloading(int a,string n)
    {
        age=a;
        name=n;
    }

    operator_overloading(operator_overloading &a)
    {
        age=a.age;
        name=a.name;
    }

    bool operator == (const operator_overloading &a) //Using this we can change the function of a operator in different function when it uses class objects as operands using this syntax where syntax is dataype operator (operator) (const class_object &variable name/&identifier).
    {
        if (age==a.age && name==a.name)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    ~operator_overloading()
    {
        cout<<"Destructor Called"<<endl;
    }
};

int main()
{
    //accessing different function members of the same class object using different arguements(function overloading).
    function_overloading a;
    a.fun();
    a.fun(4);
    a.fun(4.0);

    //Accessing operator overloading
    operator_overloading c(19,"Sparsh");
    operator_overloading b=c; //using copy constructor.
    if (b==c) //Here == will be overloaded(Operator Overloaded).
    {
        cout<<"Same"<<endl;
    }
    else
    {
        cout<<"Different"<<endl;
    }

    return 0;
    //Variable names for different class objects cannot be the same.
}