#include <bits/stdc++.h>
using namespace std;

// Function to check if a substring is a palindrome.
bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

/*---------------------------------------------------
   1. Pure Recursion
---------------------------------------------------*/
int minPartitionsRec(int i, int n, string &str) {
    if (i == n) return 0;
    int minCost = INT_MAX;
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            int cost = 1 + minPartitionsRec(j + 1, n, str);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

int palindromePartitioningRec(string str) {
    int n = str.size();
    return minPartitionsRec(0, n, str) - 1;
}

/*---------------------------------------------------
   2. Recursion + Memoization
---------------------------------------------------*/
int minPartitionsMemo(int i, int n, string &str, vector<int> &dp) {
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];
    int minCost = INT_MAX;
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            int cost = 1 + minPartitionsMemo(j + 1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}

int palindromePartitioningMemo(string str) {
    int n = str.size();
    vector<int> dp(n, -1);
    return minPartitionsMemo(0, n, str, dp) - 1;
}

/*---------------------------------------------------
   3. Tabulation (Bottom-Up DP)
---------------------------------------------------*/
int palindromePartitioningTabu(string str) {
    int n = str.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        int minCost = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, str)) {
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0] - 1;
}

/*---------------------------------------------------
   Driver Code
---------------------------------------------------*/
int main() {
    string str = "BABABCBADCEDE";

    cout << "Using Pure Recursion: " << palindromePartitioningRec(str) << "\n";
    cout << "Using Memoization: "   << palindromePartitioningMemo(str) << "\n";
    cout << "Using Tabulation: "    << palindromePartitioningTabu(str) << "\n";

    return 0;
}
