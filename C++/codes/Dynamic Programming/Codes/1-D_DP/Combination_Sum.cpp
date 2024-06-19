// https://www.naukri.com/code360/problems/number-of-ways_3755252?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&nps=true&leftPanelTabValue=SUBMISSION

// Top Down Approach
// T.C. = O(tar)
// S.C. = O(tar) + O(tar)

// Bottom Up Approach
// T.C. = O(tar*nums.size())
// S.C. = O(n)

#include <bits/stdc++.h>
int solveTop(vector<int> &nums, int tar,vector<int> &dp){
    if (tar == 0){
        return 1;
    }
    if(tar < 0){
        return 0;
    }

    if (dp[tar] != -1){
        return dp[tar];
    }

    int ans = 0;
    for(int i=0;i<nums.size();i++){
        ans += solveTop(nums,tar-nums[i],dp);
    }

    dp[tar] = ans;
    return dp[tar];
}

int solveBottom(vector<int> &nums, int tar){
    vector<int> dp(tar+1,0);
    dp[0] = 1;

    for(int i=1;i<=tar;i++){
        for(int j=0;j<nums.size();j++){
            if (i-nums[j] >= 0){
                dp[i] += dp[i-nums[j]];
            }
        }
    }
    return dp[tar];
}

int findWays(vector<int> &nums, int tar)
{
    // Top Down Approach
    // vector<int> dp(tar+1,-1);
    // int ans = solveTop(nums,tar,dp);

    // Bottom Up Approach
    int ans = solveBottom(nums,tar);
    return ans;
}