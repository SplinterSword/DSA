// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/

// Top Down Approach
// T.C. = O(n^3)
// S.C. = O(n^2)

// Bottom Up Approach
// T.C. = O(n^3)
// S.C. = O(n^2)

class Solution {
private: 
    int solveTop(vector<int>& arr,  map<pair<int,int> ,int> maxi, int left, int right,vector<vector<int>> &dp){
        // leaf node (base case)
        if (left == right){
            return 0;
        }

        if (dp[left][right] != -1){
            return dp[left][right];
        }

        int ans = INT_MAX;

        for (int i= left; i<right; i++){
            ans = min(ans, maxi[{left,i}]*maxi[{i+1,right}] + solveTop(arr,maxi,left,i,dp) + solveTop(arr,maxi, i+1, right,dp));
        }

        return dp[left][right] = ans;
    }

    int solveBottom(vector<int>& arr,  map<pair<int,int> ,int> maxi){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int left=arr.size()-1; left >= 0 ; left--){
            for(int right=0; right<=left; right++){

                int ans = INT_MAX;

                for (int i= left; i<right; i++){
                    ans = min(ans, maxi[{left,i}]*maxi[{i+1,right}] + dp[left][i] + dp[i+1][right]);
                }

                dp[left][right] = ans;

            }
        }

        return dp[0][arr.size()-1];
    }

public:
    int mctFromLeafValues(vector<int>& arr) {

        // To store the maximum value of each range
          map<pair<int,int> ,int> maxi;
          for(int i=0; i<arr.size() ; i++){
            maxi[{i,i}] = arr[i];
            for (int j=i+1; j<arr.size(); j++){
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
          }

        // Top Down Approach
        // int n = arr.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveTop(arr, maxi,0,n-1,dp);

        // Bottom Up Approach
        return solveBottom(arr, maxi);
    }
};