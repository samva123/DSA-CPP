#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DequeList {
private:
    Node* front;
    Node* rear;

public:
    DequeList() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void pushFront(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void pushBack(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void popFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        Node* temp = front;
        front = front->next;
        if (front) front->prev = nullptr;
        else rear = nullptr;
        delete temp;
    }

    void popBack() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        Node* temp = rear;
        rear = rear->prev;
        if (rear) rear->next = nullptr;
        else front = nullptr;
        delete temp;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return front->data;
    }

    int getRear() {
        if (isEmpty()) return -1;
        return rear->data;
    }
};





//////////////////////////////////JAVA//////////////////////

// class Node {
//     int data;
//     Node prev, next;

//     Node(int val) {
//         data = val;
//         prev = next = null;
//     }
// }

// class DequeList {
//     private Node front, rear;

//     public DequeList() {
//         front = rear = null;
//     }

//     public boolean isEmpty() {
//         return front == null;
//     }

//     public void pushFront(int x) {
//         Node newNode = new Node(x);
//         if (isEmpty()) {
//             front = rear = newNode;
//         } else {
//             newNode.next = front;
//             front.prev = newNode;
//             front = newNode;
//         }
//     }

//     public void pushBack(int x) {
//         Node newNode = new Node(x);
//         if (isEmpty()) {
//             front = rear = newNode;
//         } else {
//             rear.next = newNode;
//             newNode.prev = rear;
//             rear = newNode;
//         }
//     }

//     public void popFront() {
//         if (isEmpty()) {
//             System.out.println("Deque is empty");
//             return;
//         }

//         front = front.next;
//         if (front != null)
//             front.prev = null;
//         else
//             rear = null;
//     }

//     public void popBack() {
//         if (isEmpty()) {
//             System.out.println("Deque is empty");
//             return;
//         }

//         rear = rear.prev;
//         if (rear != null)
//             rear.next = null;
//         else
//             front = null;
//     }

//     public int getFront() {
//         if (isEmpty()) return -1;
//         return front.data;
//     }

//     public int getRear() {
//         if (isEmpty()) return -1;
//         return rear.data;
//     }
// }

// public class Main {
//     public static void main(String[] args) {
//         System.out.println("Deque using Linked List:");
//         DequeList dl = new DequeList();

//         dl.pushBack(5);
//         dl.pushFront(15);
//         dl.pushBack(25);
//         dl.pushFront(35);

//         System.out.println("Front: " + dl.getFront()); // 35
//         System.out.println("Rear: " + dl.getRear());   // 25

//         dl.popFront();
//         dl.popBack();

//         System.out.println("Front after pops: " + dl.getFront()); // 15
//         System.out.println("Rear after pops: " + dl.getRear());   // 5
//     }
// }
