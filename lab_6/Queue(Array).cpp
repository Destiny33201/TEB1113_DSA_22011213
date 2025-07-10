#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    static const int SIZE = 100; // Maximum size of queue
    string arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue: Insert at rear
    void enqueue(const string& name) {
        if (rear == SIZE - 1) {
            cout << "Queue overflow. Cannot enqueue " << name << ".\n";
            return;
        }

        if (front == -1) front = 0;
        rear++;
        arr[rear] = name;
        cout << "Enqueued: " << name << endl;
    }

    // Dequeue: Remove from front
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue underflow. Cannot dequeue.\n";
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;
        front++;
    }

    // Peek: Show front item
    void peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Front of queue: " << arr[front] << endl;
    }

    // Display the queue
    void display_queue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue (front -> rear): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " -> ";
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue queue;
    queue.enqueue("Alice");
    queue.enqueue("Bob");
    queue.enqueue("Charlie");
    queue.display_queue();   // Alice -> Bob -> Charlie

    queue.dequeue();         // Dequeued: Alice
    queue.display_queue();   // Bob -> Charlie

    queue.peek();            // Front of queue: Bob

    return 0;
}
