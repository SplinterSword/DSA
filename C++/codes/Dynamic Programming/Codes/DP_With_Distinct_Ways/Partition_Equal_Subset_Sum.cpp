// https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

// Top Down Approach
// T.C. = O(targetSum * N)
// S.C. = O(targetSum*N)

// Bottom Up Approach
// T.C. = O(targetSum * N)
// S.C. = O(targetSum*N)

// Bottom Up Space Optimisation Approach
// T.C. = O(targetSum * N)
// S.C. = O(targetSum*2)

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool solveTop(int N,int arr[], int targetSum, int index, vector<vector<bool>> &dp){
        // Base case
        if (index >= N){
            return 0;
        }
        if (targetSum < 0){
            return 0;
        }
        if (targetSum == 0){
            return 1;
        }
        
        if (dp[targetSum][index] != -1){
            return dp[targetSum][index];
        }
        
        bool include = solveTop(N,arr,targetSum-arr[index],index+1,dp);
        bool exclude = solveTop(N,arr,targetSum,index+1,dp);
        
        return dp[targetSum][index] = (include || exclude);
    }
    
    bool solveBottom(int N,int arr[], int targetSum){
        vector<vector<bool>> dp(targetSum+1,vector<bool>(N+1,0));
        
        // Base case
        for (int i=0;i<N;i++){
            dp[0][i] = 1;
        }
        
        for(int target=1; target <= targetSum; target++){
            for (int index = N-1 ; index >= 0; index--){
                bool include = 0;
                if (target-arr[index] >= 0){
                    include = dp[target-arr[index]][index+1];
                }
                bool exclude = dp[target][index+1];
                dp[target][index] = (include || exclude);
            }
        }
        
        return dp[targetSum][0];
    }
    
    bool solveBottomSpaceOptimisation(int N,int arr[], int targetSum){
        vector<bool> curr(targetSum+1,0);
        vector<bool> next(targetSum+1,0);
        // Base case
        curr[0] = 1;
        next[0] = 1;
        
        for(int index = N-1 ; index >= 0; index--){
            for (int target=1; target <= targetSum; target++){
                
                bool include = 0;
                if (target-arr[index] >= 0){
                    include = next[target-arr[index]];
                }
                bool exclude = next[target];
                curr[target] = (include || exclude);
            }
            next = curr;
        }
        
        return next[targetSum];
    }
public:
    int equalPartition(int N, int arr[])
    {
        int targetSum = 0;
        for (int i=0;i<N;i++){
            targetSum += arr[i];
        }
        
        if (targetSum % 2 != 0){
            return 0;
        }
        
        targetSum  = targetSum / 2;
        
        // Top Down Appraach
        // vector<vector<bool>> dp(targetSum+1,vector<bool>(N+1,-1));
        // return solveTop(N,arr,targetSum,0,dp);
        
        // Bottom Up Approach
        // return solveBottom(N,arr,targetSum);
        
        // Bottom Up Space Optimisation Approach
        return solveBottomSpaceOptimisation(N,arr,targetSum);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends