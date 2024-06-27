// https://leetcode.com/problems/longest-palindromic-subsequence/description/

// Bottom Up Space Optimisation Approach
// T.C. = O(n^2)
// S.C. = O(n)

// n is the length of the string

// Important Question based on longest common subsequence

class Solution {
private:
    int solveBottomSpaceOptimisation(string text1, string text2){
        vector<int> curr(text2.size() + 1, 0);
        vector<int> next(text2.size() + 1, 0);

        for (int i = text1.size()-1; i>=0 ; i--){
            for (int j=text2.size()-1; j>=0 ; j--){

                int ans = 0;

                if (text1[i] == text2[j]){
                    ans = 1 + next[j+1];
                }
                else {
                    ans = max(next[j],curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }

        return next[0];
    }
public:
    int longestPalindromeSubseq(string s) {
        string revStr = s;
        reverse(revStr.begin(), revStr.end());
        return solveBottomSpaceOptimisation(s,revStr);
    }
};