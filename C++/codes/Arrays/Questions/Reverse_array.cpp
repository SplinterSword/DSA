#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> *a)
{
    int n;
    cout<<"Enter the number of elements you want to enter: ";
    cin>>n;
    int d;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        (*a).push_back(d);
    }
    cout<<endl;
}

vector<int> * reverse(vector<int> *a)
{
    vector<int> *b=new vector<int>;
    for(int i=(*a).size()-1;i>=0;i--)
    {
        (*b).push_back((*a)[i]);
    }
    return b;
}

void display(vector<int> *a)
{
    for(int i=0;i<(*a).size();i++)
    {
        cout<<(*a)[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> *a=new vector<int>;
    vector<int> *b=new vector<int>;
    insert(a);
    b=reverse(a);
    display(b);
    return 0;
}