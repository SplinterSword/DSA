#include <iostream>
using namespace std;

//T.C. = O(1);
//S.C. = O(n+s);

class NStack
{
    int *arr;
    int *top;
    int *next;
    
    int n,s;

    int freespot;
    
    public:

    NStack (int N, int S)
    {
        n=N;
        s=S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        //top initialise
        for (int i=0;i<n;i++)
        {
            top[i] = -1;
        }

        //next initialise
        for (int i=0;i<s;i++)
        {
            next[i] = i+1;
        }

        //update last index value to -1
        next[s-1] = -1;

        //initialise freespot
        freespot = 0;
    }

    bool push(int x, int m)
    {
        //check for overflow
        if(freespot == -1)
        {
            return false;
        }

        //find index
        int index = freespot;

        //update freespot
        freespot = next[index];

        //insert element into the array
        next[index] = top[m-1];

        //update top
        top[m-1] = index;

        return true;
    }

    int pop(int m)
    {
        //check underflow condition
        if (top[m-1] == -1)
        {
            return -1;
        }

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }

};

int main()
{
    NStack a(6,3);
    cout<<a.push(10,1)<<endl;
    cout<<a.push(20,1)<<endl;
    cout<<a.push(20,2)<<endl;
    cout<<a.pop(1)<<endl;
    cout<<a.pop(2)<<endl;
    cout<<a.pop(2)<<endl;
    return 0;
}