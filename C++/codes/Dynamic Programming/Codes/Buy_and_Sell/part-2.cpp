// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

// Top Down Approach
// T.C. = O(n)
// S.C. = O(n)

// Bottom Up Approach
// T.C. = O(n)
// S.C. = O(n)

// Bottom Up Space Optimisation Approach
// T.C. = O(n)
// S.C. = O(1)

class Solution {
private:
    int solveTop(vector<int> prices, int index, bool buyed, vector<vector<int>> &dp){
        if (index == prices.size()){
            return 0;
        }

        if (dp[index][buyed] != -1){
            return dp[index][buyed];
        }

        int profit = 0;
        if (buyed){
            profit = max((-prices[index] + solveTop(prices,index+1,0,dp)), (0 + solveTop(prices,index+1,1,dp)));
        }
        else{
            profit = max((prices[index] + solveTop(prices,index+1,1,dp)),(0 + solveTop(prices,index+1,0,dp)));
        }

        return dp[index][buyed]=profit;
    }

    int solveBottom(vector<int> prices){
        int n = prices.size(); 
        vector<vector<int>> dp(n+1, vector<int>(2,0));

        for (int index = n-1; index>=0 ; index--){
            for (int buyed = 1; buyed>=0; buyed--){
                int profit = 0;
                if (buyed){
                    profit = max((-prices[index] + dp[index+1][0]), (0 + dp[index+1][1]));
                }
                else{
                    profit = max((prices[index] + dp[index+1][1]),(0 + dp[index+1][0]));
                }

                dp[index][buyed]=profit;
            }
        }

        return dp[0][1];
    }

    int solveBottomSpaceOptimisation(vector<int> prices){
        int n = prices.size();
        vector<int> curr(2,0);
        vector<int> next(2,0);

        for (int index = n-1; index>=0 ; index--){
            for (int buyed = 1; buyed>=0; buyed--){
                int profit = 0;
                if (buyed){
                    profit = max((-prices[index] + next[0]), (0 + next[1]));
                }
                else{
                    profit = max((prices[index] + next[1]),(0 + next[0]));
                }

                curr[buyed]=profit;
            }
            next = curr;
        }

        return next[1];
    }
public:
    int maxProfit(vector<int>& prices) {
        
        // Top Down Approach
        // int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2,-1));
        // return solveTop(prices,0,1,dp);

        // Bottom Up Approach
        // return solveBottom(prices);

        // Bottom Up Space Optimisation Approach
        return solveBottomSpaceOptimisation(prices);
    }
};