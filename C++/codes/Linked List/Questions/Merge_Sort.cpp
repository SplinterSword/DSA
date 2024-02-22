#include <iostream>
#include <map>
using namespace std;

// T.C. Optimised=O(nlogn)
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

Node *solve(Node *&first, Node *&second)
{
    // if only one element is present in first
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }
    
    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;

    while (curr2 != NULL && next1 != NULL)
    {
        if ((curr2->data <= next1->data) && (curr2->data >= curr1->data))
        {
            // add node
            curr1->next = curr2;
            Node *next2 = curr2->next;
            curr2->next = next1;

            // update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            // curr1 and next1 ko aage badhana padega
            curr1 = next1;
            next1 = next1->next;
            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }   
        }
    }
    return first;
}

Node *merge(Node *&head1, Node *&head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }

    Node *head;

    if (head1->data <= head2->data)
    {
        head = solve(head1, head2);
    }
    else
    {
        head = solve(head2, head1);
    }

    return head;
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

Node *mergeSort(Node *head)
{
    if (head == NULL || head ->next == NULL)
    {
        return head;
    }

    //break linked list in 2 halves
    Node *mid = getmid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    //recursive call to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    //merge both left and right halve
    Node *result = merge(left,right);

    return result;
}

int main()
{
    Node *head = NULL;
    InsertAtPosition(head, 0, 0);
    InsertAtPosition(head, 1, 1);
    InsertAtPosition(head, 2, 2);
    InsertAtPosition(head, 3, 5);
    InsertAtPosition(head, 4, 2);
    InsertAtPosition(head, 5, 3);
    InsertAtPosition(head, 6, 4);
    print(head);
    head = mergeSort(head);
    print(head);
    return 0;
}