#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    Node* newNode = new Node(val);
    Node* temp = root;
    Node* parent = nullptr;

    while (temp != nullptr) {
        parent = temp;
        if (val < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    if (val < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    newNode->parent = parent;
    return root; // Added return statement for root
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* findparent(Node* root, int val) {
    Node* current = root;
    while (current != nullptr && current->data != val) {
        if (val < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return (current == nullptr) ? nullptr : current->parent;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "inorder traversal of binary search tree: ";
    inorder(root);
    cout << endl;

    int val = 40;
    Node* parent = findparent(root, val);
    if (parent != nullptr) {
        cout << "Parent of Node " << val << " is " << parent->data << endl;
    } else {
        cout << "Node " << val << " does not have a parent node\n"; // Fixed missing semicolon
    }

    return 0;
}