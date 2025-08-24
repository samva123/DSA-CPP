#include <iostream>
#include<queue>

using namespace std;
int getKthGreatestElement(int arr[], int n, int k) {
        //create min heap
        priority_queue<int, vector<int>, greater<int> > pq;
        //insert inital k elements of array 
        for(int i=0; i<k; i++) {
                pq.push(arr[i]);
        }
        //for remaining elements, push only if they are greater than top
        for(int i =k; i<n; i++) {
                int element = arr[i];
                if(element > pq.top()) {
                        pq.pop();
                        pq.push(element);
                }
        }
        int ans = pq.top();
        return ans;
}
int getKthSmallestElement(int arr[], int n, int k ) {
        //create max heap
        priority_queue<int> pq;
        //insert inital k elements of array 
        for(int i=0; i<k; i++) {
                pq.push(arr[i]);
        }
        //for remaining elements, push only if they are less than top
        for(int i =k; i<n; i++) {
                int element = arr[i];
                if(element < pq.top()) {
                        pq.pop();
                        pq.push(element);
                }
        }
        int ans = pq.top();
        return ans;

}
int main() {
        int arr[] = {10,5,20,4,15};
        int n = 5;
        int k = 5;
        int ans = getKthGreatestElement(arr, n, k );
        cout << "Ans is: " << ans << endl;
        return 0;
}


// 🔹 getKthGreatestElement
// Steps:

// Insert first k elements into min-heap

// Each insertion = O(log k)

// For k elements = O(k log k)

// Process remaining (n – k) elements

// Each check = compare with pq.top() → O(1)

// If condition holds → pop + push = O(log k)

// Worst case: all (n - k) elements replace → (n - k) × O(log k)

// Return pq.top() → O(1)

// ⏱ Time Complexity:

// O(klogk+(n−k)logk)=O(nlogk)
// 🗂 Space Complexity:

// Heap stores at most k elements → O(k).
