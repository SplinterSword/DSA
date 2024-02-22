#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "}{";

    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        // if opening bracket, stack push
        if (ch == '{' || ch == '[' || ch == '(')
        {
            s.push(ch);
        }
        else
        {
            // for closing bracket
            if (!s.empty())
            {
                char top = s.top();
                if ((ch == ']' && top == '[') || (ch == '}' && top == '{') || (ch == ')' && top == '('))
                {
                    s.pop();
                }
                else
                {
                    cout << "Not Balanced \n";
                    return 0;
                }
            }
            else
            {
                cout << "Not Balanced \n";
                return 0;
            }
        }
    }

    if (s.empty())
    {
        cout << "Balanced \n";
        return 0;
    }
    else 
    {
       cout << "Not Balanced \n";
        return 0; 
    }

    return 0;
}