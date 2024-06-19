// https://www.geeksforgeeks.org/problems/dice-throw5349/1

// Top Down Approach
// T.C. = O(N*X*M)
// S.C. = O(k^2)

// Bottom Up Approach
// T.C. = O(N*X*M)
// S.C. = O(k^2)

// Bottom Up Space Optimisation Approach
// T.C. = O(N*X*M)
// S.C. = O(X*2)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        long long solveTop(int dice,int faces,int target,vector<vector<long long>> &dp){
            
            // base cases
            if (target < 0){
                return 0;
            }
            if(dice == 0 && target !=0 ){
                return 0;
            }
            if (target == 0 && dice != 0){
                return 0;
            }
            if (dice == 0 && target == 0){
                return 1;
            }
            
            if (dp[dice][target] != -1){
                return dp[dice][target];
            }
            
            long long ans = 0;
            
            for (int i=1;i<=faces; i++){
                ans = ans + solveTop(dice-1,faces,target-i,dp);
            }
            
            return dp[dice][target] = ans;
        }
        
        long long solveBottom(int dice,int faces,int target){
            
            vector<vector<long long>> dp(dice+1,vector<long long>(target+1,0));
            //base case
            dp[0][0] = 1;
            
            
            for(int i=1;i<=dice;i++){
                for(int j=1;j<=target;j++){
                    
                    long long ans = 0;
                    for (int k=1;k<=faces; k++){
                        if (j-k >= 0){
                            ans = ans + dp[i-1][j-k];
                        }
                    }
                    
                    dp[i][j] = ans;
                }
            }
            
            return dp[dice][target];
        }
        
        long long solveBottomSpaceOptimisation(int dice,int faces,int target){
            
            vector<int> prev(target+1,0);
            vector<int> curr(target+1,0);
            //base case
            prev[0] = 1;
            
            
            for(int i=1;i<=dice;i++){
                for(int j=1;j<=target;j++){
                    
                    long long ans = 0;
                    for (int k=1;k<=faces; k++){
                        if (j-k >= 0){
                            ans = ans + prev[j-k];
                        }
                    }
                    
                    curr[j] = ans;
                }
                prev = curr;
            }
            
            return prev[target];
        }
        
    public:
        long long noOfWays(int M , int N , int X) {
            
            // Top Down Approach
            // vector<vector<long long>> dp(N+1,vector<long long>(X+1,-1));
            // return solveTop(N,M,X,dp);
            
            // Bottom Up Approach
            // return solveBottom(N,M,X);
            
            // Bottom Up Space Optimisation Approach
            return solveBottomSpaceOptimisation(N,M,X);
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends