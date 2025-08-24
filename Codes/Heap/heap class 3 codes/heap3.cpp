#include <bits/stdc++.h>
using namespace std;


class Info{
  public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int a, int b, int c) {
      this->data = a;
      this->rowIndex = b;
      this->colIndex = c;
    }
};

class compare{
  public:
    bool operator()(Info* a, Info* b) {
      return a->data > b->data;
    } 
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue<Info*, vector<Info*>, compare> pq;
        int maxi = INT_MIN;
        int mini = INT_MAX;



        

        //process first k elements ko 
        for(int i=0; i<nums.size(); i++) {
            int element = nums[i][0];
            int row = i;
            int col = 0;
            Info* temp = new Info(element, row, col);
            pq.push(temp);
            maxi = max(maxi, element);
            mini = min(mini,element);
        }

        int ansStart = mini;
        int ansEnd = maxi;

        while(!pq.empty()) {
            Info* topNode = pq.top();
            int topData = topNode->data;
            int topCol = topNode->colIndex;
            int topRow = topNode->rowIndex;

            pq.pop();

            mini = topNode->data;
            //maxi ki value pehle se padi hui h 
            //compare krlete h for smaller range
            if((maxi-mini) < (ansEnd-ansStart)) {
                //update ans;
                ansStart  = mini;
                ansEnd = maxi;
            }

            //insertion wala step
            if(topCol + 1 < nums[topRow].size()) {
                int newElement = nums[topRow][topCol+1];
                maxi = max(maxi, newElement);
                Info* newInfo = new Info(newElement, topRow, topCol+1);
                pq.push(newInfo);
            }
            else {
                //aggge koi element nahi h push krne ko
                break;
            }


        }
        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;

    }
};

































////////////////////doing deallocation
// #include <bits/stdc++.h>
// using namespace std;

// struct Info {
//     int val;
//     int row;
//     int idx;
//     Info(int v, int r, int i) : val(v), row(r), idx(i) {}
// };

// class Compare {
// public:
//     bool operator()(Info* a, Info* b) {
//         return a->val > b->val; // min-heap
//     }
// };

// pair<int,int> smallestRange(vector<vector<int>>& nums) {
//     int k = nums.size();
//     priority_queue<Info*, vector<Info*>, Compare> pq;

//     int maxi = INT_MIN;

//     // Step 1: Insert first element of every list
//     for (int i = 0; i < k; i++) {
//         Info* temp = new Info(nums[i][0], i, 0);
//         pq.push(temp);
//         maxi = max(maxi, nums[i][0]);
//     }

//     int start = 0, end = INT_MAX;

//     // Step 2: Process heap
//     while (!pq.empty()) {
//         Info* curr = pq.top();
//         pq.pop();

//         int mini = curr->val;

//         if (maxi - mini < end - start) {
//             start = mini;
//             end = maxi;
//         }

//         // Move to next element in same row
//         if (curr->idx + 1 < nums[curr->row].size()) {
//             int nextVal = nums[curr->row][curr->idx + 1];
//             Info* next = new Info(nextVal, curr->row, curr->idx + 1);
//             pq.push(next);
//             maxi = max(maxi, nextVal);
//         } else {
//             // No more elements in this row → break
//             delete curr; // deallocate last popped element
//             break;
//         }

//         delete curr; // deallocate popped element
//     }

//     // Cleanup: delete remaining heap elements
//     while (!pq.empty()) {
//         delete pq.top();
//         pq.pop();
//     }

//     return {start, end};
// }

// int main() {
//     vector<vector<int>> nums = {
//         {4, 10, 15, 24, 26},
//         {0, 9, 12, 20},
//         {5, 18, 22, 30}
//     };

//     auto range = smallestRange(nums);
//     cout << "Smallest range is [" << range.first << ", " << range.second << "]\n";

//     return 0;
// }



























///////////////no pointer approach 


// #include <bits/stdc++.h>
// using namespace std;

// class Info {
// public:
//     int data;
//     int rowIndex;
//     int colIndex;

//     Info(int a, int b, int c) {
//         data = a;
//         rowIndex = b;
//         colIndex = c;
//     }
// };

// class compare {
// public:
//     bool operator()(const Info& a, const Info& b) {
//         return a.data > b.data; // min-heap
//     } 
// };

// class Solution {
// public:
//     vector<int> smallestRange(vector<vector<int>>& nums) {
        
//         priority_queue<Info, vector<Info>, compare> pq;
//         int maxi = INT_MIN;
//         int mini = INT_MAX;

//         // push first elements of each list
//         for (int i = 0; i < nums.size(); i++) {
//             int element = nums[i][0];
//             int row = i;
//             int col = 0;
//             pq.push(Info(element, row, col));
//             maxi = max(maxi, element);
//             mini = min(mini, element);
//         }

//         int ansStart = mini;
//         int ansEnd = maxi;

//         while (!pq.empty()) {
//             Info topNode = pq.top(); // copy (small struct, so cheap)
//             pq.pop();

//             mini = topNode.data;

//             if ((maxi - mini) < (ansEnd - ansStart)) {
//                 ansStart = mini;
//                 ansEnd = maxi;
//             }

//             if (topNode.colIndex + 1 < nums[topNode.rowIndex].size()) {
//                 int newElement = nums[topNode.rowIndex][topNode.colIndex + 1];
//                 maxi = max(maxi, newElement);
//                 pq.push(Info(newElement, topNode.rowIndex, topNode.colIndex + 1));
//             } else {
//                 break;
//             }
//         }

//         return {ansStart, ansEnd};
//     }
// };
