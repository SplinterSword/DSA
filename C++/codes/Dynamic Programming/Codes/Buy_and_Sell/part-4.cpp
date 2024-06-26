// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

// Top Down Approach
// T.C. = O(n*k)
// S.C. = O(n*k)

// Bottom Up Approach
// T.C. = O(n*k)
// S.C. = O(n*k)

// Bottom Up Space Optimisation Approach
// T.C. = O(n*k)
// S.C. = O(k)

// part-3 modified codeS

class Solution {
private:
    int solveBottomSpaceOptimisation(vector<int> prices, int k){
        int n = prices.size();
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        vector<vector<int>> next(2,vector<int>(k+1,0));

        for (int index = n-1; index>=0 ; index--){
            for (int buyed = 1; buyed>=0; buyed--){
                for (int limit = 1; limit <= k; limit ++){

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
        return next[1][k];
    }
    
public:
    int maxProfit(int k, vector<int>& prices) {
        // Bottom Up Space Optimisation Approach
        return solveBottomSpaceOptimisation(prices,k);
    }
};