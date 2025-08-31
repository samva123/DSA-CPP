#include <queue>
#include<vector>
using namespace std;


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char &ch : tasks) {
            freq[ch - 'A']++;
        }

        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        int time = 0;
        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> store;
            int taskCount = 0;
            while (cycle-- && !pq.empty()) {
                if (pq.top() > 1) {
                    store.push_back(pq.top() - 1);
                }
                pq.pop();
                taskCount++;
            }
            for (int &x : store) {
                pq.push(x);
            }
            time += (pq.empty() ? taskCount : n + 1);
        }
        return time;
    }
};












////////////////////second solution//////////////////
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        
        // Count frequency of each task
        for (char &c : tasks) {
            freq[c - 'A']++;
        }

        // Find max frequency
        int maxFreq = *max_element(freq, freq + 26);

        // Count how many tasks have this max frequency
        int countMax = count(freq, freq + 26, maxFreq);

        // Formula:
        // (maxFreq - 1) * (n + 1) + countMax
        int part1 = (maxFreq - 1) * (n + 1) + countMax;

        // Result is the maximum of (total tasks) vs (formula result)
        return max((int)tasks.size(), part1);
    }
};

