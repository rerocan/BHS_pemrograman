#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val){
    if(root == nullptr){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

Node* findcommonancestor(Node* root, int n1, int n2){
    if (root == nullptr) return nullptr;

    if (root->data == n1 || root->data == n2) return root;

    Node* left = findcommonancestor(root->left, n1, n2);
    Node* right = findcommonancestor(root->right, n1, n2);

    if (left != nullptr && right != nullptr) return root;

    return left != nullptr ? left : right; // Return the non-null child if one exists
}

int main (){
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int n1 = 20, n2 = 40;
    Node* ancestor = findcommonancestor(root, n1, n2);

    if (ancestor != nullptr){
        cout << "Common ancestor of " << n1 << " and " << n2 << " is " << ancestor->data << endl;
    } else {
        cout << "Common ancestor of " << n1 << " and " << n2 << " is not found" << endl;
    }
    return 0;
}