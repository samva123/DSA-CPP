////out of range question
// update(1 august 2026) got the question completely and if face problem follow below link 
// https://chatgpt.com/share/6a6d7c64-c2e4-83ee-ab07-1e57cca063b5

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        
        if (i == j)
            return nums[i];

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        int pickLeft = nums[i] - solve(i + 1, j, nums, dp);
        int pickRight = nums[j] - solve(i, j - 1, nums, dp);
        return dp[i][j] = max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {
       
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        return solve(0, n - 1, nums, dp) >= 0;
    }
};


class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            dp[i][i] = nums[i];

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {

                int pickLeft = nums[i] - dp[i + 1][j];
                int pickRight = nums[j] - dp[i][j - 1];
                dp[i][j] = max(pickLeft, pickRight);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};