#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//T.C. = O(n)
//S.C. = O(n)

int main()
{
    vector<vector<int>> people = {{0,1,0},{0,0,0},{0,1,0}};
    stack<int> s;
    s.push(0);
    s.push(1);
    s.push(2);
    int ans;

    while (s.size() != 1 )
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (people[a][b] == 1)
        {
            s.push(b);
        }
        else if (people[b][a] == 1)
        {
            s.push(a);
        }
    }

    ans = s.top();

    for (int i=0;i<3;i++)
    {
        if (people[ans][i] == 1)
        {
            cout<<-1<<endl;
            return 0;
        }   
    }

    for (int i=0;i<3;i++)
    {
        if (i == ans)
        {
            continue;
        }
        if (people[i][ans] == 0)
        {
            cout<<-1<<endl;
            return 0;
        }   
    }

    cout<<"Celebrity is: "<<ans<<endl;

    return 0;
}