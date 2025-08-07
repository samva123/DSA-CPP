#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool charsame(string &ans, char &newch, int k_1)
    {
        int it = ans.size() - 1;
        for (int i = 0; i < k_1; ++i)
        {
            if (newch != ans[it])
            {
                return false;
            }
            it--;
        }
        return true;
    }
    string removeDuplicates(string s, int k)
    {
        string ans;
        for (int i = 0; i < s.size(); ++i)
        {
            char &newch = s[i];
            if (ans.size() < k - 1)
            {
                ans.push_back(newch);
            }
            else
            {
                if (charsame(ans, newch, k - 1))
                {
                    for (int j = 0; j < k - 1; ++j)
                    {
                        ans.pop_back();
                    }
                }

                else
                {
                    ans.push_back(newch);
                }
            }
        }
        return ans;
    }
};

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        int i = 0;
        int j = 0;
        int n = s.size();
        vector<int> count(n);
        while (j < s.size())
        {
            s[i] = s[j];
            count[i] = 1;
            if (i > 0 && s[i] == s[i - 1])
            {
                count[i] += count[i - 1];
            }
            if (count[i] == k)
            {
                i -= k;
            }
            ++i, ++j;
        }
        return s.substr(0, i);
    }
};

// this is better approach because it has O(n) time complexity and first approach has O(n*k) time complexity
// and both have O(n) space complexity

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st; // Stack to store characters and their counts
        for (char c : s) {
            if (!st.empty() && st.top().first == c) {
                st.top().second++;
                if (st.top().second == k) {
                    st.pop(); // Remove the sequence when count reaches k
                }
            } else {
                st.push({c, 1}); // Add a new character to the stack
            }
        }
        // Reconstruct the string
        string result;
        while (!st.empty()) {
            result.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// space complexity is O(n) and time complexity is O(n) for this solution