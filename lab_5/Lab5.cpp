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

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push: Insert at top
    void push(const string& name) {
        Node* newNode = new Node(name);
        newNode->next = top;
        top = newNode;
    }

    // Pop: Remove from top
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }

        Node* temp = top;
        cout << "Popped: " << top->name << endl;
        top = top->next;
        delete temp;
    }

    // Peek at the top item
    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Top of stack: " << top->name << endl;
        }
    }

    // Display stack from top to bottom
    void display_stack() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }

        Node* current = top;
        cout << "Stack (top -> bottom): ";
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to clean up
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack stack;
    stack.push("Alice");
    stack.push("Bob");
    stack.push("Charlie");
    stack.display_stack();  // Charlie -> Bob -> Alice

    stack.pop();            // Popped: Charlie
    stack.display_stack();  // Bob -> Alice

    stack.peek();           // Top of stack: Bob

    return 0;
}
