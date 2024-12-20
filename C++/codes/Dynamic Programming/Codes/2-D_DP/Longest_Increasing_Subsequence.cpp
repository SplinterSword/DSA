// https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
// Very Important Question

// Top Down Approach
// T.C. = O(n^2)
// S.C. = O(n^2)

// Bottom Up Approach
// T.C. = O(n^2)
// S.C. = O(n^2)

// Bottom Up Space Optimisation
// T.C. = O(n^2)
// S.C. = O(n*2)

// Dp with Binary Search (Most Optimal Solution)
// T.C. = O(nlog(n))
// S.C. = O(n)


#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    int solveTop(int n, int a[], int curr, int prev,vector<vector<int>> &dp){
        // Base Case
        if (curr == n){
            return 0;
        }
        
        if (dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        
        // include
        int include = 0;
        if (prev == -1 || a[curr] > a[prev]){
            include = 1 + solveTop(n,a,curr+1,curr,dp);
        }
        
        // exclude
        int exclude = 0 + solveTop(n,a,curr+1,prev,dp);
        
        return dp[curr][prev+1] = max(include,exclude);
    }
    
    int solveBottom(int n, int a[]){
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for (int curr = n-1; curr>=0 ;curr--){
            for (int prev = curr-1;prev>=-1;prev--){
                
                int include = 0;
                if (prev == -1 || a[curr] > a[prev]){
                    include = 1 + dp[curr+1][curr+1];
                }
                
                // exclude
                int exclude = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(include,exclude);
            }
        }
        
        return dp[0][0];
    }
    
    int solveBottomSpaceOptimisation(int n, int a[]){
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        
        for (int curr = n-1; curr>=0 ;curr--){
            for (int prev = curr-1;prev>=-1;prev--){
                
                int include = 0;
                if (prev == -1 || a[curr] > a[prev]){
                    include = 1 + nextRow[curr+1];
                }
                
                // exclude
                int exclude = 0 + nextRow[prev+1];
                currRow[prev+1] = max(include,exclude);
            }
            
            nextRow = currRow;
        }
        
        return nextRow[0];
    }
    
    int DpWithBinarySearch(int n, int a[]){
        
        if (n==0){
            return 0;
        }
        
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i=1; i<n;i++){
            if(a[i]>ans.back()){
                ans.push_back(a[i]);
            }
            else{
                // find index of just bada element in ans
                int index = lower_bound(ans.begin(),ans.end(),a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        
        return ans.size();
    }
    
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // Top Down Approach
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return solveTop(n,a,0,-1,dp);
        
        // Bottom Up Approach
        //return solveBottom(n,a);
        
        // Bottom Up Space Optimisation Approach
        // return solveBottomSpaceOptimisation(n,a);
        
        // DP with Binary Search
        return DpWithBinarySearch(n, a);
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends