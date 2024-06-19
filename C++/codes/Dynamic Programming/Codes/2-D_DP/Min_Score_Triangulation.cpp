// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

// Top Down Approach
// T.C. = O(n^3)
// S.C. = O(n^2)

// Bottom Up Approach
// T.C. = O(n^3)
// S.C. = O(n^2)

class Solution {
private:
    int solveTop(vector<int>& v,int i,int j,vector<vector<int>> &dp) {
        // base case
        if(i+1 == j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        dp[i][j] = INT_MAX;
        for (int k=i+1;k<j;k++){
            dp[i][j] = min(dp[i][j], v[i]*v[j]*v[k] + solveTop(v,i,k,dp) + solveTop(v,k,j,dp));
        }

        return dp[i][j];
    }

    int solveBottom(vector<int>& v) {
        
        // Base Case
        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (n,0));
      
        for(int i=n-1; i>=0; i--){
            for(int j=i+2;j<n;j++){

                dp[i][j] = INT_MAX;

                for (int k=i+1;k<j;k++){
                    dp[i][j] = min(dp[i][j], v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
                }

            }
        }

        return dp[0][n-1];
    }
public:
    int minScoreTriangulation(vector<int>& values) {

        // Top Down Approach
        // int n = values.size();
        // vector<vector<int>> dp(n, vector<int> (n,-1));
        // return solveTop(values,0,n-1,dp);

        // Bottom Up Approach
        return solveBottom(values);
    }
};