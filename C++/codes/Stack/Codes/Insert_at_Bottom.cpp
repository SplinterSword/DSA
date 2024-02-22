#include <iostream>
#include <stack>
using namespace std;

stack<int> Insert_at_Bottom(stack<int> inputStack, int element)
{
    //base case
    if (inputStack.empty())
    {
        inputStack.push(element);
        return inputStack;
    }

    int temp = inputStack.top();
    inputStack.pop();
    
    inputStack = Insert_at_Bottom(inputStack, element);

    inputStack.push(temp);

    return inputStack;
}

int main()
{
    stack<int> question;
    question.push(5);
    question.push(6);
    question.push(7);
    question.push(8);
    question.push(9);
    question.push(10);
    question = Insert_at_Bottom(question,4);
    while (question.size() != 0)
    {
        cout<<question.top()<<" ";
        question.pop();
    }
    return 0;
}