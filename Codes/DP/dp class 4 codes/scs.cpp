#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 1. Recursive Version
class RecursiveSolution {
public:
    string solveUsingRecursion(string a, string b, int i, int j) {
        if (i >= a.length()) return b.substr(j);
        if (j >= b.length()) return a.substr(i);
        if (a[i] == b[j]) {
            return a[i] + solveUsingRecursion(a, b, i + 1, j + 1);
        } else {
            string option1 = a[i] + solveUsingRecursion(a, b, i + 1, j);
            string option2 = b[j] + solveUsingRecursion(a, b, i, j + 1);
            return (option1.length() <= option2.length()) ? option1 : option2;
        }
    }

    string shortestCommonSupersequence(string str1, string str2) {
        return solveUsingRecursion(str1, str2, 0, 0);
    }
};


















// 2. Memoization Version
class MemoizationSolution {
public:
    string solveUsingRecursion(string a, string b, int i, int j, vector<vector<string>>& dp) {
        if (i >= a.length()) return b.substr(j);
        if (j >= b.length()) return a.substr(i);
        if (!dp[i][j].empty()) return dp[i][j];
        if (a[i] == b[j]) {
            dp[i][j] = a[i] + solveUsingRecursion(a, b, i + 1, j + 1, dp);
        } else {
            string option1 = a[i] + solveUsingRecursion(a, b, i + 1, j, dp);
            string option2 = b[j] + solveUsingRecursion(a, b, i, j + 1, dp);
            dp[i][j] = (option1.length() <= option2.length()) ? option1 : option2;
        }
        return dp[i][j];
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<string>> dp(m, vector<string>(n, ""));
        return solveUsingRecursion(str1, str2, 0, 0, dp);
    }
};





























// 3. LCS-based Version
class LCSSolution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        string lcs = getLCS(s1, s2);
        int i = 0, j = 0;
        string result = "";
        for (char c : lcs) {
            while (s1[i] != c) {
                result += s1[i];
                i++;
            }
            while (s2[j] != c) {
                result += s2[j];
                j++;
            }
            result += c;
            i++;
            j++;
        }
        result += s1.substr(i) + s2.substr(j);
        return result;
    }

    string getLCS(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        string lcs = "";
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s1[i] == s2[j]) {
                lcs += s1[i];
                i++;
                j++;
            } else if (dp[i][j + 1] > dp[i + 1][j]) {
                j++;
            } else {
                i++;
            }
        }
        return lcs;
    }
};

// Example usage
int main() {
    string str1 = "abac", str2 = "cab";

    RecursiveSolution rsol;
    MemoizationSolution msol;
    LCSSolution lsol;

    cout << "Recursive: " << rsol.shortestCommonSupersequence(str1, str2) << endl;
    cout << "Memoized:  " << msol.shortestCommonSupersequence(str1, str2) << endl;
    cout << "LCS-Based: " << lsol.shortestCommonSupersequence(str1, str2) << endl;

    return 0;
}
























// below is just different way of writing solution of tabulation


#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.length(), n = s2.length();

        // Step 1: Compute LCS using a 2D DP array
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Step 2: Reconstruct the result string using LCS
        string result = "";
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                result = s1[i - 1] + result;
                --i;
                --j;
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                result = s1[i - 1] + result;
                --i;
            } else {
                result = s2[j - 1] + result;
                --j;
            }
        }

        // Add remaining characters from s1 and s2
        while (i > 0) result = s1[--i] + result;
        while (j > 0) result = s2[--j] + result;

        return result;
    }
};



