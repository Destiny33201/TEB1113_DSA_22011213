#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
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

    void add_root(string name) {
        root = new Node(name);
    }

    Node* add_left(Node* parent, string name) {
        parent->left = new Node(name);
        return parent->left;
    }

    Node* add_right(Node* parent, string name) {
        parent->right = new Node(name);
        return parent->right;
    }
};

int main() {
    Tree tree;

    tree.add_root("A");
    Node* root = tree.root;
    Node* B = tree.add_left(root, "B");
    Node* C = tree.add_right(root, "C");

    tree.add_left(B, "D");
    tree.add_right(B, "E");

    tree.add_left(C, "F");
    tree.add_right(C, "G");

    cout << "Root: " << root->name << endl;
    cout << "Left child of root: " << B->name << endl;
    cout << "Right child of root: " << C->name << endl;
    cout << "Left child of B: " << B->left->name << endl;
    cout << "Right child of B: " << B->right->name << endl;
    cout << "Left child of C: " << C->left->name << endl;
    cout << "Right child of C: " << C->right->name << endl;

    return 0;
}
