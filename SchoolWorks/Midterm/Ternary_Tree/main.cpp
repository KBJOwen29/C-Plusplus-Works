#include <iostream>
using namespace std;

// Node structure for Ternary Tree
struct Node {
    int data;          // Data value in the node
    Node* left;        // Pointer to the left child
    Node* middle;      // Pointer to the middle child
    Node* right;       // Pointer to the right child

    // Constructor to create a new node
    Node(int val) : data(val), left(nullptr), middle(nullptr), right(nullptr) {}
};

// Insertion operation for Ternary Tree
Node* insert(Node* root, int value) {
    // If root is null, create a new node with the given value
    if (!root) {
        return new Node(value);
    }

    // If value is less than root's data, insert in the left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // If value equals root's data, insert in the middle subtree
    else if (value == root->data) {
        root->middle = insert(root->middle, value);
    }
    // If value is greater, insert in the right subtree
    else {
        root->right = insert(root->right, value);
    }

    // Return the root after insertion
    return root;
}

// Find the minimum value node in the tree (for deletion)
Node* findmin(Node* root) {
    // Find the minimum node by going left till we can't anymore
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

// Deletion operation for Ternary Tree
Node* deleteNode(Node* root, int value) {
    if (!root) return nullptr;  // If the root is null, nothing to delete

    if (value < root->data) {  // If the value to delete is smaller, go left
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {  // If the value is greater, go right
        root->right = deleteNode(root->right, value);
    } else {  // If value matches, this is the node to delete

        // Case when the node has no middle child
        if (!root->middle) {
            if (!root->left) {  // No left child, replace with the right
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {  // No right child, replace with the left
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node has two children, find the minimum in the right subtree
            Node* temp = findmin(root->right);
            // Replace root's data with the minimum value in the right subtree
            root->data = temp->data;
            // Delete the minimum node in the right subtree
            root->right = deleteNode(root->right, temp->data);
        } else {
            // If there is a middle child, delete the middle node
            root->middle = deleteNode(root->middle, value);
        }
    }
    return root;
}

// Pre-order Traversal: Root, Left, Middle, Right
void preOrder(Node* root) {
    if (root) {
        cout << root->data << " ";  // Visit root node
        preOrder(root->left);       // Visit left subtree
        preOrder(root->middle);     // Visit middle subtree
        preOrder(root->right);      // Visit right subtree
    }
}

// In-order Traversal: Left, Root, Middle, Right
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);        // Visit left subtree
        cout << root->data << " ";  // Visit root node
        inOrder(root->middle);      // Visit middle subtree
        inOrder(root->right);       // Visit right subtree
    }
}

// Post-order Traversal: Left, Middle, Right, Root
void postOrder(Node* root) {
    if (root) {
        postOrder(root->left);      // Visit left subtree
        postOrder(root->middle);    // Visit middle subtree
        postOrder(root->right);     // Visit right subtree
        cout << root->data << " ";  // Visit root node
    }
}

// Main function to demonstrate insertion, deletion, and traversal
int main() {
    Node* root = nullptr;

    // Insert nodes into the ternary tree
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 5);  // Duplicate value (middle insertion)
    root = insert(root, 5);
    root = insert(root, 3);

    cout << "Pre-Order Traversal: ";
    preOrder(root);  // Display pre-order traversal
    cout << endl;

    cout << "In-Order Traversal: ";
    inOrder(root);  // Display in-order traversal
    cout << endl;

    cout << "Post-Order Traversal: ";
    postOrder(root);  // Display post-order traversal
    cout << endl;

    // Delete a node and display the traversal again
    root = deleteNode(root, 5);  // Deleting node with value 5
    cout << "\nAfter deletion of 5:\n";

    cout << "Pre-Order Traversal: ";
    preOrder(root);  // Display pre-order traversal
    cout << endl;

    return 0;
}
