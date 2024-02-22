#include <iostream>
#include <stack>
using namespace std;

// T.C. = O(n^2)

stack<int> sortedInsert(stack<int> s, int element)
{
    if (s.empty() || (!s.empty() && s.top() < element))
    {
        s.push(element);
        return s;
    }

    int n = s.top();
    s.pop();

    s=sortedInsert(s,n);

    s.push(n);
    
    return s;
}

stack<int> sortStack(stack<int> inputstack)
{
    if (inputstack.empty())
    {
        return inputstack;
    }

    int temp = inputstack.top();
    inputstack.pop();

    inputstack = sortStack(inputstack);

    inputstack = sortedInsert(inputstack, temp);

    return inputstack;
}

int main()
{
    stack<int> question;
    question.push(5);
    question.push(-2);
    question.push(9);
    question.push(-7);
    question.push(3);
    question.push(10);
    question = sortStack(question);
    while (question.size() != 0)
    {
        cout << question.top() << " ";
        question.pop();
    }
    return 0;
}