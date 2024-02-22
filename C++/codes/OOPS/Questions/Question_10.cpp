#include <iostream>
using namespace std;

class accounts
{
    static int count;
    string name;
    long int account_no;
    int money=1000;
    char type;
    public:
    void getvalues()
    {
        cout<<"Enter the name: ";
        getline(cin,name);
        cout<<"Enter the account no.: ";
        cin>>account_no;
        cout<<"Enter the type of account\nS for savings and C for Current: ";
        cin>>type;
        count++;
    }
    void deposit()
    {
        int a;
        cout<<"Enter the money you want to deposit: ";
        cin>>a;
        money=money+a;
    }
    void withdraw()
    {
        int a;
        cout<<"Enter the money you want to withdraw: ";
        cin>>a;
        if (money-a<1000)
        {
            cout<<"You can't withdraw more than the minimum balance.";
            return;
        }
        money=money-a;
    }
    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Account No."<<account_no<<endl;
        cout<<"Money: "<<money<<endl;
        cout<<"Type: "<<type<<endl;
        cout<<endl;
    }
};

int accounts::count=1;

int main()
{
    accounts a[10];
    for(int i=0;i<10;i++)
    {
        a[i].getvalues();
        a[i].deposit();
        a[i].withdraw();
        a[i].display();
        cin.ignore();
    }
    return 0;
}