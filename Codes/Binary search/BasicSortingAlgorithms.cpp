#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v) {
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << endl;
}

void bubbleSort(vector<int> &v) {
  int n = v.size();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
      }
    }
  }
}

// void bubbleSort(vector<int> &v) {
//   int n = v.size();
//   for (int i = 0; i < n - 1; ++i) {
//     bool swapped = false; // check if any swap happened
//     for (int j = 0; j < n - i - 1; ++j) {
//       if (v[j] > v[j + 1]) {
//         swap(v[j], v[j + 1]);
//         swapped = true;
//       }
//     }
//     if (!swapped) break; // array already sorted
//   }
// }


// Case	Explanation	Time Complexity
// Best case	Already sorted array — but your code does not have an early stop check, so it still does all passes → O(n²) (if optimized with a flag, it becomes O(n))	
// Average case	Random order, roughly half the pairs swapped per pass → O(n²)	
// Worst case	Reverse-sorted array — every comparison leads to a swap → O(n²)	


void selectionSort(vector<int> &v) {
  int n = v.size();
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i; // ith element hi smallest hai
    for (int j = i + 1; j < n; j++) {
      if (v[j] < v[minIndex]) {
        minIndex = j;
      }
    }

    // swap ith and minIndex elements;
    swap(v[i], v[minIndex]);
  }
}

// Case	Explanation	Time
// Best case	Even if already sorted, we still compare all pairs (no early stop)	O(n²)
// Average case	Random order, same comparisons	O(n²)
// Worst case	Reverse sorted — still same comparisons	O(n²)

void insertionSort(vector<int> &v) {
  int n = v.size();
  // i = 0, chhod deta hu
  for (int i = 1; i < n; ++i) {
    int key = v[i];
    int j = i - 1;

    // Move elements of arr[0..i-1] that are greater than
    // key to one position ahead of theri current position
    while (j >= 0 && v[j] > key) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key; // insertion
  }
}

// Case	Explanation	Time
// Best case	Already sorted → no shifting in inner loop	O(n)
// Average case	Random order → about half of the elements shifted	O(n²)
// Worst case	Reverse sorted → every new element moved to front	O(n²)

int main() {
  vector<int> v = {44,33,55,22,11};
  // bubbleSort(v);
  // selectionSort(v);
  insertionSort(v);
  print(v);
  return 0;
}



#include <stdio.h>

int insertionSortShifts(int arr[], int n) {
    int shifts = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Count and perform shifts while sorting
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            shifts++; // Increment shifts for each movement
        }
        arr[j + 1] = key; // Place the key in its correct position
    }
    return shifts; // Return total shift count
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        int arr[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        printf("%d\n", insertionSortShifts(arr, N));
    }
    return 0;
}
