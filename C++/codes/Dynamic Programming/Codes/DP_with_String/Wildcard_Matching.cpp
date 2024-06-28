// https://leetcode.com/problems/wildcard-matching/description/

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
// n = string.length() and m = pattern.length()

class Solution {
private:
    bool solveTop(string &s, string p, int i, int j, vector<vector<int>> &dp){
        // base case
        if (i==0 && j==0){
            return true;
        }
        if (i>0 && j==0){
            return false;
        }
        if (i==0 && j>0){
            for(int k=1; k<=j; k++){
                if (p[k-1] != '*'){
                    return false;
                }
            }
            return true;
        }

        if (dp[i][j] != -1){
            return dp[i][j];
        }

        // Match
        if (s[i-1] == p[j-1] || p[j-1] == '?'){
            return dp[i][j] = solveTop(s,p,i-1,j-1,dp);
        }
        // Star
        else if (p[j-1] == '*'){
            return dp[i][j] = (solveTop(s,p,i-1,j,dp) || solveTop(s,p,i,j-1,dp));
        }
        // No Match
        else {
            return dp[i][j] = false;
        }
    }
    bool solveBottom(string &s, string p){

        vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,0));
        // base case
        dp[0][0] = true;
        for (int j=1; j<=p.length(); j++){
            bool flag = true;
            for(int k=1; k<=j; k++){
                if (p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for (int i=1;i<=s.size();i++){
            for (int j=1;j<=p.size();j++){
                // Match
                if (s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                // Star
                else if (p[j-1] == '*'){
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                }
                // No Match
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[s.size()][p.size()];
    }

    bool solveBottomSpaceOptimisation(string &s, string p){
        vector<int> prev(p.length()+1,0);
        vector<int> curr(p.length()+1,0);
        // base case
        prev[0] = true;
        for (int j=1; j<=p.length(); j++){
            bool flag = true;
            for(int k=1; k<=j; k++){
                if (p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for (int i=1;i<=s.size();i++){
            for (int j=1;j<=p.size();j++){
                // Match
                if (s[i-1] == p[j-1] || p[j-1] == '?'){
                    curr[j] = prev[j-1];
                }
                // Star
                else if (p[j-1] == '*'){
                    curr[j] = (prev[j] || curr[j-1]);
                }
                // No Match
                else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[p.size()];
    }
public:
    bool isMatch(string s, string p) {
        
        // Top Down Approach
        // vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,-1));
        // 1 Based Indexing
        // return solveTop(s,p,s.size(),p.size(),dp);

        // Bottom Up Approach
        // return solveBottom(s,p);

        // Bottom Up Space Optimisation Approach
        return solveBottomSpaceOptimisation(s,p);
    }
};