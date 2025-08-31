#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        unordered_map<int,int> freq;
        for(int card : hand) freq[card]++;

        sort(hand.begin(), hand.end());

        for(int card : hand) {
            if(freq[card] > 0) {

                
                int count = freq[card];
                for(int i = 0; i < groupSize; i++) {
                    if(freq[card + i] < count) return false;
                    freq[card + i] -= count;
                }
            }
        }
        return true;
    }
};







////////////////////second solution/////////////

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        unordered_map<int, int> freq;
        for (int card : hand) freq[card]++;

        // Min-heap for smallest card each time
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &p : freq) pq.push(p.first);

        while (!pq.empty()) {
            int start = pq.top();

            // Try to form a group starting from 'start'
            for (int i = 0; i < groupSize; i++) {
                int curr = start + i;
                if (freq[curr] == 0) return false;  // can't form group
                freq[curr]--;

                // If count becomes 0, remove from heap
                if (freq[curr] == 0) {
                    if (curr != pq.top()) return false; // order mismatch
                    pq.pop();
                }
            }
        }
        return true;
    }
};
