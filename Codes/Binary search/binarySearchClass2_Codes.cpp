//find pivot index:

#include <iostream>
#include<vector>
using namespace std;

int findPivotIndex(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;

        while(s <= e) {
            //corner case
            if(s == e) {
                //single element
                return s;
            }

            if(arr[mid] > arr[mid+1])
                return mid;
            else if(arr[mid] < arr[mid-1])
                return mid-1;
            else if(arr[s] > arr[mid] ) 
                e = mid - 1;
            else 
                s = mid + 1;
            
            mid = s + (e-s)/2;
        }
        return -1;

    }


//////////////////////////////////////////////////MINOR CHANGES/////////////////

    int findPivotIndex1(vector<int>& arr) {
    int n = arr.size();
    int s = 0;
    int e = n - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        // corner case: if mid is at the boundaries
        if (mid < n - 1 && arr[mid] > arr[mid + 1])
            return mid;
        if (mid > 0 && arr[mid] < arr[mid - 1])
            return mid - 1;

        if (arr[s] <= arr[mid]) {
            // Left part is sorted, pivot must be in right
            s = mid + 1;
        } else {
            // Pivot is in left part
            e = mid - 1;
        }
    }

    // If no rotation (sorted array), last element is the pivot
    return n - 1;
}

int findPivotIndex2(vector<int>& arr) {
    int n = arr.size();
    int s = 0, e = n - 1;

    while (s < e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] > arr[e])
            s = mid + 1;
        else
            e = mid;
    }

    // s now points to smallest element
    return (s - 1 + n) % n;  // pivot index (largest element)
}


int main() {
  vector<int> v = {2, 2, 2, 3, 1, 2};


//   v.push_back(2);
//   v.push_back(4);
//   v.push_back(6);
//   v.push_back(8);
//   v.push_back(10);

  int pivotIndex = findPivotIndex2(v);
  cout << "Pivot Index is: " << pivotIndex << endl;
  return 0;
}


// //search in a rotated and sorted array 
// class Solution {
// public:

//     int findPivotIndex(vector<int>& arr) {
//         int n = arr.size();
//         int s = 0;
//         int e = n-1;
//         int mid = s + (e-s)/2;

//         while(s <= e) {
//             //corner case
//             if(s == e) {
//                 //single element
//                 return s;
//             }

//             if(mid+1 < n && arr[mid] > arr[mid+1])
//                 return mid;
//             else if(mid-1 >=0 && arr[mid] < arr[mid-1])
//                 return mid-1;
//             else if(arr[s] > arr[mid] ) 
//                 e = mid - 1;
//             else 
//                 s = mid + 1;
            
//             mid = s + (e-s)/2;
//         }
//         return -1;

//     }

//     int binarySearch(vector<int>& arr, int s, int e, int target) {
//         int mid = s + (e-s)/2;
//         while(s<=e) {
//             if(arr[mid] == target) {
//                 return mid;
//             }
//             if(target > arr[mid]) {
//                 s = mid + 1;
//             }
//             else {
//                 e = mid - 1;
//             }
//             mid = s + (e-s)/2;
//         }
//         return -1;
//     }

//     int search(vector<int>& nums, int target) {
//         int pivotIndex = findPivotIndex(nums);
//         cout << "Pivot Index us: " << pivotIndex << endl;
//         int n = nums.size();
//         int ans = -1;

//         //search in A
//         if(target >= nums[0] && target <= nums[pivotIndex]) {
//             ans = binarySearch(nums, 0, pivotIndex, target);
//         }
//         else {
//             ans = binarySearch(nums, pivotIndex+1, n-1, target);
//         }
//         return ans;
//     }
// };


// //find square root of a number 
// class Solution {
// public:


//     int mySqrt(int x) {
//         int s = 0;
//         int e = x;
//         long long int mid = s + (e-s)/2;
//         int ans = -1;

//         while(s <= e) {
//             //kya mid hi toh answer nahi
//             if(mid*mid == x) {
//                 return mid;
//             }
//             else if(mid*mid < x) {
//                 //ans store
//                 //right me jao
//                 ans = mid;
//                 s = mid+1;
//             }
//             else {
//                 //left me jana h 
//                 e = mid-1;
//             }
//             mid = s + (e-s)/2;
//         }
//         return ans;
//     }

    
// };


// //binary search in a  2D matrix 
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int row = matrix.size();
//         int col = matrix[0].size();
//         int n = row*col;

//         int s = 0;
//         int e = n-1;
//         int mid = s + (e-s)/2;

//         while(s <= e) {
//             int rowIndex = mid/col;
//             int colIndex = mid % col;
//             int currNumber = matrix[rowIndex][colIndex];

//             if(currNumber == target)
//                 return true;
//             else if(target > currNumber ) {
//                 //right;
//                 s = mid + 1;
//             } 
//             else {
//                 //left;
//                 e = mid-1;
//             }
//             mid = s + (e-s)/2;
//         }
//         return false;
//     }
// };
























































// //{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;


// // } Driver Code Ends
// // User function template for C++
// class Solution {
//   public:
//     bool matSearch(vector<vector<int>> &matrix, int target) {
//         // your code here
//         long long int row = matrix.size();
//         long long int col = matrix[0].size();
//         long long int n = row*col;

//         long long int s = 0;
//         long long int e = n-1;
//         long long int mid = s + (e-s)/2;

//         while(s <= e) {
//             long long int rowIndex = mid/col;
//             long long int colIndex = mid % col;
//             long long int currNumber = matrix[rowIndex][colIndex];

//             if(currNumber == target)
//                 return true;
//             else if(target > currNumber ) {
//                 //right;
//                 s = mid + 1;
//             } 
//             else {
//                 //left;
//                 e = mid-1;
//             }
//             mid = s + (e-s)/2;
//         }
//         return false;
//     }
// };

// // //{ Driver Code Starts.
// // int main() {
// //     int t;
// //     cin >> t;

// //     while (t--) {
// //         int r, c;
// //         cin >> r >> c;
// //         vector<vector<int>> matrix(r, vector<int>(c, 0));
// //         int x;
// //         for (int i = 0; i < r; i++) {
// //             for (int j = 0; j < c; j++) {
// //                 cin >> matrix[i][j];
// //             }
// //         }
// //         cin >> x;
// //         Solution ob;
// //         bool an = ob.matSearch(matrix, x);
// //         if (an)
// //             cout << "true" << endl;
//         else
//             cout << "false" << endl;
//         cout << "~" << endl;
//     }
//     return 0;
// }
// // } Driver Code Ends