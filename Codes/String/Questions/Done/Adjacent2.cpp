#include <bits/stdc++.h>
using namespace std;


string removeDuplicates(string s, int k) {
    bool changed = true;

    while (changed) {
        changed = false;

        for (int i = 0; i + k <= s.size(); i++) {
            bool ok = true;

            // check if k consecutive are equal
            for (int j = 1; j < k; j++) {
                if (s[i] != s[i + j]) {
                    ok = false;
                    break;
                }
            }

            // remove them
            if (ok) {
                s.erase(i, k);
                changed = true;
                break;  // must restart scanning
            }
        }
    }

    return s;
}


string removeDuplicates(string s, int k) {
    vector<int> count(s.size());
    int j = 0;

    for (int i = 0; i < s.size(); i++, j++) {
        s[j] = s[i];

        if (j > 0 && s[j] == s[j - 1])
            count[j] = count[j - 1] + 1;
        else
            count[j] = 1;

        if (count[j] == k)
            j -= k;
    }

    return s.substr(0, j);
}

// this is better approach because it has O(n) time complexity and first approach has O(n*k) time complexity
// and both have O(n) space complexity

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st;

        for(char c : s){
            if(!st.empty() && st.back().first == c){
                st.back().second++;
                if(st.back().second == k)
                    st.pop_back();
            }else{
                st.push_back({c,1});
            }
        }

        string ans = "";
        for(auto &p : st){
            ans.append(p.second, p.first);
        }
        return ans;
    }
};

// space complexity is O(n) and time complexity is O(n) for this solution