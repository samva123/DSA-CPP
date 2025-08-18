#include <bits/stdc++.h>
using namespace std;

// ------------------ 1. Pure Recursion ------------------
int f_recursive(vector<int>& arr, int i, int j) {
    if (i == j) return 0;
    int mini = INT_MAX;
    for (int k = i; k <= j - 1; k++) {
        int ans = f_recursive(arr, i, k) + f_recursive(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        mini = min(mini, ans);
    }
    return mini;
}
int matrixMultiplication_recursive(vector<int>& arr, int N) {
    return f_recursive(arr, 1, N - 1);
}

// ------------------ 2. Recursion + Memoization ------------------
int f_memo(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int mini = INT_MAX;
    for (int k = i; k <= j - 1; k++) {
        int ans = f_memo(arr, i, k, dp) + f_memo(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
        mini = min(mini, ans);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication_memo(vector<int>& arr, int N) {
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return f_memo(arr, 1, N - 1, dp);
}

// ------------------ 3. Tabulation (Bottom-Up) ------------------
int matrixMultiplication_tab1(vector<int>& arr, int N) {
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = N - 1; i >= 1; i--) {
        for (int j = i + 1; j < N; j++) {
            int mini = 1e9;
            for (int k = i; k < j; k++) {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}

// ------------------ 4. Tabulation (Chain Length) ------------------
int matrixMultiplication_tab2(vector<int>& arr, int N) {
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int len = 2; len < N; len++) {
        for (int i = 1; i < N - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][N - 1];
}

// ------------------ Main ------------------
int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size();

    cout << "Pure Recursion: " << matrixMultiplication_recursive(arr, n) << endl;
    cout << "Recursion + Memoization: " << matrixMultiplication_memo(arr, n) << endl;
    cout << "Tabulation (Bottom-Up): " << matrixMultiplication_tab1(arr, n) << endl;
    cout << "Tabulation (Chain Length): " << matrixMultiplication_tab2(arr, n) << endl;

    return 0;
}


//////////////////only for my satisfaction///////////////////

#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int i = N - 1; i >= 1; i--) {
        for (int j = 1; j < N; j++) {

            if(i >= j){
                continue;
            }
            int mini = 1e9;
            for (int k = i; k < j; k++) {
                int steps = arr[i - 1] * arr[k] * arr[j]
                          + dp[i][k]
                          + dp[k + 1][j];
                if (steps < mini) mini = steps;
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}