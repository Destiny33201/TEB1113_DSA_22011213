#include <iostream>
#include <string>  // Fixed include
using namespace std;

class Node {
public:
    string name;
    Node* next;  // Pointer to the next node

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert a new node at the end
    void insert_node(string name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete a node by name
    void delete_node(string name) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        // If head needs to be deleted
        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted: " << name << endl;
            return;
        }

        // Traverse to find the node to delete
        Node* current = head;
        while (current->next != nullptr && current->next->name != name) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << "Node not found: " << name << endl;
        } else {
            Node* temp = current->next;
            current->next = current->next->next;

            // Update tail if needed
            if (temp == tail) {
                tail = current;
            }

            delete temp;
            cout << "Deleted: " << name << endl;
        }
    }

// Display all nodes with arrows between them
void display_list() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* currNode = head;
    cout << "Linked List: ";
    while (currNode != nullptr) {
        cout << currNode->name;
        if (currNode->next != nullptr) {
            cout << " -> ";
        }
        currNode = currNode->next;
    }
    cout << endl;
}
};

int main() {
    LinkedList list;

    list.insert_node("Alice");
    list.insert_node("Bob");
    list.insert_node("Charlie");
    list.display_list();

    list.delete_node("Bob");
    list.display_list();

    list.delete_node("Daniel");  // Non-existent
    list.display_list();

    return 0;
}
