#include <iostream>
using namespace std;

//Linked list is the collection of nodes and each node includes a data and the address of the second node,
//Singly linked is is show here. This type of linked list includes nodes only pointing in one way and each node points to only one node.
//This is the foundation of linked list.

class Node
{
    public:
    int data;
    Node* next;
    Node (int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
    ~Node()
    {
        int value = this -> data;
        //memory free
        if (this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"Memory free for value: "<<value<<endl;
    }
};

void InsertAtHead(Node* &head,int d)
{
    //new node create
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

void InsertAtTail(Node* &tail,int data)
{
    //new node create
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}

void InsertAtPosition(Node* &head,Node* &tail,int position,int data)
{
    //Inserting at Start
    if (position==1)
    {
        InsertAtHead(head,data);
        return;
    }

    Node *temp=head;
    int cnt=1;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }

    //Inserting at last position
    if (temp->next==NULL)
    {
        InsertAtTail(tail,data);
        return;
    }

    //creating a node for d
    Node* nodetoinsert=new Node(data);

    nodetoinsert->next=temp->next;

    temp->next=nodetoinsert;
}

void deleteNode(int position,Node* &head)
{
    //deleting first or start node
    if (position==1)
    {
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        //deleting middle or last node
        Node *current=head;
        Node *previous=NULL;
        int cnt=1;
        while(cnt< position)
        {
            cnt++;
            previous=current;
            current=current->next;
        }
        previous->next=current->next;
        current->next=NULL;
        delete current;
    }
}

void print(Node* &head)
{
    //Traversing a linked list
    Node * temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    //created a new node
    Node* node1=new Node(10);
    cout<<node1->data<<" "<<node1->next<<endl;

    //head pointed to node1
    Node* head=node1;
    Node* tail=node1;
    
    InsertAtHead(head,12);

    print(head);

    InsertAtHead(head,15);

    print(head);

    InsertAtTail(tail,16);

    print(head);

    InsertAtPosition(head,tail,3,17);

    print(head);

    InsertAtPosition(head,tail,1,18);

    print(head);

    InsertAtPosition(head,tail,5,19);

    print(head);

    deleteNode(1,head);

    print(head);

    deleteNode(4,head);

    print(head);

    cout<<"Tail: "<<tail->data<<endl;
    cout<<"Head: "<<head->data<<endl;
    return 0;
}