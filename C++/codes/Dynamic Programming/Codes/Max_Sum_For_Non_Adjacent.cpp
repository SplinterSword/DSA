// https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// Top Down Approach
// T.C. = O(n)
// S.C. = O(n) + O(n)

// Bottom Up Approach
// T.C. = O(n)
// S.C. = O(n)

// Bottom Up Approach Space Optimisation
// T.C. = O(n)
// S.C. = O(1)

#include <bits/stdc++.h> 
int solveTop(vector<int> &nums, int n, vector<int> &dp){
    //base case
    if(n < 0){
        return 0;
    }
    if (n == 0){
        return nums[0];
    }

    if (dp[n] != -1){
        return dp[n];
    }

    //Include
    int include = solveTop(nums, n-2,dp) + nums[n];

    //Exclude
    int exclude = solveTop(nums, n-1,dp) + 0;

    dp[n] = max(include,exclude);
    return dp[n];
}

int solveBottom(vector<int> &nums, int n){
    // dp
    vector<int> dp(n+1,0);

    // Base Cases
    dp[0] = nums[0];

    // Rest of the cases
    for(int i=1;i<=n;i++){
        int include = dp[i-2] + nums[i];
        int exclude = dp[i-1] + 0;
        dp[i] = max(include,exclude);
    }

    return dp[n];
}

int solveBottomSpaceOptimisation(vector<int> &nums, int n){
    // Base Cases
    int prev2 = 0;
    int prev1 = nums[0];

    // Rest of the cases
    for(int i=1;i<=n;i++){
        int include = prev2 + nums[i];
        int exclude = prev1 + 0;
        int ans = max(include,exclude);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();

    // Top Down Approach
    // vector<int> dp(n+1,-1);
    // int ans = solveTop(nums,n-1,dp);
    // return ans;

    // Bottom Up Approach
    // int ans = solveBottom(nums,n-1);
    // return ans;

    // Bottom Up Approach Space Optimisation
    int ans = solveBottomSpaceOptimisation(nums,n-1);
    return ans;
}