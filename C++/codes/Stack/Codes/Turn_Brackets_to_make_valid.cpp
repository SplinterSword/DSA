#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "}}{}";

    if (str.length() % 2 != 0)
    {
        cout << "String Invalid\n";
        return 0;
    }

    stack<char> s;
    s.push(str[0]);
    int countopen=0,countclose=0;

    for (int i=1 ; i<str.length() ; i++)
    {
        char ch = s.top();
        if (ch == '{' && str[i] == '}')
        {
            s.pop();
            countopen--;
            continue;
        }

        if(str[i] == '{')
        {
            countopen++;
        }
        else if (str[i] == '}')
        {
            countclose++;
        }
        
        s.push(str[i]);
    }

    cout << (countopen + 1)/2 + (countclose + 1)/2 <<endl;

    return 0;
}