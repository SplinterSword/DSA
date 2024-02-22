#include <iostream>
using namespace std;

class Node 
{
    public:
    int data;
    Node *next;

    Node (int data)
    {
        this->data = data;
        next = NULL;
    }
    ~Node ()
    {
        if (this->next != NULL)
        {
            this->next = NULL;
        }
        delete next;
    }
};

void InsertAtHead(Node *&head,int data)
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

void InsertAtTail(Node *&head,int data)
{
    if (head == NULL)
    {
        InsertAtHead(head,data);
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *nodetoinsert = new Node(data);
    temp->next = nodetoinsert;
    return;
}

int deletenode(Node *&head)
{
    if (head->next == NULL)
    {
        int ans = head->data;
        delete head;
        head = NULL;
        return ans;
    }

    if (head == NULL)
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *nodetodelete = temp->next;
    temp->next = NULL;
    int ans = nodetodelete->data;
    delete nodetodelete;
    return ans;
}

class Stack
{
    Node *head = NULL;

    public:

    void push(int element)
    {
        InsertAtTail(head,element);
        return;
    }

    int pop()
    {
        if (head == NULL)
        {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return deletenode(head);
    }
};

int main()
{
    Stack a;
    a.push(1);
    a.push(2);
    cout<<a.pop()<<endl;
    cout<<a.pop()<<endl;
    cout<<a.pop()<<endl;
    return 0;
}
