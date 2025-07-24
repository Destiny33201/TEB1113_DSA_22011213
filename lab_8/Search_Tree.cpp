#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void insert(int val) {
        root = insert_recursive(root, val);
    }

    Node* insert_recursive(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);

        if (val < node->value)
            node->left = insert_recursive(node->left, val);
        else
            node->right = insert_recursive(node->right, val);

        return node;
    }

    Node* search(Node* node, int target) {
        if (node == nullptr || node->value == target)
            return node;

        if (target < node->value)
            return search(node->left, target);
        else
            return search(node->right, target);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }
};

int main() {
    Tree tree;

    // Build BST: Inserting in non-sorted order to allow BST to self-organize
    tree.insert(40);
    tree.insert(20);
    tree.insert(60);
    tree.insert(10);
    tree.insert(30);
    tree.insert(50);
    tree.insert(70);

    cout << "In-order Traversal (Should be sorted): ";
    tree.inorder(tree.root);
    cout << endl;

    int target = 70;
    Node* result = tree.search(tree.root, target);
    if (result)
        cout << "Value " << target << " found in tree!" << endl;
    else
        cout << "Value " << target << " not found." << endl;

    return 0;
}

