#include <iostream>
#include <string>
using namespace std;

int Knapsack(int value[],int wt[],int n, int W){

    if(n==0 or W==0){
        return 0;
    }

    if(wt[n-1]>W){
        return Knapsack(value,wt,n-1,W);
    }

    return max(Knapsack(value,wt,n-1,W-wt[n-1])+value[n-1],Knapsack(value,wt,n-1,W));

}

int main(){
    
    int wt[3]={10,20,30};
    int value[3]={100,50,150};
    int W=50;

    cout<<Knapsack(value,wt,3,W)<<endl;
    
    return 0;
}