// https://leetcode.com/problems/edit-distance/description/

// Top Down Approach
// T.C. = O(n*m)
// S.C. = O(n*m)

// Bottom Up Approach
// T.C. = O(n*m)
// S.C. = O(n*m)

// Bottom Up Space Optimisation Approach
// T.C. = O(n*m)
// S.C. = O(min(n,m))

// Important Question
// n = text1.length() and m = text2.length()

class Solution {
private:
    int solveTop(string word1, string word2,int i, int j,  vector<vector<int>> &dp){
        // base case
        if (i>=word1.length()){
            return word2.length()-j;
        }
        if (j>=word2.length()){
            return word1.length()-i;
        }

        if (dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if (word1[i] == word2[j]){
            ans = solveTop(word1,word2,i+1,j+1,dp);
        }
        else{
            //insert
            int insertAns  = 1 + solveTop(word1,word2,i,j+1,dp);

            //delete
            int deleteAns = 1 + solveTop(word1,word2,i+1,j,dp);

            //replace
            int replaceAns = 1 + solveTop(word1,word2,i+1,j+1,dp);

            ans = min(insertAns, min(deleteAns,replaceAns));
        }
        return dp[i][j] = ans;
    }

    int solveBottom(string word1, string word2){
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, 0));
        // base case
        for(int i=0;i<=word2.length();i++){
            dp[word1.length()][i] = word2.length() - i;
        }
        for(int i=0;i<=word1.length();i++){
            dp[i][word2.length()] = word1.length() - i;
        }

        for (int i=word1.length()-1;i>=0;i--){
            for (int j=word2.length()-1;j>=0;j--){
                int ans = 0;
                if (word1[i] == word2[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    //insert
                    int insertAns  = 1 + dp[i][j+1];

                    //delete
                    int deleteAns = 1 + dp[i+1][j];

                    //replace
                    int replaceAns = 1 + dp[i+1][j+1];

                    ans = min(insertAns, min(deleteAns,replaceAns));
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }

    int solveBottomSpaceOptimisation(string word1, string word2){
        vector<int> curr(word2.length()+1, 0); 
        vector<int> next(word2.length()+1, 0); 

        // base case
        for(int i=0;i<=word2.length();i++){
            next[i] = word2.length() - i;
        }
        // Important Part of the Question Catch
        // for(int i=0;i<=word1.length();i++){
        //     dp[i][word2.length()] = word1.length() - i;
        // }

        for (int i=word1.length()-1;i>=0;i--){
            for (int j=word2.length()-1;j>=0;j--){

                // catch here of the second base case
                curr[word2.length()] = word1.length() - i;

                int ans = 0;
                if (word1[i] == word2[j]){
                    ans = next[j+1];
                }
                else{
                    //insert
                    int insertAns  = 1 + curr[j+1];

                    //delete
                    int deleteAns = 1 + next[j];

                    //replace
                    int replaceAns = 1 + next[j+1];

                    ans = min(insertAns, min(deleteAns,replaceAns));
                }
                curr[j] = ans;
            }
            next = curr;
        }

        return next[0];
    }
public:
    int minDistance(string word1, string word2) {

        // Top Down Approach
        // vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        // return solveTop(word1,word2,0,0,dp);
        
        // Bottom Up Approach
        // return solveBottom(word1,word2);

        // Bottom Up Space Optimisation Approach
        // base case
        if (word1.length() == 0){
            return word2.length();
        }
        if (word2.length() == 0){
            return word1.length();
        }
        
        return solveBottomSpaceOptimisation(word1,word2);
    }
};