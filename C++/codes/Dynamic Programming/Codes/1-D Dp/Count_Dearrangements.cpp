// https://www.naukri.com/code360/problems/count-derangements_873861?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&nps=true&leftPanelTabValue=SUBMISSION

// Top Down Approach
// T.C. = O(n)
// S.C. = O(n) + O(n)

// Bottom Up Approach
// T.C. = O(n)
// S.C. = O(n)

// Bottom Up Space Optimisation
// T.C. = O(n)
// S.C. = O(1)

#define MOD 1000000007
#include <vector>

long long int solveTop(int n, vector<long long int> &dp){
     // Base Case
    if  (n == 1){
        return 0;
    }
    if (n == 2){
        return 1;
    }

    if (dp[n]!=-1){
        return dp[n];
    }

    long long int ans = ((n-1)%MOD) * ((solveTop(n-1,dp)%MOD)+(solveTop(n-2,dp)%MOD));
    dp[n] = ans%MOD;

    return dp[n];
}

long long int solveBottom(int n){
    vector<long long int> dp(n+1,-1);

    // Base Case
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3;i<=n;i++){
        long long int ans = ((i-1)%MOD) * ((dp[i-1]%MOD)+(dp[i-2]%MOD));
        dp[i] = ans%MOD;
    }

    return dp[n];
}

long long int solveBottomSpaceOptimisation(int n){

    // Base Case
    long long int prev1 = 0;
    long long int prev2 = 1;

    for(int i=3;i<=n;i++){
        long long int ans = ((i-1)%MOD) * ((prev1%MOD)+(prev2%MOD));
        ans = ans%MOD;
        prev1 = prev2;
        prev2 = ans;
    }

    return prev2;
}

long long int countDerangements(int n) {
    // Write your code here.
    // vector<long long int> dp(n+1,-1);
    // long long int ans = solveTop(n, dp);
    // long long int ans = solveBottom(n);
    long long int ans = solveBottomSpaceOptimisation(n);
    return ans;
}