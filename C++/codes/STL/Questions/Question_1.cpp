#include <iostream>
#include <vector>
using namespace std;

void insert(vector <int> *a)
{
    static int i=1;
    cout<<"Enter the value for vector "<<i<<endl;
    while (1)
    {
        int n;
        cout<<"Enter the value you want to enter: ";
        cin>>n;
        if(n<0)
        {
            i++;
            break;
        }
        (*a).push_back(n);
    }
}

void display(vector<int> a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}

bool check(int a,vector<int> *b)
{
    for(int i=0;i<(*b).size();i++)
    {
        if (a==(*b)[i])
        {
            return false;
        }
    }
    return true;
}

void insertion_sort(vector<int> *a)
{
    for(int i=1;i<(*a).size();i++)
    {
        int current=(*a)[i];
        int j=i-1;
        while(j>=0 && current<(*a)[j])
        {
            (*a)[j+1]=(*a)[j];
            j--;
        }
        (*a)[j+1]=current;
    }
}

int main()
{
    vector<int> a,b;
    insert(&a);
    insert(&b);
    for(int i=0;i<b.size();i++)
    {
        if(check(b[i],&a))
        {
            a.push_back(b[i]);
        }
    }
    display(a);
    insertion_sort(&a);
    display(a);
    return 0;
}