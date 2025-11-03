#include <bits/stdc++.h>
using namespace std;

class Heap{
    public:
    int* arr;
    int capacity ; 
    int size;

    Heap(int capacity){
        this->arr = new int[capacity];
        this->capacity  = capacity;
        this->size = 0;

    }

    void insert(int val){
        if(size == capacity){
            cout << "heap oveflow" << endl;
            return;
        }
        size++;
        int index  = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;
            if(arr[index] > arr[parent]){
                swap(arr[index] , arr[parent]);
                index  = parent;
            }else{
                break;
            }
        }
    }
    void printHeap() {
      for(int i=1; i<=size; i++) {
         cout << arr[i] << " ";
     }
    }

};


int main(){

    Heap h(20);
    //insertion
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);

    cout << "Printing the content of heap: " << endl;
    h.printHeap();

}