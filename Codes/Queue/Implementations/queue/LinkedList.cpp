#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class QueueLL {
    Node *front, *rear;
public:
    QueueLL() : front(nullptr), rear(nullptr) {}

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (!rear) {  // If the queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    int dequeue() {
        if (!front) return -1;  // Queue is empty
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (front) front->prev = nullptr;
        else rear = nullptr;  // If queue is now empty
        delete temp;
        return val;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void print() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue: ";
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~QueueLL() {
        while (front) {
            dequeue();
        }
    }
};

int main() {
    QueueLL q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.print();  // Output: Queue: 10 20 30 40

    q.dequeue();
    q.print();  // Output: Queue: 20 30 40

    q.enqueue(50);
    q.enqueue(60);
    q.print();  // Output: Queue: 20 30 40 50 60

    return 0;
}







//////////////////////JAVA////////////////////

// public class QueueLL {
//     class Node {
//         int data;
//         Node next, prev;
//         Node(int val) {
//             data = val;
//             next = prev = null;
//         }
//     }

//     private Node front, rear;

//     public QueueLL() {
//         front = rear = null;
//     }

//     public void enqueue(int val) {
//         Node newNode = new Node(val);
//         if (rear == null) {  // If the queue is empty
//             front = rear = newNode;
//         } else {
//             rear.next = newNode;
//             newNode.prev = rear;
//             rear = newNode;
//         }
//     }

//     public int dequeue() {
//         if (front == null) return -1;  // Queue is empty
//         int val = front.data;
//         front = front.next;
//         if (front != null) front.prev = null;
//         else rear = null;  // If queue is now empty
//         return val;
//     }

//     public boolean isEmpty() {
//         return front == null;
//     }

//     public void print() {
//         if (front == null) {
//             System.out.println("Queue is empty");
//             return;
//         }

//         System.out.print("Queue: ");
//         Node temp = front;
//         while (temp != null) {
//             System.out.print(temp.data + " ");
//             temp = temp.next;
//         }
//         System.out.println();
//     }

//     public static void main(String[] args) {
//         QueueLL q = new QueueLL();

//         q.enqueue(10);
//         q.enqueue(20);
//         q.enqueue(30);
//         q.enqueue(40);
//         q.print();  // Output: Queue: 10 20 30 40

//         q.dequeue();
//         q.print();  // Output: Queue: 20 30 40

//         q.enqueue(50);
//         q.enqueue(60);
//         q.print();  // Output: Queue: 20 30 40 50 60
//     }
// }
