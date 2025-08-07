#include <bits/stdc++.h>
using namespace std;

const int prime = 1e9 + 7;

// -------------------------------------
// 1. Recursive with Memoization (Top-down DP)
// -------------------------------------
int countUtil(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp) {
    if (ind2 < 0)
        return 1;
    if (ind1 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    int result = 0;
    if (s1[ind1] == s2[ind2]) {
        int leaveOne = countUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
        int stay = countUtil(s1, s2, ind1 - 1, ind2, dp);
        result = (leaveOne + stay) % prime;
    } else {
        result = countUtil(s1, s2, ind1 - 1, ind2, dp);
    }

    dp[ind1][ind2] = result;
    return result;
}

int topDownMemo(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return countUtil(s1, s2, n - 1, m - 1, dp);
}

// -------------------------------------
// 2. Tabulation (Bottom-up DP)
// -------------------------------------
int bottomUpTabulation(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % prime;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][m];
}

// -------------------------------------
// 3. Space Optimized: Single 1D DP Array
// -------------------------------------
int oneDOptimized(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    vector<int> dp(m + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[j] = (dp[j] + dp[j - 1]) % prime;
            }
        }
    }

    return dp[m];
}

// -------------------------------------
// 4. Fully Optimized with Two 1D Arrays
// -------------------------------------
int twoD_1D_Optimized(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    prev[0] = 1;

    for (int i = 1; i <= n; i++) {
        curr[0] = 1;
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                curr[j] = (prev[j - 1] + prev[j]) % prime;
            } else {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }

    return prev[m];
}

// -------------------------------------
// Main Driver
// -------------------------------------
int main() {
    string s1 = "babgbag";
    string s2 = "bag";

    cout << "Top-Down Memoization: " << topDownMemo(s1, s2) << endl;
    cout << "Bottom-Up Tabulation: " << bottomUpTabulation(s1, s2) << endl;
    cout << "1D Optimized: " << oneDOptimized(s1, s2) << endl;
    cout << "Two 1D Arrays Optimized: " << twoD_1D_Optimized(s1, s2) << endl;

    return 0;
}
