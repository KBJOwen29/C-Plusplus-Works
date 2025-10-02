#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert nodes in a binary tree
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        // Create a new node if the root is empty
        return new Node(value);
    }

    // Insert in the left subtree if the value is less than the root value
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    // Insert in the right subtree if the value is greater than the root value
    else {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Inorder traversal to display the tree
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    // Creating the root node with the value 50
    Node* root = new Node(50);

    // Insert more nodes
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    // Inorder traversal to print the tree
    cout << "Inorder traversal of the binary tree: ";
    inorderTraversal(root);

    return 0;
}
