// Important Question and repeat
// https://www.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1

// Top Down Approach
// T.C. = O(n^2)
// S.C. = O(n^2)

// Bottom Up Approach
// T.C. = O(n^2)
// S.C. = O(n^2)

// Bottom Up Space Optimisation Approach
// T.C. = O()
// S.C. = O()


#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    int bruteForce(int index, int diff, int A[]){
        // Backward Checks
        
        if (index < 0){
            return 0;
        }
        
        int ans = 0;
        for (int j = index-1; j>=0; j--){
            if(A[index]-A[j] == diff){
                ans = max(ans, 1 + bruteForce(j, diff, A));
            }
        }
        
        return ans;
    }
    
    int solveTop(int index, int diff, int A[],unordered_map<int,int> dp[]){
        // Backward Checks
        
        if (index < 0){
            return 0;
        }
        
        if (dp[index].count(diff)){
            return dp[index][diff];
        }
        
        int ans = 0;
        for (int j = index-1; j>=0; j--){
            if(A[index]-A[j] == diff){
                ans = max(ans, 1 + solveTop(j, diff, A, dp));
            }
        }
        
        return dp[index][diff] = ans;
    }
public:
    int lengthOfLongestAP(int A[], int n) {
        
        if (n<=2){
            return n;
        }
        
        // Brute Force Approach
        // int ans = 0;
        
        // For the last two elements of an AP
        // for (int i=0; i<n; i++){
        //     for (int j=i+1; j<n; j++){
        //         ans = max(ans, 2+bruteForce(i, A[j] - A[i], A));
        //     }
        // }
        // return ans;
        
        // Top Down Approach
        int ans = 0;
        unordered_map<int,int> dp[n+1];
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                ans = max(ans, 2+solveTop(i, A[j] - A[i], A,dp));
            }
        }
        return ans;
        
        // Bottom Up Approach
        // int ans = 0;
        // unordered_map<int,int> dp[n+1];
        // for (int i=1; i<n; i++){
        //     for (int j=0; j<i; j++){
        //         int diff = A[i] - A[j];
        //         int count = 1;
                
        //         // check if answer already present
        //         if (dp[j].count(diff)){
        //             count = dp[j][diff];
        //         }
                
        //         dp[i][diff] = 1 + count;
                
        //         ans = max(ans, dp[i][diff]);
        //     }
        // }
        // return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends