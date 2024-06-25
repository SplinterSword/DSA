// https://leetcode.com/problems/guess-number-higher-or-lower-ii/submissions/1296370731/

// Top Down Approach
// T.C. = O(n^3)
// S.C. = O(n^2)

// Bottom Up Approach
// T.C. = O(n^3)
// S.C. = O(n^2)

class Solution {
private:
    int solveTop(int start, int end, vector<vector<int>> &dp){
        if (start >= end){
            return 0;
        }

        if (dp[start][end] != -1){
            return dp[start][end];
        }

        int maxi = INT_MAX;
        for(int i = start; i<=end ; i++){
            maxi= min(maxi,i+max(solveTop(start,i-1,dp),solveTop(i+1,end,dp)));
        }

        return dp[start][end] = maxi;
    }

    int solveBottom(int n){
        vector<vector<int>> dp(n+2, vector<int>(n+2,0));

        for(int start = n; start>=1; start--){
            for (int end=start; end<=n; end++){
                if (start == end){
                    continue;
                }

                int maxi = INT_MAX;
                for(int i = start; i<=end ; i++){
                    maxi= min(maxi,i+max(dp[start][i-1],dp[i+1][end]));
                }

                dp[start][end] = maxi;
            }
        }
        return dp[1][n];
    }
public:
    int getMoneyAmount(int n) {
        
        // Top Down Approach
        // vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        // return solveTop(1,n,dp);

        // Bottom Up Approach
        return solveBottom(n);
    }
};