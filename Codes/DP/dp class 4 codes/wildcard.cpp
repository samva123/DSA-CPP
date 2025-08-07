#include <bits/stdc++.h>
using namespace std;

// ------------------------
// Helper: isAllStars()
// ------------------------
bool isAllStars(string &S1, int i) {
    for (int j = 0; j <= i; j++) {
        if (S1[j] != '*')
            return false;
    }
    return true;
}

bool isAllStars1Based(string &S1, int i) {
    for (int j = 1; j <= i; j++) {
        if (S1[j - 1] != '*')
            return false;
    }
    return true;
}

// ------------------------
// 1. Recursive with Memoization (Top-down DP)
// ------------------------
bool wildcardMatchingMemoUtil(string &S1, string &S2, int i, int j, vector<vector<int>> &dp) {
    if (i < 0 && j < 0) return true;
    if (i < 0 && j >= 0) return false;
    if (j < 0 && i >= 0) return isAllStars(S1, i);

    if (dp[i][j] != -1) return dp[i][j];

    if (S1[i] == S2[j] || S1[i] == '?')
        return dp[i][j] = wildcardMatchingMemoUtil(S1, S2, i - 1, j - 1, dp);
    if (S1[i] == '*')
        return dp[i][j] = wildcardMatchingMemoUtil(S1, S2, i - 1, j, dp) || wildcardMatchingMemoUtil(S1, S2, i, j - 1, dp);

    return dp[i][j] = false;
}

bool wildcardMatchingMemo(string &S1, string &S2) {
    int n = S1.size(), m = S2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return wildcardMatchingMemoUtil(S1, S2, n - 1, m - 1, dp);
}

// ------------------------
// 2. Tabulation (Bottom-up DP)
// ------------------------
bool wildcardMatchingTab(string &S1, string &S2) {
    int n = S1.size(), m = S2.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    dp[0][0] = true;
    for (int j = 1; j <= m; j++) dp[0][j] = false;
    for (int i = 1; i <= n; i++) dp[i][0] = isAllStars1Based(S1, i);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (S1[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else
                dp[i][j] = false;
        }
    }

    return dp[n][m];
}

// ------------------------
// 3. Space Optimized Tabulation
// ------------------------
bool wildcardMatchingSpaceOptimized(string &S1, string &S2) {
    int n = S1.size(), m = S2.size();
    vector<bool> prev(m + 1, false), cur(m + 1, false);

    prev[0] = true;

    for (int i = 1; i <= n; i++) {
        cur[0] = isAllStars1Based(S1, i);
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
                cur[j] = prev[j - 1];
            else if (S1[i - 1] == '*')
                cur[j] = prev[j] || cur[j - 1];
            else
                cur[j] = false;
        }
        prev = cur;
    }

    return prev[m];
}

// ------------------------
// Main Function
// ------------------------
int main() {
    string S1 = "ab*cd";
    string S2 = "abdefcd";

    cout << "Recursive with Memoization: ";
    if (wildcardMatchingMemo(S1, S2))
        cout << "Match\n";
    else
        cout << "No Match\n";

    cout << "Tabulation (2D DP): ";
    if (wildcardMatchingTab(S1, S2))
        cout << "Match\n";
    else
        cout << "No Match\n";

    cout << "Space Optimized Tabulation: ";
    if (wildcardMatchingSpaceOptimized(S1, S2))
        cout << "Match\n";
    else
        cout << "No Match\n";

    return 0;
}
