#include <iostream>
using namespace std;

//When parameterized constructors are made you can't take value in the class object the normal way

class student{  //This the creation of class datatype(class defination).
    
    float percent; // This is private as it is written before public:
    
    public: //public: is used to make the class data accessable outside the class (by other objects or functions). Anything written before it will be private.
    string name; //different elements of class datatype.
    int age;
    bool gender;

    void setpercent(float f) //This is how you access private things in a class object.
    {
        percent=f;
    }
    
    void getpercent() //to get private percent variable.
    {
        cout<<"Percent=";
        cout<<percent<<endl;
    }

    student (float f,string n,int a,bool g) //This is how you create a parameterized constructor which is used to insert private data in the class object.
    {
        cout<<"Parameterized Construtor"<<endl;
        percent=f;
        name=n;
        age=a;
        gender=g;
    }

    student (student &a) //This is how you create a copy constructor to copy values from one object to another. &variable name is neccessary when using another class object as a parameter.
    {
        cout<<"Copy Constructor"<<endl;
        percent=a.percent;
        name=a.name;
        age=a.age;
        gender=a.gender;
    }

    ~student() //Destructor is used to destroy an class object when the program is ended.
    {
        cout<<"Destructor Called"<<endl;
    }

    void printInfo() //All the function for one object is defined inside the class object defination.
    {
        
        cout<<"Name=";
        cout<<name<<endl;
        cout<<"Age=";
        cout<<age<<endl;
        cout<<"Gender=";
        cout<<gender<<endl;
    }

    bool check(student &a)
    {
        if (name==a.name && percent==a.percent && gender==a.gender && age==a.age)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}; //this ; is important at the class defination to end it.


int main()
{
    student b(55,"kk",19,0); //This is how you use a constructor.
    b.printInfo();

    student a(99,"Neha",19,1);

    student c=b; //This is how you use a copy constructor.
    c.printInfo();

    if(c.check(b)==1)
    {
        cout<<"Same"<<endl;
    }
    else
    {
        cout<<"Not Same"<<endl;
    }

    return 0;
}