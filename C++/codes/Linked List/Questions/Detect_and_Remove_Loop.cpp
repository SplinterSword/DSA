#include <iostream>
#include <map>
using namespace std;

// Map wala
// T.C.=O(n)
// S.C.=O(n)

// Floyd's Cycle detection algorithm
// T.C.=O(n)
// S.C.=O(1)

// Only tail is needed in circular linked list.
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    ~Node()
    {
        int value = data;
        if (next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout << "The value being deleted is: " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int data)
{
    // assuming that the element is present in the list

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empty list
        // assuming that element is present in the list

        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element found -> curr is representing element wala node
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node *&tail, int element)
{
    // empty list
    if (tail == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }
    else
    {
        // non empty
        // assuming that "value" is present in the linked list
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }

        // One node
        if (curr == prev)
        {
            tail = NULL;
            return;
        }

        // 2 of more nodes
        if (tail == curr)
        {
            tail = prev;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "List is empty\n";
    }

    Node *temp = tail;

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

bool detectLoop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    map<Node* , bool> visited;

    Node* temp = head;

    while (temp != NULL)
    {
        //cycle is present
        if (visited[temp] == true)
        {
            cout<<"Present in :"<<temp->data<<endl;
            return 1;
        }

        visited[temp] = true;
        temp = temp->next;    
    }

    return false;
}

bool floydloop(Node *&head)
{
    if (head == NULL)
    {
        return false;
    }

    Node *slow=head;
    Node *fast=head;

    while(fast!=NULL && slow!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }

        slow = slow -> next;

        if (slow == fast)
        {
            cout<<"present at "<<slow->data<<endl;
            return 1;
        }
    }

    return 0;
}

Node* startingNode(Node *&head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *slow=head;
    Node *fast=head;

    while(fast!=NULL && slow!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }

        slow = slow -> next;

        if (slow == fast)
        {
            slow=head;
            if (slow==NULL)
            {
                return NULL;
            }
            break;
        }
    }

    while (slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }

    cout<<"Starting Node: "<<slow->data<<endl;
    return slow;
}

void removeLoop(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *startofloop=startingNode(head);
    Node *temp=startofloop;

    while (temp -> next != startofloop)
    {
        temp = temp -> next;
    }

    temp->next=NULL;
}


int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    insertNode(tail, 3, 5);
    insertNode(tail, 5, 7);
    insertNode(tail, 7, 9);
    insertNode(tail, 5, 6);
    insertNode(tail, 9, 10);
    insertNode(tail, 3, 4);
    deleteNode(tail, 3);
    print(tail);
    cout << detectLoop(tail) << endl;
    cout << floydloop(tail) << endl;
    removeLoop(tail);
    cout << floydloop(tail) << endl;
    return 0;
}