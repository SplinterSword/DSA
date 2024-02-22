#include <iostream>
#include <vector>
using namespace std;

// T.C. =O(n)
// S.C. =O(n)

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

bool checkpalindrome1(Node *&head)
{
    vector<int> arr;
    Node *temp=head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int s=0,e=arr.size()-1;

    while (s<=e)
    {
        if (arr[s] != arr[e])
        {
            return false;
        }
        else
        {
            s++;
            e--;
        }
    }

    return true;
}

Node *getmid(Node *&head)
{
    Node *slow=head;
    Node *fast=head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

Node *reverse(Node *head)
{
    Node *curr=head;
    Node *prev=NULL;
    Node *forward=curr->next;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

bool checkpalindrome2(Node *head)
{
    if (head->next == NULL)
    {
        return true;
    }

    Node *mid=getmid(head);

    Node *temp= mid->next;
    mid->next = reverse(temp);
    temp = mid->next;

    while (temp != NULL)
    {
        if (head->data != temp->data)
        {
            return false;
        }
        head = head->next;
        temp = temp->next;
    }

    return true;
}

int main()
{
    Node *head = NULL;
    InsertAtPosition(head, 0, 1);
    InsertAtPosition(head, 1, 2);
    InsertAtPosition(head, 2, 1);
    InsertAtPosition(head, 3, 1);
    InsertAtPosition(head, 4, 2);
    InsertAtPosition(head, 5, 1);
    print(head);
    cout<<checkpalindrome1(head)<<endl;
    cout<<checkpalindrome2(head)<<endl;
    return 0;
}