#include <iostream>
#include <stack>
using namespace std;

stack<int> deleteMiddle(stack<int> inputStack, int count, int size)
{
    //base case
    if (count == size/2)
    {
        inputStack.pop();
        return inputStack;
    }

    int temp = inputStack.top();
    inputStack.pop();
    count++;
    
    inputStack = deleteMiddle(inputStack, count, size);

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
    int count = 0;
    question = deleteMiddle(question,count,question.size());
    while (question.size() != 0)
    {
        cout<<question.top()<<" ";
        question.pop();
    }
    return 0;
}