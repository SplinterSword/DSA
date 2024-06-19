// https://leetcode.com/problems/minimum-sideway-jumps/

// Top Down Approach
// T.C. = O(n*3)
// S.C. = O(n*3)

// Bottom Up Approach
// T.C. = O(n*3)
// S.C. = O(n*3)

class Solution {
private:
    int solveTop(vector<int>& obstacles,int pos, int currlane,int n,vector<vector<int>> &dp){
        // Base Case
        if (pos == n){
            return 0;
        }

        if (dp[pos][currlane] != -1){
            return dp[pos][currlane];
        }

        if (obstacles[pos+1] != currlane){
            return solveTop(obstacles,pos+1,currlane,n,dp);
        }

        // Sideways Jump
        dp[pos][currlane] = INT_MAX;
        for(int i = 1; i<=3; i++){
            if(currlane != i && obstacles[pos] != i){
                dp[pos][currlane] = min(dp[pos][currlane], 1+solveTop(obstacles,pos,i,n,dp));
            }
        }

        return dp[pos][currlane];
    }

    int solveBottom(vector<int>& obstacles){
        int n = obstacles.size() - 1;
        vector<vector<int>> dp(n+1,vector<int>(4,1e9));

        // Base Case
        dp[n][0] = 0;
        dp[n][1] = 0;
        dp[n][2] = 0;
        dp[n][3] = 0;

        for(int i=n-1;i>=0;i--){
            for(int j=1; j<=3 ;j++){

                if (obstacles[i+1] != j){
                    dp[i][j] = dp[i+1][j];
                }

                // Sideways Jump
                int ans = 1e9;
                for(int ip = 1; ip<=3; ip++){
                    if(j != ip && obstacles[i] != ip){
                        ans = min(ans, 1+dp[i+1][ip]);
                    }
                }
                dp[i][j] = ans;
            }
        }

        return min(dp[0][2] ,min(dp[0][1] + 1, dp[0][3] + 1));
    }
public:
    int minSideJumps(vector<int>& obstacles) {

        // Top Down Approach
        // int n = obstacles.size() - 1;
        // vector<vector<int>> dp(n+1,vector<int>(4,-1));
        // return solveTop(obstacles,0,2,n,dp);

        // Bottom up Approach
        return solveBottom(obstacles);


    }
};