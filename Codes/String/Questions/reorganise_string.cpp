#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string reorganizeString(string s) {
        // create freq map
        map<char, int> freqMap;
        for (auto ch : s)
        {
            freqMap[ch]++;
        }

        // make PQ.
        priority_queue<pair<int, char>> pq;
        for (auto it : freqMap)
        {
            pq.push({it.second, it.first});
        }

        // build answer string
        string ans;
        pair<int, char> hidden = {0, 0};
        while (!pq.empty())
        {
            if (ans.size() == 0)
            {
                hidden = pq.top();
                pq.pop();
                ans += hidden.second;
                hidden.first--;
            }
            else
            {
                auto top = pq.top();
                pq.pop();
                ans += top.second;
                top.first--;
                if (hidden.first > 0)
                    pq.push(hidden);
                hidden = top;
            }
        }
        if (ans.size() != s.size())
            return "";
        return ans;
        
    }
};





// ⏱️ Time Complexity

// Frequency counting → O(n)

// Building heap → O(k)

// Each push/pop per character → O(log k)
// ✅ O(n log k) overall, ≈ O(n) for small k.









//below code is commented because of new cpp syntax


// class Solution {
// public:
//     string reorganizeString(string s) {
//         unordered_map<char, int> freq_map;
//         for (char c : s) {
//             freq_map[c]++;
//         }

//         priority_queue<pair<int, char>> max_heap;
//         for (auto &[ch, freq] : freq_map) {
//             max_heap.push({freq, ch});
//         }

//         string res;
//         while (max_heap.size() >= 2) {
//             auto [freq1, char1] = max_heap.top(); max_heap.pop();
//             auto [freq2, char2] = max_heap.top(); max_heap.pop();

//             res += char1;
//             res += char2;

//             if (--freq1 > 0) max_heap.push({freq1, char1});
//             if (--freq2 > 0) max_heap.push({freq2, char2});
//         }

//         if (!max_heap.empty()) {
//             auto [freq, ch] = max_heap.top();
//             if (freq > 1) return "";
//             res += ch;
//         }

//         return res;
//     }
// };


///////////////////TIME//////////////////
// Building frequency map → O(n)

// Building heap → O(k) (k = distinct characters ≤ 26)

// Each push/pop → O(log k)

// Every character (n times total across all freq) causes at most one push & pop
// ⇒ O(n log k)

// ✅ Total = O(n log k) ≈ O(n) for English letters (since k ≤ 26).