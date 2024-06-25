// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

// T.C. = O(n)
// S.C. = O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int profit = 0;
        for(int i=1;i<n;i++){
            int diff = prices[i] - mini;
            profit = max(profit, diff);
            mini = min(mini,prices[i]);
        }

        return profit;
    }
};