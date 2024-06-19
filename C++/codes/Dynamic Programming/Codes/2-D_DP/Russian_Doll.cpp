// https://leetcode.com/problems/russian-doll-envelopes/description/
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


class Solution {
private:
    int DpWithBinarySearch(vector<vector<int>> envelopes){
        int n = envelopes.size();

        if (n==0){
            return 0;
        }
        
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        
        for(int i=1; i<n;i++){
            if(envelopes[i][1]>ans.back()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                // find index of just bada element in ans
                int index = lower_bound(ans.begin(),ans.end(),envelopes[i][1]) - ans.begin();
                ans[index] = envelopes[i][1];
            }
        }
        
        return ans.size();
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        // To sort the vector according to the requirments
        ranges::sort(envelopes, [](const auto& a, const auto& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        return DpWithBinarySearch(envelopes);
    }
};