#include <bits/stdc++.h>
using namespace std;

// ------------------- Pure Recursion -------------------
int findMinimumCostRec(int i, int j, vector<int> &cuts) {
    if (i > j) return 0;

    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++) {
        int ans = cuts[j + 1] - cuts[i - 1] +
                  findMinimumCostRec(i, ind - 1, cuts) +
                  findMinimumCostRec(ind + 1, j, cuts);
        mini = min(mini, ans);
    }
    return mini;
}

int minimumCostRec(int n, int c, vector<int> cuts) {
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    return findMinimumCostRec(1, c, cuts);
}

// ------------------- Memoization -------------------
int findMinimumCostMemo(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++) {
        int ans = cuts[j + 1] - cuts[i - 1] +
                  findMinimumCostMemo(i, ind - 1, cuts, dp) +
                  findMinimumCostMemo(ind + 1, j, cuts, dp);
        mini = min(mini, ans);
    }
    return dp[i][j] = mini;
}

int minimumCostMemo(int n, int c, vector<int> cuts) {
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return findMinimumCostMemo(1, c, cuts, dp);
}

// ------------------- Tabulation -------------------
int minimumCostTab(int n, int c, vector<int> cuts) {
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--) {
        for (int j = 1; j <= c; j++) {
            if (i > j) continue;
            int mini = INT_MAX;
            for (int ind = i; ind <= j; ind++) {
                int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                mini = min(mini, ans);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}

// ------------------- Driver -------------------
int main() {
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n = 7;

    cout << "Recursion: The minimum cost incurred is: " << minimumCostRec(n, c, cuts) << endl;
    cout << "Memoization: The minimum cost incurred is: " << minimumCostMemo(n, c, cuts) << endl;
    cout << "Tabulation: The minimum cost incurred is: " << minimumCostTab(n, c, cuts) << endl;

    return 0;
}
