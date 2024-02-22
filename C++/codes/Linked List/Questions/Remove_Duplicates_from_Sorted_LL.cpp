#include <iostream>
using namespace std;

// T.C. Optimised=O(n)
// S.C. Optimised=O(n)

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

void removeduplicates(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Node *curr = head;

    while (curr != NULL)
    {
        if ((curr->next != NULL) && curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = temp->next;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
}

int main()
{
    Node *head = NULL;
    InsertAtPosition(head, 0, 0);
    InsertAtPosition(head, 1, 1);
    InsertAtPosition(head, 2, 3);
    InsertAtPosition(head, 3, 3);
    InsertAtPosition(head, 4, 4);
    InsertAtPosition(head, 5, 5);
    removeduplicates(head);
    print(head);
    return 0;
}