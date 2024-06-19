// https://leetcode.com/problems/pizza-with-3n-slices/

// Top Down Approach
// T.C. = O(k^2)
// S.C. = O(k^2)

// Bottom Up Approach
// T.C. = O(k^2)
// S.C. = O(k^2)

// Bottom Up Space Optimisation Approach
// T.C. = O(k^2)
// S.C. = O(k)

class Solution {
private:
    int solveTop(int index,int endIndex,vector<int>& slices, int n,vector<vector<int>> &dp){
        // base case
        if (n == 0 || index > endIndex){
            return 0;
        }

        if (dp[index][n] != -1){
            return dp[index][n];
        }
        int include = slices[index] + solveTop(index+2,endIndex,slices,n-1,dp);
        int exclude = 0 + solveTop(index+1,endIndex,slices,n,dp);

        return dp[index][n] = max(include,exclude);
    }

    int solveBottom(vector<int>& slices){
        int k = slices.size();
        // Base case is already initialised with 0
        vector<vector<int>> dp1(k+2,vector<int>(k+2,0));
        vector<vector<int>> dp2(k+2,vector<int>(k+2,0));

        // case 1
        for(int index = k-2;index>=0;index--){
            for (int n = 1; n<=k/3; n++){
                int include = slices[index] +dp1[index+2][n-1];
                int exclude = 0 + dp1[index+1][n];
                dp1[index][n] = max(include,exclude);
            }
        }

        int case1 = dp1[0][k/3];

        // case 2
        for(int index = k-1;index>=1;index--){
            for (int n = 1; n<=k/3; n++){
                int include = slices[index] +dp2[index+2][n-1];
                int exclude = 0 + dp2[index+1][n];
                dp2[index][n] = max(include,exclude);
            }
        }

        int case2 = dp2[1][k/3];

        return max(case1,case2);
    }

    int solveBottomSpaceOptimisation(vector<int>& slices){
        int k = slices.size();
        // Base case is already initialised with 0
        vector<int> prev1(k+2,0);
        vector<int> curr1(k+2,0);
        vector<int> next1(k+2,0);

        vector<int> prev2(k+2,0);
        vector<int> curr2(k+2,0);
        vector<int> next2(k+2,0);

        // case 1
        for(int index = k-2;index>=0;index--){
            for (int n = 1; n<=k/3; n++){
                int include = slices[index] + next1[n-1];
                int exclude = 0 + curr1[n];
                prev1[n] = max(include,exclude);
            }
            next1 = curr1;
            curr1 = prev1;
        }

        int case1 = curr1[k/3];

        // case 2
        for(int index = k-1;index>=1;index--){
            for (int n = 1; n<=k/3; n++){
                int include = slices[index] +next2[n-1];
                int exclude = 0 + curr2[n];
                prev2[n] = max(include,exclude);
            }
            next2 = curr2;
            curr2 = prev2;
        }

        int case2 = curr2[k/3];

        return max(case1,case2);
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        // Top Down Approach
        // int k = slices.size();
        // vector<vector<int>> dp1(k,vector<int>(k,-1));
        // vector<vector<int>> dp2(k,vector<int>(k,-1));
        // int case1 = solveTop(0,k-2,slices,k/3,dp1);
        // int case2 = solveTop(1,k-1,slices,k/3,dp2);
        // return max(case1, case2);

        // Bottom Up Approach
        // return solveBottom(slices);

        // Bottom Up Space Optimisation Approach
        return solveBottomSpaceOptimisation(slices);
    }
};