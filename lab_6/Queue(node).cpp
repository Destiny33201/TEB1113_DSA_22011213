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

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue: Insert at rear
    void enqueue(const string& name) {
        Node* newNode = new Node(name);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue: Remove from front
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;
        cout << "Dequeued: " << front->name << endl;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr; // Queue is now empty
        }

        delete temp;
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
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to clean up
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue queue;
    queue.enqueue("Alice");
    queue.enqueue("Bob");
    queue.enqueue("Charlie");
    queue.display_queue();  // Alice -> Bob -> Charlie

    queue.dequeue();        // Dequeued: Alice
    queue.display_queue();  // Bob -> Charlie

    queue.peek();           // Front of queue: Bob

    return 0;
}
