// https://www.naukri.com/code360/problems/ninja-and-the-fence_3210208?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&nps=true&leftPanelTabValue=SUBMISSION

// Top Down Approach
// T.C. = O(n)
// S.C. = O(n) + O(n)

// Bottom Up Approach
// T.C. = O(n)
// S.C. = O(n)

// Bottom Up Space Optimisation
// T.C. = O(n)
// S.C. = O(1)

#include <bits/stdc++.h> 
#define MOD 1000000007

int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a,int b){
    return ((a%MOD)* 1LL *(b%MOD))%MOD;
}

int solveTop(int n,int k,vector<int> &dp){
    // Base Case
    if (n==1){
        return k;
    }
    if (n == 2){
        return add(k,mul(k,k-1));
    }
    if (dp[n] != -1){
        return dp[n];
    }
    

    dp[n] = add(mul(solveTop(n-2,k,dp), k-1),mul(solveTop(n-1,k,dp), k-1));
    return dp[n];
    
}

int solveBottom(int n,int k){
    // Base Case
    vector<int> dp(n+1,-1);
    dp[1] = k;
    dp[2] = add(k,mul(k,k-1));
    for(int i=3;i<=n;i++){
        dp[i] = add(mul(dp[i-2], k-1),mul(dp[i-1], k-1));
    }
    return dp[n];
}

int solveBottomSpaceOptimisation(int n,int k){
    // Base Case
    int prev1 = k;
    int prev2 = add(k,mul(k,k-1));
    for(int i=3;i<=n;i++){
        int ans = add(mul(prev1, k-1),mul(prev2, k-1));
        prev1 = prev2;
        prev2 = ans;
    }
    return prev2;
}

int numberOfWays(int n, int k) {
    // Write your code here.

    // Top Down Approach
    // vector<int> dp(n+1,-1);
    // int ans = solveTop(n,k,dp);

    // Bottom Up Approach
    // int ans = solveBottom(n, k);

    // Bottom Up Space Optimisation Approach
    int ans = solveBottomSpaceOptimisation(n, k);
    return ans;
}
