// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

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
    int solveTop(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>> &dp){
        // base case
        if (index == nums1.size()){
            return 0;
        }

        if (dp[index][swapped] != -1){
            return dp[index][swapped];
        }

        int ans = INT_MAX;

        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        // catch
        if (swapped){
            swap(prev1,prev2);
        }

        // no swap
        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = solveTop(nums1,nums2,index+1,0,dp);
        }

        // swap
        if (nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans, 1+solveTop(nums1,nums2,index+1,1,dp));
        }

        return dp[index][swapped] = ans;
    }

    int solveBottom(vector<int>& nums1, vector<int>& nums2){
        vector<vector<int>> dp(nums1.size()+1,vector<int>(2,0));

        for (int index = nums1.size() - 1; index>=1; index--){
            for(int swapped = 1; swapped >= 0 ; swapped--){

                int ans = INT_MAX;

                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                // catch
                if (swapped){
                    swap(prev1,prev2);
                }

                // no swap
                if(nums1[index] > prev1 && nums2[index] > prev2){
                    ans = dp[index+1][0];
                }

                // swap
                if (nums1[index] > prev2 && nums2[index] > prev1){
                    ans = min(ans, 1+dp[index+1][1]);
                }

                dp[index][swapped] = ans;
            }
        }

        return dp[1][0];
    }

    int solveBottomSpaceOptimisation(vector<int>& nums1, vector<int>& nums2){
        vector<int> next(2,0);
        vector<int> curr(2,0);

        for (int index = nums1.size() - 1; index>=1; index--){
            for(int swapped = 1; swapped >= 0 ; swapped--){

                int ans = INT_MAX;

                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                // catch
                if (swapped){
                    swap(prev1,prev2);
                }

                // no swap
                if(nums1[index] > prev1 && nums2[index] > prev2){
                    ans = next[0];
                }

                // swap
                if (nums1[index] > prev2 && nums2[index] > prev1){
                    ans = min(ans, 1+next[1]);
                }

                curr[swapped] = ans;
            }
            next = curr;
        }

        return next[0];
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);

        // Top Down Approach
        // it means wheather the previous indexes were swapped or not
        // vector<vector<int>> dp(nums1.size()+1,vector<int>(2,-1));
        // bool swapped = 0;
        // return solveTop(nums1, nums2, 1, swapped, dp);

        // Bottom Up Approach
        // return solveBottom(nums1, nums2);

        // Bottom Up Space Optimisation Approach
        return solveBottomSpaceOptimisation(nums1, nums2);
    }
};