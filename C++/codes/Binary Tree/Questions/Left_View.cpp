// question link is in lecture no. 64  
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
// S.C. = O(n)
// T.C. = O(n)

#include <iostream>
#include <queue>
using namespace std;

class node
{
    public:
    int data;
    node *right;
    node *left;

    node (int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void buildtree(node *&root)
{
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;


    if (data == -1)
    {
        root = NULL;
        return;
    }

    root = new node(data);

    cout << "Enter data to the left of " << data << endl;
    buildtree(root->left);
    cout << "Enter data to the right of " << data << endl;
    buildtree(root->right);

}

void inorder (node *&root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void levelordertraversal(node *&root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

void zigzagTraversal(node *&root)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node *temp = q.front();

    }
}

int main()
{
    node *root;
    buildtree(root);
    inorder(root);
    cout << endl;
    levelordertraversal(root);
    return 0;
}