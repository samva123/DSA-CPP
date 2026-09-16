#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        // Total subsets = 2^n
        for (int mask = 0; mask < (1 << n); mask++) {

            vector<int> subset;

            // Check every bit
            for (int i = 0; i < n; i++) {

                // If i-th bit is set, include nums[i]
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            ans.push_back(subset);
        }

        return ans;
    }
};