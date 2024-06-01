#include <iostream>
using namespace std;

int fib_top(int n, int *memo){
    // Base Case
    if (n == 0 || n == 1){
        memo[n] = n;
        return memo[n];
    }

    // Check if the result exist
    if (memo[n] != -1){
        return memo[n];
    }
    else{
        memo[n] = fib_top(n-1,memo) + fib_top(n-2,memo);
        return memo[n];
    }
}

int fib_bottom(int n){
    //Creation of DP Array
    int *bottom_memo = new int(n+1);

    // Base Case
    bottom_memo[0] = 0;
    bottom_memo[1] = 1;

    // for rest of the cases
    for (int i=2 ; i<=n ; i++){
        bottom_memo[i] = bottom_memo[i-1] + bottom_memo[i-2];
    }

    return bottom_memo[n];
}

int main(){
    int n = 10;

    // Top Down Approach
    // T.C. = O(n)
    // S.C. = O(n) + O(n)
    int *memo = new int(n+1);

    for (int i=0; i<=n; i++){
        memo[i] = -1;
    }

    cout << fib_top(n,memo) << endl;

    // Bottom up Approach
    // T.C. = O(n)
    // S.C. = O(n) (better than top down approach)
    cout << fib_bottom(n) << endl;
}