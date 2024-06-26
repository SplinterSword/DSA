// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

// Top Down Approach
// T.C. = O(n)
// S.C. = O(n)

// Bottom Up Approach
// T.C. = O(n)
// S.C. = O(n)

// Bottom Up Space Optimisation Approach
// T.C. = O(n)
// S.C. = O(1)

// Important Question
// Cause 3-D DP and part-2 modified code

class Solution {
private:
    int solveTop(vector<int> prices, int index, bool buyed, int limit,  vector<vector<vector<int>>> &dp){
        // base case
        if (index == prices.size()){
            return 0;
        }
        if (limit == 0){
            return 0;
        }

        if (dp[index][buyed][limit] != -1){
            return dp[index][buyed][limit];
        }

        int profit = 0;
        if (buyed){
            profit = max((-prices[index] + solveTop(prices,index+1,0,limit,dp)), (0 + solveTop(prices,index+1,1,limit,dp)));
        }
        else{
            profit = max((prices[index] + solveTop(prices,index+1,1,limit-1,dp)),(0 + solveTop(prices,index+1,0,limit,dp)));
        }

        return dp[index][buyed][limit]=profit;
    }

    int solveBottom(vector<int> prices){
        int n = prices.size(); 
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2,vector<int>(3,0)));

        for (int index = n-1; index>=0 ; index--){
            for (int buyed = 1; buyed>=0; buyed--){
                for (int limit = 1; limit <= 2; limit ++){

                    int profit = 0;
                    if (buyed){
                        profit = max((-prices[index] + dp[index+1][0][limit]), (0 + dp[index+1][1][limit]));
                    }
                    else{
                        profit = max((prices[index] + dp[index+1][1][limit-1]),(0 + dp[index+1][0][limit]));
                    }

                    dp[index][buyed][limit]=profit;
                }
            }
        }

        return dp[0][1][2];
    }

    int solveBottomSpaceOptimisation(vector<int> prices){
        int n = prices.size();
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> next(2,vector<int>(3,0));

        for (int index = n-1; index>=0 ; index--){
            for (int buyed = 1; buyed>=0; buyed--){
                for (int limit = 1; limit <= 2; limit ++){

                    int profit = 0;
                    if (buyed){
                        profit = max((-prices[index] + next[0][limit]), (0 + next[1][limit]));
                    }
                    else{
                        profit = max((prices[index] + next[1][limit-1]),(0 + next[0][limit]));
                    }

                    curr[buyed][limit]=profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }
public:
    int maxProfit(vector<int>& prices) {
        // Top Down Approach
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2,vector<int>(3,-1)));
        // return solveTop(prices, 0, 1, 2, dp);

        // Bottom Up Approach
        // return solveBottom(prices);

        // Bottom Up Space Optimisation Approach
        return solveBottomSpaceOptimisation(prices);
    }
};