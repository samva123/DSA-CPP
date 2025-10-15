#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp, int &maxLen) {
        if (i >= s1.length() || j >= s2.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if (s1[i] == s2[j]) {
            ans = 1 + solve(s1, s2, i + 1, j + 1, dp, maxLen);
            maxLen = max(maxLen, ans);
        } else {
            solve(s1, s2, i + 1, j, dp, maxLen);  // explore other paths
            solve(s1, s2, i, j + 1, dp, maxLen);
        }

        return dp[i][j] = ans;
    }

    int longestCommonSubstr(string &s1, string &s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                solve(s1, s2, i, j, dp, maxLen);
            }
        }

        return maxLen;
    }
};















class Solution {
public:
    int longestCommonSubstring(string a, string b) {
        int n = a.length();
        int m = b.length();

        // Initialize the DP table with zeros
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxLength = 0;

        // Reverse loops: Start from bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                // If characters match, increment the diagonal value
                if (a[i] == b[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                    maxLength = max(maxLength, dp[i][j]);
                } else {
                    dp[i][j] = 0; // Reset to 0 for substring
                }
            }
        }

        return maxLength;
    }
};
























class Solution {
  public:
    int longestCommonSubstr(string& a, string& b) {
        // your code here
        int n = a.length();
        int m = b.length();

        // Initialize the DP table with zeros
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        vector<int>curr(a.length()+1,0);
        vector<int>next(a.length()+1,0);
        int maxlength = 0;
        
        for(int j = m-1 ; j>=0 ; j--){
            for(int i = n-1 ; i >= 0 ; i--){
                int ans  = 0 ;
                if(a[i] == b[j]){
                    ans = 1+next[i+1];
                    
                }else{
                    ans = 0;
                }
                curr[i] = ans;
                maxlength = max(maxlength , curr[i]);
            }
            next = curr;
        }
        return maxlength;

        // // Reverse loops: Start from bottom-right to top-left
        // for (int i = n - 1; i >= 0; i--) {
        //     for (int j = m - 1; j >= 0; j--) {
        //         // If characters match, increment the diagonal value
        //         if (a[i] == b[j]) {
        //             curr[j] = 1 + next[j + 1];
        //             maxLength = max(maxLength, curr[j]);
        //         } else {
        //             curr[j] = 0; // Reset to 0 for substring
        //         }
                
        //     }
        //     next = curr;
        // }

        // return maxLength;
    }
};
