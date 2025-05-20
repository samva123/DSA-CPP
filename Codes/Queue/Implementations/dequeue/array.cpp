#include <iostream>
using namespace std;

class DequeArray {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int size;

    void resize() {
        int* newArr = new int[capacity * 2];
        int index = 0;

        for (int i = front; i != rear; i = (i + 1) % capacity)
            newArr[index++] = arr[i];
        newArr[index++] = arr[rear];

        delete[] arr;
        arr = newArr;
        front = 0;
        rear = size - 1;
        capacity *= 2;
    }

public:
    DequeArray(int cap = 5) {
        arr = new int[cap];
        capacity = cap;
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isEmpty() { return size == 0; }

    void pushFront(int x) {
        if (size == capacity)
            resize();

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }

        arr[front] = x;
        size++;
    }

    void pushBack(int x) {
        if (size == capacity)
            resize();

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = x;
        size++;
    }

    void popFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
    }

    void popBack() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }

        size--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
    
    void print() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deque contents: ";
        for (int i = front, cnt = 0; cnt < size; i = (i + 1) % capacity, cnt++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};












/////////////////////JAVA////////////

// class DequeArray {
//     private int[] arr;
//     private int front, rear, size, capacity;

//     public DequeArray(int cap) {
//         arr = new int[cap];
//         capacity = cap;
//         front = -1;
//         rear = -1;
//         size = 0;
//     }

//     private void resize() {
//         int[] newArr = new int[capacity * 2];
//         int index = 0;

//         for (int i = front; i != rear; i = (i + 1) % capacity)
//             newArr[index++] = arr[i];
//         newArr[index++] = arr[rear];

//         arr = newArr;
//         front = 0;
//         rear = size - 1;
//         capacity *= 2;
//     }

//     public boolean isEmpty() {
//         return size == 0;
//     }

//     public void pushFront(int x) {
//         if (size == capacity) resize();

//         if (isEmpty()) {
//             front = rear = 0;
//         } else {
//             front = (front - 1 + capacity) % capacity;
//         }

//         arr[front] = x;
//         size++;
//     }

//     public void pushBack(int x) {
//         if (size == capacity) resize();

//         if (isEmpty()) {
//             front = rear = 0;
//         } else {
//             rear = (rear + 1) % capacity;
//         }

//         arr[rear] = x;
//         size++;
//     }

//     public void popFront() {
//         if (isEmpty()) {
//             System.out.println("Deque is empty");
//             return;
//         }

//         if (front == rear) {
//             front = rear = -1;
//         } else {
//             front = (front + 1) % capacity;
//         }

//         size--;
//     }

//     public void popBack() {
//         if (isEmpty()) {
//             System.out.println("Deque is empty");
//             return;
//         }

//         if (front == rear) {
//             front = rear = -1;
//         } else {
//             rear = (rear - 1 + capacity) % capacity;
//         }

//         size--;
//     }

//     public int getFront() {
//         if (isEmpty()) return -1;
//         return arr[front];
//     }

//     public int getRear() {
//         if (isEmpty()) return -1;
//         return arr[rear];
//     }
// }
// public class Main {
//     public static void main(String[] args) {
//         System.out.println("Deque using Dynamic Array:");
//         DequeArray da = new DequeArray(3);

//         da.pushBack(10);
//         da.pushFront(20);
//         da.pushBack(30);
//         da.pushFront(40); // triggers resize

//         System.out.println("Front: " + da.getFront()); // 40
//         System.out.println("Rear: " + da.getRear());   // 30

//         da.popFront();
//         da.popBack();

//         System.out.println("Front after pops: " + da.getFront()); // 20
//         System.out.println("Rear after pops: " + da.getRear());   // 10
//     }
// }
