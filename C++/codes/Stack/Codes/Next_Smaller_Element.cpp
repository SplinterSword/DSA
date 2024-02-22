#include <iostream>
#include <stack>
using namespace std;

//T.C = O(n)

int main()
{
    int arr[4] = {2, 1, 4, 3};
    int ans[4];
    stack<int> check;
    check.push(-1);

    for (int i = 3; i >= 0; i--)
    {
        if (check.top() < arr[i])
        {
            ans[i] = check.top();
            check.push(arr[i]);
        }
        else 
        {
            while (check.top() > arr[i])
            {
                check.pop();
            }

            ans[i] = check.top();
            check.push(arr[i]);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}