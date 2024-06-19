// https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1

// Top Down Approach
// T.C. = O(n*n)
// S.C. = O(n)

// Bottom Up Approach
// T.C. = O(n*n)
// S.C. = O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        int solveTop(int n,vector<int> &dp){
            // Base Case
            if (n == 0){
                return 0;
            }
            if (dp[n] != -1){
                return dp[n];
            }
            
            dp[n] = n;
            for (int i=1; i*i <= n; i++){
                dp[n] = min(dp[n],1 + solveTop(n-(i*i),dp));
            }
            
            return dp[n];
        }
        
        int solveBottom(int n){
            // Base Case
            vector<int> dp(n+1,INT_MAX);
            dp[0] = 0;
            
            for (int i=1 ; i<=n;i++){
                for (int j=1; j*j <= n; j++){
                    if(i-(j*j)>=0)
                        dp[i] = min(dp[i],1 + dp[i-(j*j)]);
                }
            }
            
            return dp[n];
        }
        
	public:
    	int MinSquares(int n)
    	{
    	    // Top Down Approach
    	    // vector<int> dp(n+1,-1);
    	    // int ans = solveTop(n,dp);
    	    
    	    // Bottom Up Approach
    	    int ans = solveBottom(n);
    	    return ans;
    	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends