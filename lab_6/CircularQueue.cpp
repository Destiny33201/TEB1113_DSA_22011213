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

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue: Add to rear
    void enqueue(const string& name) {
        Node* newNode = new Node(name);

        if (front == nullptr) {
            front = rear = newNode;
            rear->next = front;  // Point to itself, circular
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;  // Maintain circular link
        }
        cout << "Enqueued: " << name << endl;
    }

    // Dequeue: Remove from front
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        if (front == rear) {
            // Only one node
            cout << "Dequeued: " << front->name << endl;
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            cout << "Dequeued: " << temp->name << endl;
            front = front->next;
            rear->next = front;  // Update circular link
            delete temp;
        }
    }

    // Peek at the front item
    void peek() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Front of queue: " << front->name << endl;
        }
    }

    // Display the queue
    void display_queue() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* current = front;
        cout << "Queue (front -> rear): ";
        do {
            cout << current->name << " -> ";
            current = current->next;
        } while (current != front);
        cout << front->name << endl;
    }

    // Destructor
    ~CircularQueue() {
        if (front == nullptr) return;

        rear->next = nullptr;  // Break circular link
        Node* current = front;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    CircularQueue queue;
    queue.enqueue("Alice");
    queue.enqueue("Bob");
    queue.enqueue("Charlie");
    queue.display_queue();     // Alice -> Bob -> Charlie -> (back to front)

    queue.dequeue();           // Dequeued: Alice
    queue.display_queue();     // Bob -> Charlie -> (back to front)

    queue.peek();              // Front of queue: Bob

    return 0;
}
