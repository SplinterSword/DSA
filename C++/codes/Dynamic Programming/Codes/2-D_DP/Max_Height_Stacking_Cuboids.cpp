// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/submissions/1287858419/

// Bottom Up Space Optimisation
// T.C. = O(n^2)
// S.C. = O(n*2)

class Solution {
private:

    bool check(vector<int> base, vector<int> newBox){
        if (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2]){
            return true;
        }
        return false;
    }

    int solveBottomSpaceOptimisation(int n, vector<vector<int>> a){
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        
        for (int curr = n-1; curr>=0 ;curr--){
            for (int prev = curr-1;prev>=-1;prev--){
                
                int include = 0;
                if (prev == -1 || check(a[curr], a[prev])){
                    include = a[curr][2] + nextRow[curr+1];
                }
                
                // exclude
                int exclude = 0 + nextRow[prev+1];
                currRow[prev+1] = max(include,exclude);
            }
            
            nextRow = currRow;
        }
        
        return nextRow[0];
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        // step 1 - sort each vector in the given vector and consider the last element height
        for (int i=0;i<cuboids.size();i++){
            sort(cuboids[i].begin(),cuboids[i].end());
        }

        // step 2 - sort all cuboids
        sort(cuboids.begin(),cuboids.end());

        // Use longest increasing subsiquence method to find the last answer
        return solveBottomSpaceOptimisation(cuboids.size(),cuboids);
    }
};