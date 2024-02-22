#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "((a+b))";

    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        // if opening bracket, stack push
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            s.push(ch);
        }
        else
        {
            // for closing bracket
            if (!s.empty())
            {
                if (ch == ')')
                {
                    bool isRedundant = true;
                    while (s.top() != '(')
                    {
                        char top = s.top();
                        if (top == '+' || top == '-' || top == '*' || top == '/')
                        {
                            isRedundant = false;
                        }
                        s.pop();
                    }

                    if (isRedundant == true)
                    {
                        cout << "It is redundant\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Not redundant \n";

    return 0;
}