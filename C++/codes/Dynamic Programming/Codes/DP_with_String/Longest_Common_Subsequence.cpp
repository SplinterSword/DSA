// https://leetcode.com/problems/longest-common-subsequence/description/

// Top Down Approach
// T.C. = O(n*m)
// S.C. = O(n*m)

// Bottom Up Approach
// T.C. = O(n*m)
// S.C. = O(n*m)

// Bottom Up Space Optimisation Approach
// T.C. = O(n*m)
// S.C. = O(m)

// Important Question
// n = text1.length() and m = text2.length()

class Solution {
private:
    int solveTop(string text1, string text2,int i, int j, vector<vector<int>> &dp){
        // base case
        if (i >= text1.size() || j >= text2.size()){
            return 0;
        }

        if (dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;

        if (text1[i] == text2[j]){
            ans = 1 + solveTop(text1,text2,i+1,j+1,dp);
        }
        else {
            ans = max(solveTop(text1,text2,i+1,j,dp),solveTop(text1,text2,i,j+1,dp));
        }
        return dp[i][j] = ans;
    }

    int solveBottomSpaceOptimisation(string text1, string text2){
        vector<int> curr(text2.size() + 1, 0);
        vector<int> next(text2.size() + 1, 0);

        for (int i = text1.size()-1; i>=0 ; i--){
            for (int j=text2.size()-1; j>=0 ; j--){

                int ans = 0;

                if (text1[i] == text2[j]){
                    ans = 1 + next[j+1];
                }
                else {
                    ans = max(next[j],curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }

        return next[0];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Top Down Approach
        // vector<vector<int>> dp (text1.size() + 1, vector<int>(text2.size() + 1, -1));
        // return solveTop(text1,text2,0,0,dp);

        // Bottom up Approach
        // return solveBottom(text1,text2);

        // Bottom up Space Optimisation Approach
        return solveBottomSpaceOptimisation(text1,text2);
    }
}; 