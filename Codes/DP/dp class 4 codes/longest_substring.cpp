#include <bits/stdc++.h>
using namespace std;



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
        
        vector<int>curr(b.length()+1,0);
        vector<int>next(b.length()+1,0);
        int maxLength = 0;

        // Reverse loops: Start from bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                // If characters match, increment the diagonal value
                if (a[i] == b[j]) {
                    curr[j] = 1 + next[j + 1];
                    maxLength = max(maxLength, curr[j]);
                } else {
                    curr[j] = 0; // Reset to 0 for substring
                }
                
            }
            next = curr;
        }

        return maxLength;
    }
};