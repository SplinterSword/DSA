#include <iostream>
#include <stack>
#include <climits>
#include <vector>
using namespace std;

// T.C. = O(n)
// S.C. = O(n)

vector<int> nextSmallerElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

int maxArea(vector<vector<int>> matrix, int n, int m)
{
    //compute area for first row
    int area = largestRectangleArea(matrix[0]);

    for (int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            //row updated: by previous row's values
            if(matrix[i][j] != 0)
            {
                matrix[i][j] = matrix[i][j] + matrix[i-1][j];
            }
            else
            {
                matrix[i][j] = 0;
            }
        }

        //entire row is updated
        area = max(area,largestRectangleArea(matrix[i]));
    }

    return area;
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
    cout<<maxArea(matrix,4,4)<<endl;

    return 0;
}