// Introduction to Balanced Binary Search Tree (BBST) or AVL Trees

// BBST is just a binary search tree which is self balancing.
// Self Balancing means that the tree maintains a height propotional to logarithmic time of number of nodes(log(n) where an is the number of nodes) wheather a node is inserted or deleted from it.

// This is very important or useful as it reduces the insertion, updation, deletion and search time complexity to O(log(n)) in avg case and in worse case it is O(n)

// The BBST keeps itself balanced with the help of tree rotations and tree invariant.
// A Tree invariant is just a property or rule you impose on your tree that must be met after every operations.
// To ensure that the invariant is always satisfied a series of tree rotations are normally applied.

// AVL Trees are a variation of BBST where the height of the left and right subtrees differ by at most one (-1,0,1).
// The height of a tree is defined as the number of edges from the root to the leaf node.
// This is the Tree Invariant of the AVL Tree which keeps the tree balanced

// Now the Implementations

#include <iostream>
using namespace std;

class AVLTreeNode {


    public:
    int data;
    AVLTreeNode* left;
    AVLTreeNode* right;
    int balance;
    int height;
    AVLTreeNode(int data) {
        this -> data = data;
        this -> left = nullptr;
        this -> right = nullptr;
        this -> balance = 0;
        this -> height = 0;
    }
};

bool contains(AVLTreeNode* root, int data) {
    if (root == nullptr) {
        return false;
    }

    if (root -> data == data) {
        return true;
    }    

    if (data < root -> data) { 
        return contains(root -> left, data);
    } else if (data > root -> data) {
        return contains(root -> right, data);
    }

    return false;
}



void update(AVLTreeNode* root) {
    if (root == nullptr) {
        return;
    }

    int leftHeight = root -> left == nullptr ? -1 : root -> left -> height;
    int rightHeight = root -> right == nullptr ? -1 : root -> right -> height;
    root -> height = max(leftHeight, rightHeight) + 1;
    root -> balance = leftHeight - rightHeight;
}

AVLTreeNode* rightRotate(AVLTreeNode* root) {
    AVLTreeNode* newRoot = root -> left;
    root -> left = newRoot -> right;
    newRoot -> right = root;
    update(root);
    update(newRoot);
    return newRoot;
}

AVLTreeNode *leftRotate(AVLTreeNode* root) {
    AVLTreeNode* newRoot = root -> right;
    root -> right = newRoot -> left;
    newRoot -> left = root;
    update(root);
    update(newRoot);
    return newRoot;
}

AVLTreeNode* leftRightRotate(AVLTreeNode* root) {
    root -> left = leftRotate(root -> left);
    return rightRotate(root);
}

AVLTreeNode* rightLeftRotate(AVLTreeNode* root) {
    root -> right = rightRotate(root -> right);
    return leftRotate(root);
}

AVLTreeNode* balance(AVLTreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    // We only take the left or right rotation if the balance is -2 or 2
    if (root -> balance == -2) {
        if (root -> left != nullptr && root -> left -> balance == 1) {
            return leftRightRotate(root);
        }
        return rightRotate(root);
    } else if (root -> balance == 2) {
        if (root -> right != nullptr && root -> right -> balance == -1) {
            return rightLeftRotate(root);
        }
        return leftRotate(root);
    }

    // Else we don't need to balance
    return root;
}

AVLTreeNode* insert(AVLTreeNode* root, int data) {
    if (root == nullptr) {
        return new AVLTreeNode(data);
    }

    if (contains(root, data)) {
        return root;
    }

    if (data < root -> data) {
        root -> left = insert(root -> left, data);
    } else if (data > root -> data) {
        root -> right = insert(root -> right, data);
    }

    update(root);
    return balance(root);
}

AVLTreeNode* deleteValue(AVLTreeNode* root, int data) {
    if (root == nullptr) {
        return root;
    }

    if (data < root -> data) {
        root -> left = deleteValue(root -> left, data);
    } else if (data > root -> data) {
        root -> right = deleteValue(root -> right, data);
    } else {
        if (root -> left == nullptr && root -> right == nullptr) {
            return nullptr;
        } else if (root -> left == nullptr) {
            return root -> right;
        } else if (root -> right == nullptr) {
            return root -> left;
        } else {
            if (root -> left -> height < root-> right -> height) {
                AVLTreeNode* min = root -> right;
                // Finding min in the right subtree
                while (min -> left != nullptr) {
                    min = min -> left;
                }
                root -> data = min -> data;
                root -> right = deleteValue(root -> right, min -> data);
            } else {
                AVLTreeNode* max = root -> left;
                // Finding max in the left subtree
                while (max -> right != nullptr) {
                    max = max -> right;
                }
                root -> data = max -> data;
                root -> left = deleteValue(root -> left, max -> data);
            }
        }
    }

    update(root);
    return balance(root);
}

int main () {
    AVLTreeNode *root = nullptr;

    root = insert(root, 10);

    cout << deleteValue(root, 10) << "\n";
}