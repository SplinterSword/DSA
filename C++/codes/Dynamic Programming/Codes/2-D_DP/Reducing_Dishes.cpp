// https://leetcode.com/problems/reducing-dishes/submissions/1285773847/

// Top Down Approach
// T.C. = O(n^2)
// S.C. = O(n^2)

// Bottom Up Approach
// T.C. = O(n^2)
// S.C. = O(n^2)

// Bottom Up Space Optimisation
// T.C. = O(n^2)
// S.C. = O(n*2)

// Bottom Up Better Space Optimisation
// T.C. = O(n^2)
// S.C. = O(1)

class Solution {
private:
    int solveTop(vector<int>& satisfaction, int index, int time,vector<vector<int>> &dp){
        // Base Case
        if(index == satisfaction.size()){
            return 0;
        }

        if(dp[index][time] != -1){
            return dp[index][time];
        }

        int include = satisfaction[index] * (time) + solveTop(satisfaction,index+1,time+1,dp);
        int exclude = solveTop(satisfaction,index+1,time,dp) + 0;
        dp[index][time] = max(include,exclude);

        return dp[index][time];
    }

    int solveBottom(vector<int>& satisfaction){

        vector<vector<int>> dp(satisfaction.size() + 1,vector<int>(satisfaction.size() + 1,0));
        int n = satisfaction.size();
        
        for (int index = n-1; index>=0; index--){
            for(int time = index; time>=0; time--){
                int include = satisfaction[index] * (time+1) + dp[index+1][time+1];
                int exclude = dp[index+1][time] + 0;
                dp[index][time] = max(include,exclude);
            }
        }

        return dp[0][0];
    }

    int solveBottomSpaceOptimisation(vector<int>& satisfaction){

        int n = satisfaction.size();
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        
        for (int index = n-1; index>=0; index--){
            for(int time = index; time>=0; time--){
                int include = satisfaction[index] * (time+1) + next[time+1];
                int exclude = next[time] + 0;
                curr[time] = max(include,exclude);
            }
            next = curr;
        }

        return next[0];
    }


public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // Necessary step
        sort(satisfaction.begin(),satisfaction.end());

        // Top Down Approach
        // vector<vector<int>> dp(satisfaction.size() + 1,vector<int>(satisfaction.size() + 1,-1));
        // return solveTop(satisfaction,0,1,dp);

        // Bottom Up Approach
        // return solveBottom(satisfaction);

        // Bottom Up Space Optimisation Approach
        return solveBottomSpaceOptimisation(satisfaction);
    }
};