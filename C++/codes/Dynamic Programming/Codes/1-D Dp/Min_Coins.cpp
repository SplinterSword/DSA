// https://www.naukri.com/code360/problems/minimum-elements_3843091?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// Top Down Approach
// T.C. = O(x*n)
// S.C. = O(x)

// Bottom Up Approach
// T.C. = O(x*n)
// S.C. = O(x)

int solveTop (vector<int> &nums, int x,vector<int> &dp){
    if (x == 0){
        return 0;
    }
    if (x<0){
        return INT_MAX;
    }

    if (dp[x] != -1){
        return dp[x];
    }

    dp[x] = INT_MAX;
    for (int i = 0; i<nums.size();i++){
        int ans = solveTop(nums,x-nums[i],dp);
        if (ans != INT_MAX){
            dp[x] = min(dp[x], 1+ans);
        }
    }
    return dp[x];
}

int solveBottom(vector<int> &nums, int x){
    vector<int> dp(x+1,INT_MAX);
    dp[0] = 0;
    
    for(int i=1;i<=x;i++){
        for(int j = 0; j<nums.size(); j++){
            if (i - nums[j] >= 0 && dp[i-nums[j]] != INT_MAX){
                dp[i] = min(dp[i],1+dp[i-nums[j]]);
            }
        }
    }
    return dp[x];
}

int minimumElements(vector<int> &nums, int x)
{
    // Write your code here.
    vector<int> dp(x+1,-1);
    // int ans = solveTop(nums,x,dp);
    int ans = solveBottom(nums,x);

    if (ans == INT_MAX){
        return -1;
    }
    return ans;
}