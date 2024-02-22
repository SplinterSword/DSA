#include <iostream>
using namespace std;

class Person {

    protected:
    static int id;
    string name;
    int age;

    public:

    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

int Person::id=0;

class Professor : public Person {

    int publication,cur_id;

    public:
    Professor() {
        Person::id++;
        cur_id=Person::id;
    }

    void getdata() {
        cin>>name>>age>>publication;
    }

    void putdata() {
        cout<<name<<" "<<age<<" "<<publication<<" "<<cur_id<<endl;
    }
};

class Student : public Person {

    int cur_id,marks[6],sum=0;

    public:
    Student() {
        Person::id++;
        cur_id=Person::id;
    }

    void getdata() {
        cin>>name>>age;
        for(int i=0;i<6;i++) {
            cin>>marks[i];
            sum=sum+marks[i];
        }
    }

    void putdata() {
        cout<<name<<" "<<age<<" "<<sum<<" "<<cur_id<<endl;
    }
};

int main() {
    Person *p=new Professor;
    p->getdata();
    p->putdata();
    p=new Student;
    p->getdata();
    p->putdata();
    return 0;
}