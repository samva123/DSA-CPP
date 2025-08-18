#include <bits/stdc++.h>
using namespace std;

// ------------------- Pure Recursion -------------------
int maxCoinsHelperRec(int i, int j, vector<int> &nums) {
    if (i > j) return 0;
    int maxCoins = INT_MIN;

    for (int k = i; k <= j; k++) {
        int coins = nums[i - 1] * nums[k] * nums[j + 1];
        int remainingCoins = maxCoinsHelperRec(i, k - 1, nums) + maxCoinsHelperRec(k + 1, j, nums);
        maxCoins = max(maxCoins, coins + remainingCoins);
    }
    return maxCoins;
}

int maxCoinsRec(vector<int> nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    return maxCoinsHelperRec(1, n, nums);
}

// ------------------- Memoization -------------------
int maxCoinsHelperMemo(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int maxCoins = INT_MIN;
    for (int k = i; k <= j; k++) {
        int coins = nums[i - 1] * nums[k] * nums[j + 1];
        int remainingCoins = maxCoinsHelperMemo(i, k - 1, nums, dp) + maxCoinsHelperMemo(k + 1, j, nums, dp);
        maxCoins = max(maxCoins, coins + remainingCoins);
    }
    return dp[i][j] = maxCoins;
}

int maxCoinsMemo(vector<int> nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    return maxCoinsHelperMemo(1, n, nums, dp);
}

// ------------------- Tabulation -------------------
int maxCoinsTab(vector<int> nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (i > j) continue;
            int maxi = INT_MIN;
            for (int ind = i; ind <= j; ind++) {
                int coins = nums[i - 1] * nums[ind] * nums[j + 1];
                int remainingCoins = dp[i][ind - 1] + dp[ind + 1][j];
                maxi = max(maxi, coins + remainingCoins);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}

// ------------------- Driver -------------------
int main() {
    vector<int> nums = {3, 1, 5, 8};

    cout << "Recursion: Maximum coins obtained = " << maxCoinsRec(nums) << endl;
    cout << "Memoization: Maximum coins obtained = " << maxCoinsMemo(nums) << endl;
    cout << "Tabulation: Maximum coins obtained = " << maxCoinsTab(nums) << endl;

    return 0;
}
