#include <iostream>
using namespace std;

// T.C. Optimised=O(M+N)
// S.C. Optimised=O(Max(N,M))
// N and M is 2 linked list

class Node
{
public:
    Node *next;
    int data;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    ~Node()
    {
        delete next;
    }
};

void InsertAthead(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&head, int data)
{
    if (head == NULL)
    {
        InsertAthead(head, data);
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *nodetoinsert = new Node(data);
    temp->next = nodetoinsert;
}

void InsertAtPosition(Node *&head, int index, int data)
{
    if (index == 0)
    {
        InsertAthead(head, data);
        return;
    }
    Node *temp = head;
    int count = 0;
    while (count < index - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        InsertAtTail(head, data);
        return;
    }
    Node *nodetobeinserted = new Node(data);
    nodetobeinserted->next = temp->next;
    temp->next = nodetobeinserted;
}

void deletenode(Node *&head, int index)
{
    if (index == 0)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *temp = head;
        int count = 0;
        while (count < index - 1)
        {
            temp = temp->next;
            count++;
        }
        Node *nodetobedeleted = temp->next;
        temp->next = nodetobedeleted->next;
        nodetobedeleted->next = NULL;
        delete nodetobedeleted;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverse(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

Node *add(Node *first, Node *second)
{
    int carry = 0;
    Node *answer = NULL;

    while (first != NULL || second != NULL || carry !=0)
    {
        int val1=0,val2=0;
        if (first != NULL)
        {
            val1 = first->data;
        }
        if (second != NULL)
        {
            val2 = second->data;
        }

        int sum = carry + val2 + val1;
        int digit = sum % 10;
        InsertAtTail(answer, digit);
        carry = sum / 10;
        
        if (first != NULL)
        {
            first = first->next;
        }
        if (second != NULL)
        {
            second = second->next;
        }
    }
    cout<<endl;

    return answer;
}

Node *addtwolist(Node *first, Node *second)
{
    // step 1 - reverse input LL
    first = reverse(first);
    second = reverse(second);

    // step 2 - add 2 LL
    Node *ans = add(first, second);

    // step 3 - reverse the final answer
    ans = reverse(ans);

    return ans;
}

int main()
{
    Node *head1 = NULL;
    InsertAtPosition(head1, 0, 1);
    InsertAtPosition(head1, 1, 3);
    InsertAtPosition(head1, 2, 5);
    print(head1);

    Node *head2 = NULL;
    InsertAtPosition(head2, 0, 2);
    InsertAtPosition(head2, 1, 4);
    print(head2);

    Node *head = addtwolist(head1, head2);
    print(head);

    return 0;
}