#include <iostream>
using namespace std;

bool isSafe(int* arr,int x,int y,int n)
{
    for (int row=0;row<x;row++)
    {
        if(*(arr+row*n+y)==1)
        {
            return false;
        }
    }

    int row=x;
    int col=y; 
    while(row>=0 &&col>=0)
    {
        if(*(arr+row*n+col)==1)
        {
            return false;
        }
        row--;
        col--;
    }

    row=x;
    col=y; 
    while(row>=0 &&col<n)
    {
        if(*(arr+row*n+col)==1)
        {
            return false;
        }
        row--;
        col++;
    }

    return true;
}

bool nQueen(int* arr,int x,int n)
{
    if(x>=n)
    {
        return true;
    }

    for(int col=0;col<n;col++)
    {
        if(isSafe(arr,x,col,n))
        {
            *(arr+x*n+col)=1;

            if(nQueen(arr,x+1,n))
            {
                return true;
            }

            *(arr+x*n+col)=0;
        }
    }
    return false;
}

int main()
{
    cout<<"Enter the size of the chessboard and the no. of queens: ";
    int n;
    cin>>n;

    int *arr=new int[n*n];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            *(arr+i*n+j)=0;
        }
    }

    nQueen(arr,0,n);

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<*(arr+i*n+j)<<" ";
        }
        cout<<endl;
    }

    return 0;
}