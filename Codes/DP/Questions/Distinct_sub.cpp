#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(string&s , string&t , int i , int j){
        if(j == t.size()) return 1 ;
        if(i == s.size()) return 0;
        int ans = 0 ; 
        if(s[i] == t[j]){
            ans +=  solve(s , t , i+1 , j+1);
        }
        return ans += solve(s , t , i+1 , j);

    }
    int numDistinct(string s, string t) {
        return solve(s , t , 0 , 0);
        
        
    }
};

// Time Complexity: O(2^(m+n)), where m and n are the lengths of s and t respectively. This is because each character in s can either be included or excluded, leading to an exponential number of recursive calls.
// Space Complexity: O(m + n) due to the recursion stack.




class Solution {
public:
    int solve(string&s , string&t , int i , int j , vector<vector<int>>dp){
        if(j == t.size()) return 1 ;
        if(i == s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0 ; 
        if(s[i] == t[j]){
            ans +=  solve(s , t , i+1 , j+1 , dp);
        }
        ans += solve(s , t , i+1 , j , dp);
        return dp[i][j] = ans;

    }
    int numDistinct(string s, string t) {

        vector<vector<int>>dp(s.size()+1  , vector<int>(t.size() +1 , -1));

        return solve(s , t , 0 , 0 , dp);
        
        
    }
};

// Time Complexity: O(m * n), where m and n are the lengths of s and t respectively. This is because each state (i, j) is computed only once.
// Space Complexity: O(m * n) due to the memoization table and O(m + n) for the recursion stack.






class Solution {
public:
    const int MOD = 1000000007;  // Define a large prime for modulo

    int solve(string& s, string& t) {
        vector<vector<long long>> dp(s.size() + 1, vector<long long>(t.size() + 1, 0));

        // Base case: If t is empty, there's exactly one way to match it (by deleting all characters in s)
        for (int i = 0; i <= s.size(); ++i) {
            dp[i][t.size()] = 1;
        }

        // Filling the dp table bottom-up
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = t.size() - 1; j >= 0; --j) {
                long long ans = 0;
                // If characters match, we can consider matching the rest
                if (s[i] == t[j]) {
                    ans += dp[i + 1][j + 1];  // Match the current character
                }
                ans += dp[i + 1][j];  // Skip the current character in s
                dp[i][j] = ans % MOD;  // Take modulo to avoid overflow
            }
        }
        return dp[0][0];  // Final result is stored in dp[0][0]
    }

    int numDistinct(string s, string t) {
        return solve(s, t);
    }
};


// Time Complexity: O(m * n), where m and n are the lengths of s and t respectively. This is because we are filling an m x n DP table.
// Space Complexity: O(m * n) for the DP table.





class Solution {
public:
     const int MOD = 1000000007;  // Define a large prime for modulo
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        
        // Edge case: if t is longer than s, no subsequences can match
        if (n > m) return 0;

        // Previous and current rows for space optimization
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        // Base case: if t is empty, there's exactly one way to match it
        prev[n] = 1;  // dp[i][n] = 1 for all i

        // Filling the dp table bottom-up
        for (int i = m - 1; i >= 0; --i) {
            curr[n] = 1;  // Base case for the current row
            for (int j = n - 1; j >= 0; --j) {
                long long ans = 0;
                 if (s[i] == t[j]) {
                    ans += prev[j + 1];  // Match the current character
                }
                ans += prev[j];  // Skip the current character in s
                curr[j] = ans % MOD;  // Take modulo to avoid overflow
            }
            prev = curr;  // Move to the next row
        }

        return prev[0];  // Final result is stored in prev[0]
    }
};































class Solution {
public:
    const int MOD = 1000000007;

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<long long> dp(m + 1, 0); // Represents "next" row
        dp[m] = 1; // Base case: If t is empty, there's exactly one way to match it

        // Fill the DP table bottom-up
        for (int i = n - 1; i >= 0; --i) {
            vector<long long> current(m + 1, 0); // Temporary array for current row
            current[m] = 1; // Base case for the current row

            for (int j = m - 1; j >= 0; --j) {
                long long ans = dp[j]; // Skip the current character in `s`
                if (s[i] == t[j]) {
                    ans += dp[j + 1]; // Match the current character
                }
                current[j] = ans % MOD; // Take modulo to avoid overflow
            }
            dp = current; // Update `dp` to represent the next row
        }

        return dp[0]; // Final result is stored in dp[0]
    }
};



















class Solution {
public:
    const int MOD = 1000000007;

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<long long> dp(m + 1, 0);
        dp[m] = 1; // Base case: If t is empty, there's exactly one way to match it

        // Fill the DP array bottom-up
        for (int i = n - 1; i >= 0; --i) {
            long long prev = dp[m]; // Store the previous value of dp[m] before updating
            for (int j = m - 1; j >= 0; --j) {
                long long temp = dp[j]; // Save the current value of dp[j] for the next iteration
                // If characters match, add the value from dp[j+1]
                if (s[i] == t[j]) {
                    dp[j] = (dp[j] + prev) % MOD;
                }
                prev = temp; // Update prev to be the value of dp[j] for the next iteration
            }
        }

        return dp[0]; // Final result is stored in dp[0]
    }
};
