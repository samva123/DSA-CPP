// class Solution {
// public:
//     string reorganizeString(string s) {
//         int freq[26] = {0};
//         for(char c : s) freq[c - 'a']++;

//         priority_queue<pair<int,char>> pq;
//         for(int i = 0; i < 26; i++) {
//             if(freq[i]) pq.push({freq[i], i + 'a'});
//         }

//         string ans = "";

//         while(pq.size() > 1) {
//             auto [c1, ch1] = pq.top(); pq.pop();
//             auto [c2, ch2] = pq.top(); pq.pop();

//             ans += ch1;
//             ans += ch2;

//             if(--c1) pq.push({c1, ch1});
//             if(--c2) pq.push({c2, ch2});
//         }

//         if(pq.size()) {
//             auto [c, ch] = pq.top();
//             if(c > 1) return "";
//             ans += ch;
//         }

//         return ans;
//     }
// };