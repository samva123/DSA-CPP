#include <iostream>
using namespace std;

class QueueArray {
    int* arr;
    int front, rear, size, capacity;

    void resize() {
        int* newArr = new int[2 * capacity];
        for (int i = 0; i < size; ++i)
            newArr[i] = arr[(front + i) % capacity];

        delete[] arr;
        arr = newArr;
        front = 0;
        rear = size;
        capacity *= 2;
    }

public:
    QueueArray(int cap = 4) {
        capacity = cap;
        arr = new int[capacity];
        front = rear = size = 0;
    }

    ~QueueArray() {
        delete[] arr;
    }

    void enqueue(int val) {
        if (size == capacity) resize();
        arr[rear] = val;
        rear = (rear + 1) % capacity;
        size++;
    }

    int dequeue() {
        if (size == 0) return -1; // Queue is empty
        int val = arr[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }

    bool isEmpty() {
        return size == 0;
    }

    void print() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < size; ++i)
            cout << arr[(front + i) % capacity] << " ";
        cout << endl;
    }
};






/////////////JAVA////////////

// public class QueueArray {
//     private int[] arr;
//     private int front, rear, size, capacity;

//     public QueueArray(int cap) {
//         capacity = cap;
//         arr = new int[capacity];
//         front = rear = size = 0;
//     }

//     private void resize() {
//         int[] newArr = new int[2 * capacity];
//         for (int i = 0; i < size; ++i)
//             newArr[i] = arr[(front + i) % capacity];

//         arr = newArr;
//         front = 0;
//         rear = size;
//         capacity *= 2;
//     }

//     public void enqueue(int val) {
//         if (size == capacity) resize();
//         arr[rear] = val;
//         rear = (rear + 1) % capacity;
//         size++;
//     }

//     public int dequeue() {
//         if (size == 0) return -1; // Queue is empty
//         int val = arr[front];
//         front = (front + 1) % capacity;
//         size--;
//         return val;
//     }

//     public boolean isEmpty() {
//         return size == 0;
//     }

//     public void print() {
//         if (size == 0) {
//             System.out.println("Queue is empty");
//             return;
//         }

//         System.out.print("Queue: ");
//         for (int i = 0; i < size; ++i)
//             System.out.print(arr[(front + i) % capacity] + " ");
//         System.out.println();
//     }

//     public static void main(String[] args) {
//         QueueArray q = new QueueArray(4);

//         q.enqueue(10);
//         q.enqueue(20);
//         q.enqueue(30);
//         q.enqueue(40);
//         q.print();  // Output: Queue: 10 20 30 40

//         q.dequeue();
//         q.print();  // Output: Queue: 20 30 40

//         q.enqueue(50);
//         q.enqueue(60);  // Triggers resize
//         q.print();  // Output: Queue: 20 30 40 50 60
//     }
// }
