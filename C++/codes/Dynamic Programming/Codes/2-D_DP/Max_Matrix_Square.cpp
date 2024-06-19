// https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

// Top Down Approach
// T.C. = O(m*n)
// S.C. = O(m*n)

// Bottom Up Approach
// T.C. = O(m*n)
// S.C. = O(m*n)

// Bottom Up Space Optimisation Approach
// T.C. = O(m*n)
// S.C. = O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    int bruteForce(vector<vector<int>> mat, int i, int j, int &maxi){
        
        // Base Case
        if (i >= mat.size() || j >= mat[0].size()){
            return 0;
        }
        
        int right = bruteForce(mat,i,j+1,maxi);
        int diagonal = bruteForce(mat,i+1,j+1,maxi);
        int down = bruteForce(mat,i+1,j,maxi);
        
        if (mat[i][j] == 1){
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        }
        else{
            return 0;
        }
    }
    
    int solveTop(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp){
        
        // Base Case
        if (i >= mat.size() || j >= mat[0].size()){
            return 0;
        }
        
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right = solveTop(mat,i,j+1,maxi,dp);
        int diagonal = solveTop(mat,i+1,j+1,maxi,dp);
        int down = solveTop(mat,i+1,j,maxi,dp);
        
        if (mat[i][j] == 1){
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j] = 0;
        }
    }
    
    int solveBottom(vector<vector<int>> &mat, int &maxi){
        
        int row = mat.size();
        int col = mat[0]. size();
        
        // Base case already set in this line of code
        vector<vector<int>> dp(row+1 , vector<int>(col+1,0));
        
        for (int i = row-1 ; i>=0; i--){
            for(int j = col-1; j>=0; j--){
                
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                if (mat[i][j] == 1){
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return dp[0][0];
    }
    
    int solveBottomSpaceOptimisation(vector<vector<int>> &mat, int &maxi){
        
        int row = mat.size();
        int col = mat[0]. size();
        
        // Base case already set in this line of code
        vector<int> curr(col+1,0);
        vector<int> next(col+1,0);
        
        for (int i = row-1 ; i>=0; i--){
            for(int j = col-1; j>=0; j--){
                
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                if (mat[i][j] == 1){
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, curr[j]);
                }
                else{
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        
        return next[0];
    }
    
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        
        // Brute Force
        // int maxi = 0;
        // bruteForce(mat,0,0,maxi);
        // return maxi;
        
        // Top down Approach
        // vector<vector<int>> dp(n, vector<int> (m,-1));
        // int maxi = 0;
        // solveTop(mat,0,0,maxi,dp);
        // return maxi;
        
        // Bottom Up Approach
        // int maxi = 0;
        // solveBottom(mat, maxi);
        // return maxi;
        
        // Space Optimisation Approach
        int maxi = 0;
        solveBottomSpaceOptimisation(mat, maxi);
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}