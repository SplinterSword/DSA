#include <iostream>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    int arr[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j=j+1){
            cin>>arr[i][j];
        }
    }

    int row_start=0,column_start=0,row_end=n-1,column_end=m-1;

    while(row_start<=row_end and column_end>=column_start){

        for(int col=column_start;col<=column_end;col++){
            cout<<arr[row_start][col]<<" ";
        }
        row_start++;
        
        for(int row=row_start;row<=row_end;row++){
            cout<<arr[row][column_end]<<" ";
        }
        column_end--;

        for(int col=column_end;col>=column_start;col--){
            cout<<arr[row_end][col]<<" ";
        }
        row_end--;

        for(int row=row_end;row>=row_start;row--){
            cout<<arr[row][column_start]<<" ";
        }
        column_start++;

    }

    return 0;
}