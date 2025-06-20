#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert a new node at the end
    void insert_node(const string& name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->next = head; // Circular link
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Maintain circular link
        }
    }

    // Delete a node by name
    void delete_node(const string& name) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        // Special case: only one node
        if (head == tail && head->name == name) {
            delete head;
            head = tail = nullptr;
            cout << "Deleted: " << name << endl;
            return;
        }

        Node* current = head;
        Node* prev = tail;

        do {
            if (current->name == name) {
                if (current == head) {
                    head = head->next;
                    tail->next = head;
                } else if (current == tail) {
                    tail = prev;
                    tail->next = head;
                } else {
                    prev->next = current->next;
                }
                delete current;
                cout << "Deleted: " << name << endl;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);

        cout << "Node not found: " << name << endl;
    }

    // Display all nodes with arrows
	void display_list() {
	    if (head == nullptr) {
	        cout << "List is empty.\n";
	        return;
	    }
	
	    Node* current = head;
	    cout << "Circular Linked List: ";
	    do {
	        cout << current->name << " -> ";
	        current = current->next;
	    } while (current != head);
	    cout << head->name << endl; // Show it loops back to the head
	}


    // Destructor to clean up
    ~CircularLinkedList() {
        if (head == nullptr) return;

        Node* current = head;
        tail->next = nullptr; // Break the loop for safe deletion

        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    CircularLinkedList list;
    list.insert_node("Alice");
    list.insert_node("Bob");
    list.insert_node("Charlie");
    list.display_list();  // Alice -> Bob -> Charlie

    list.delete_node("Bob");
    list.display_list();  // Alice -> Charlie

    list.delete_node("Daniel");  // Not found
    list.display_list();

    return 0;
}
