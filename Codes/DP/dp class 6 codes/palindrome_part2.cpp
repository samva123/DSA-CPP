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















////Instead of only returning the minimum number of cuts,
/////we’ll print all sets of substrings that form palindromic partitions.


// Input:  "aab"
// Output partitions:
// a | a | b
// aa | b




#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

void allPalPartitions(int i, int n, string &str, vector<string> &path) {
    if (i == n) {
        for (int k = 0; k < path.size(); k++) {
            cout << path[k];
            if (k != path.size() - 1) cout << " | ";
        }
        cout << endl;
        return;
    }

    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            path.push_back(str.substr(i, j - i + 1));
            allPalPartitions(j + 1, n, str, path);
            path.pop_back(); // backtrack
        }
    }
}

int main() {
    string str = "aab";
    vector<string> path;
    cout << "All Palindromic Partitions:\n";
    allPalPartitions(0, str.size(), str, path);
    return 0;
}
















//////////only min cuts//////////////

#include <bits/stdc++.h>
using namespace std;

// ---------- Helper: Check Palindrome ----------
bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

// ---------- Step 1: Compute Minimum Cuts (DP) ----------
int getMinCuts(string &s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        int minCost = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, s)) {
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0] - 1;  // number of cuts = partitions - 1
}

// ---------- Step 2: Backtrack to Print Only Min-Cut Partitions ----------
void printMinCutPartitions(int i, string &s, int n, vector<string> &path, int minCuts, vector<vector<string>> &result) {
    if (i == n) {
        if ((int)path.size() - 1 == minCuts) {
            result.push_back(path);
        }
        return;
    }

    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, s)) {
            path.push_back(s.substr(i, j - i + 1));
            printMinCutPartitions(j + 1, s, n, path, minCuts, result);
            path.pop_back(); // backtrack
        }
    }
}

int main() {
    string s = "aab";
    int minCuts = getMinCuts(s);

    vector<string> path;
    vector<vector<string>> result;

    printMinCutPartitions(0, s, s.size(), path, minCuts, result);

    cout << "Minimum Cuts: " << minCuts << "\n";
    cout << "Partitions with Minimum Cuts:\n";
    for (auto &vec : result) {
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i != vec.size() - 1) cout << " | ";
        }
        cout << "\n";
    }
    return 0;
}


















/////////////////with pre-computed table/

#include <bits/stdc++.h>
using namespace std;

// Function to precompute palindrome table
vector<vector<bool>> precomputePalTable(string &s) {
    int n = s.size();
    vector<vector<bool>> pal(n, vector<bool>(n, false));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1])) {
                pal[i][j] = true;
            }
        }
    }
    return pal;
}

/*---------------------------------------------------
   Optimized Tabulation with precomputed palindrome table
---------------------------------------------------*/
int palindromePartitioningTabu(string str) {
    int n = str.size();
    vector<vector<bool>> isPal = precomputePalTable(str);
    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        int minCost = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPal[i][j]) {
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

    cout << "Using Optimized Tabulation: " << palindromePartitioningTabu(str) << "\n";

    return 0;
}








