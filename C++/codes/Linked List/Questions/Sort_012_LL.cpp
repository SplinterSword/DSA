#include <iostream>
#include <map>
using namespace std;

// T.C. Optimised=O(n)
// S.C. Optimised=O(1)

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
        if (this->next!=NULL)
        {
            this->next=NULL;
            delete next;
        }
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

Node *InsertAtTail(Node *&head, int data)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *nodetoinsert = new Node(data);
    temp->next = nodetoinsert;
    return nodetoinsert;
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

void sort_012_with_data_replacement(Node *&head)
{
    int zerocount = 0, onecount = 0, twocount = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zerocount++;
        }
        else if (temp->data == 1)
        {
            onecount++;
        }
        else if (temp->data == 2)
        {
            twocount++;
        }
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        if (zerocount != 0)
        {
            temp->data = 0;
            zerocount--;
        }
        else if (onecount != 0)
        {
            temp->data = 1;
            onecount--;
        }
        else if (twocount != 0)
        {
            temp->data = 2;
            twocount--;
        }
        temp = temp->next;
    }

    return;
}

void sort_012_without_data_replacement(Node *&head)
{
    Node *zerohead = new Node(-1);
    Node *zerotail, *onetail, *twotail;
    Node *onehead = new Node(-1);
    Node *twohead = new Node(-1);

    Node *curr = head;

    // create seperate list 0s, 1s, and 2s
    while (curr != NULL)
    {
        int value = curr->data;

        if (value == 0)
        {
            zerotail = InsertAtTail(zerohead, value);
        }
        else if (value == 1)
        {
            onetail = InsertAtTail(onehead, value);
        }
        else if (value == 2)
        {
            twotail = InsertAtTail(twohead, value);
        }

        curr = curr->next;
    }

    // merge 3 sublist
    if (onehead->next != NULL) // one list is not empty
    {
        zerotail->next = onehead->next;
    }
    else
    {
        zerotail->next = twohead->next;
    }

    onetail->next = twohead->next;
    twotail->next = NULL;

    //setup head
    head = zerohead -> next;

    //delete dummy nodes
    delete zerohead;
    delete onehead;
    delete twohead;
}

int main()
{
    Node *head = NULL;
    InsertAtPosition(head, 0, 1);
    InsertAtPosition(head, 1, 0);
    InsertAtPosition(head, 2, 1);
    InsertAtPosition(head, 3, 2);
    InsertAtPosition(head, 4, 2);
    print(head);
    sort_012_with_data_replacement(head);
    print(head);
    delete head;
    head = NULL;
    InsertAtPosition(head, 0, 1);
    InsertAtPosition(head, 1, 0);
    InsertAtPosition(head, 2, 1);
    InsertAtPosition(head, 3, 2);
    InsertAtPosition(head, 4, 2);
    print(head);
    sort_012_without_data_replacement(head);
    print(head);
    return 0;
}