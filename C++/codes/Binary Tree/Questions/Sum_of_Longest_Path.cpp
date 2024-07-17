// question link is in lecture no. 64  
// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
// S.C. = O(n)
// T.C. = O(n)

class Solution
{
private:
    void solve(Node *root,int &path,int tempPath,int &sum,int tempSum){
        if (root == NULL){
            if (tempPath>path){
                path = tempPath;
                sum = tempSum;
            }
            else if (path == tempPath && sum < tempSum){
                sum = tempSum;
            }
            return;
        }
        

        solve(root->left,path,tempPath+1,sum,tempSum+root->data);
        solve(root->right,path,tempPath+1,sum,tempSum+root->data);
        
        return;
        
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        if (root == NULL){
            return 0;
        }
        
        int sum = INT_MIN;
        int path = 0;
        solve(root,path,0,sum,0);
        return sum;
        
    }
};