#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());
        int cost = 0;

        while(minHeap.size() > 1) {
            int first = minHeap.top(); minHeap.pop();
            int second = minHeap.top(); minHeap.pop();

            int sum = first + second;
            cost += sum;

            minHeap.push(sum);
        }
        return cost;
        
    }
};