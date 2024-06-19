#include <iostream>
#include <vector>
#include <deque>
void sliding_window(vector<int> ans, vector<int> nums, int n, int k)
{
    if (k > n)
    {
        cout << "Enter a Valid Input" << endl;
        return;
    }

    deque<int> indexs;

    int l,r = 0;

    while (r<n)
    {
        while(!indexs.empty() && nums[r] > nums[indexs.back()])
        {
            indexs.pop_back();
        }

        indexs.push_front(r);

        if (l>indexs.front())
        {
            indexs.pop_front();
        }

        if(r + 1 >= k)
        {
            ans.push_back(nums[indexs.front()]);
            l++;
        }
        r++;
    }

}

int main()
{
    vector<int> nums = [1,3,-1,-3,5,3,6,7];
    int k = 3;
    int n = nums.size();

    vector<int> ans; 
    sliding_window(ans,nums,n,k);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout << endl;
}