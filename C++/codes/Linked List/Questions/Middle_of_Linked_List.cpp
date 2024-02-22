#include <iostream>
using namespace std;

//T.C. Optimised=O(n/2)
//S.C. Optimised=O(1)

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

int midelement(Node *&head)
{
    int len = 0, mid;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    mid = len / 2;

    temp = head;
    len = 0;

    while (len < mid)
    {
        temp = temp->next;
        len++;
    }

    return temp->data;
}

int optimisedmidelement(Node *&head)
{
    if (head == NULL)
    {
        return -1;
    }
    else if (head->next == NULL)
    {
        return head->data;
    }
    else if (head->next->next == NULL)
    {
        return head->next->data;
    }
    else
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
        }

        return slow->data;
    }
}

int main()
{
    Node *head = NULL;
    InsertAtPosition(head, 0, 0);
    InsertAtPosition(head, 1, 1);
    InsertAtPosition(head, 2, 2);
    InsertAtPosition(head, 3, 3);
    InsertAtPosition(head, 4, 4);
    InsertAtPosition(head, 5, 5);
    print(head);
    cout << "Middle element of the list is: " << midelement(head) << endl;
    cout << "Middle element of the list is: " << optimisedmidelement(head) << endl;
    return 0;
}