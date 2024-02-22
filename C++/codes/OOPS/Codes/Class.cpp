#include <iostream>
using namespace std;
//Class is a user defined data type
//It is basically the same as a structure from a c language.
//One difference it has from a structure it can't be accessed outside the class datatype.
//It is used in object oriented programming
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
}; //this ; is important at the class defination to end it.


int main()
{
    student a; //declaration of variable of a class datatype.
    a.name="Urvi"; //Normally shows an error as class data is private and can only be accessed in the class(Object Oriented Programming).
    a.age=20;
    a.gender=1;
    a.setpercent(66.6);

    a.getpercent();
    cout<<a.name<<endl;
    cout<<a.age<<endl;
    cout<<a.gender<<endl;

    student arr[3]; // declaration of array of student datatype.
    for(int i=0;i<3;i++)
    {
        float f;
        cout<<"Percent=";
        cin>>f;
        arr[i].setpercent(f);
        cout<<"Name=";
        cin>>arr[i].name;
        cout<<"Age=";
        cin>>arr[i].age;
        cout<<"Gender=";
        cin>>arr[i].gender;
    }

    for(int i=0;i<3;i++)
    {
        arr[i].printInfo(); //This is how you use user defined datatype defined in a class object
    }

    return 0;
}