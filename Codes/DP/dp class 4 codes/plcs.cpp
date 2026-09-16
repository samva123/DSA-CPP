#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    
    void solveUsingTabulation(string &a, string &b, vector<vector<int>> &dp) {
        int n = a.length();
        int m = b.length();
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = 1 + dp[i + 1][j + 1];
                } else {
                    ans = max(dp[i][j + 1], dp[i + 1][j]);
                }
                dp[i][j] = ans;
            }
        }
    }

   
    void backtrackDP(string &s1, string &s2, int i, int j, vector<vector<int>> &dp, set<string> &ans, string temp, unordered_map<string, bool> &mpp) {
        if (i == s1.length() || j == s2.length()) {
            //reverse(temp.begin(), temp.end());
            ans.insert(temp);
            return;
        }

        string key = to_string(i) + "," + to_string(j) + "," + temp;
        if (mpp.find(key) != mpp.end()) return;
        mpp[key] = true;

        if (s1[i] == s2[j]) {
            backtrackDP(s1, s2, i + 1, j + 1, dp, ans, temp + s1[i], mpp);
        } else {
            if (dp[i][j] == dp[i + 1][j]) {
                backtrackDP(s1, s2, i + 1, j, dp, ans, temp, mpp);
            }
            if (dp[i][j] == dp[i][j + 1]) {
                backtrackDP(s1, s2, i, j + 1, dp, ans, temp, mpp);
            }
        }
    }

    
    vector<string> allLCS(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        
        solveUsingTabulation(s, t, dp);

        set<string> ansSet;
        unordered_map<string, bool> mpp;
        string temp = "";

        
        backtrackDP(s, t, 0, 0, dp, ansSet, temp, mpp);

        vector<string> result(ansSet.begin(), ansSet.end());
        return result;
    }
};


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    map<pair<int,int>, set<string>> memo;

    set<string> solve(string &s, string &t, int i, int j) {
        int n = s.size();
        int m = t.size();

        if (i == n || j == m) {
            return {""};
        }

        if (memo.count({i, j})) {
            return memo[{i, j}];
        }

        set<string> ans;

        if (s[i] == t[j]) {
            set<string> temp = solve(s, t, i + 1, j + 1);

            for (auto &str : temp) {
                ans.insert(s[i] + str);
            }
        }
        else {
            if (dp[i + 1][j] == dp[i][j]) {
                set<string> temp = solve(s, t, i + 1, j);

                for (auto &str : temp) {
                    ans.insert(str);
                }
            }

            if (dp[i][j + 1] == dp[i][j]) {
                set<string> temp = solve(s, t, i, j + 1);

                for (auto &str : temp) {
                    ans.insert(str);
                }
            }
        }

        return memo[{i, j}] = ans;
    }

    vector<string> allLCS(string s, string t) {
        int n = s.size();
        int m = t.size();

        dp.assign(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        set<string> ans = solve(s, t, 0, 0);

        return vector<string>(ans.begin(), ans.end());
    }
};