#include <iostream>
using namespace std;

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

        //One node
        if (curr == prev)
        {
            tail = NULL;
            return;
        }

        //2 of more nodes
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
    if (tail==NULL)
    {
        cout<<"List is empty\n";
    }
    
    Node *temp = tail;

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
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
    return 0;
}