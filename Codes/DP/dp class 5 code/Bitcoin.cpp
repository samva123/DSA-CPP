#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest bitonic subsequence
int longestBitonicSequence(vector<int>& arr, int n) {
    // Initialize two arrays to store the increasing and decreasing subsequences
    vector<int> dp1(n, 1); // dp1[i] stores the length of the longest increasing subsequence ending at arr[i]
    vector<int> dp2(n, 1); // dp2[i] stores the length of the longest decreasing subsequence ending at arr[i]

    // Calculate the longest increasing subsequence
    for (int i = 0; i < n; i++) {
        for (int prev_index = 0; prev_index < i; prev_index++) {
            if (arr[prev_index] < arr[i]) {
                dp1[i] = max(dp1[i], 1 + dp1[prev_index]);
            }
        }
    }

    // Reverse the direction of nested loops to calculate the longest decreasing subsequence
    for (int i = n - 1; i >= 0; i--) {
        for (int prev_index = n - 1; prev_index > i; prev_index--) {
            if (arr[prev_index] < arr[i]) {
                dp2[i] = max(dp2[i], 1 + dp2[prev_index]);
            }
        }
    }

    int maxi = -1;

    // Find the maximum length of the bitonic subsequence
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }

    return maxi;
}

int main() {
    vector<int> arr = {10,20,30};
    int n = arr.size();

    cout << "The length of the longest bitonic subsequence is " << longestBitonicSequence(arr, n) << endl;

    return 0;
}



























///////////////below is my approach/////////////









class Solution {
public:
    int solve(vector<int>& num, vector<int>& lis) {
        if (num.size() == 0) {
            return 0;
        }
        vector<int> ans;
        lis.push_back(1);
        ans.push_back(num[0]);
        for (int i = 1; i < num.size(); i++) {
            if (num[i] > ans.back()) {
                ans.push_back(num[i]);
                lis.push_back(ans.size());
            } else {
                int index = lower_bound(ans.begin(), ans.end(), num[i]) - ans.begin();
                ans[index] = num[i];
                lis.push_back(index + 1);
            }
        }
        return ans.size();
    }

    int LongestBitonicSequence(int n, vector<int>& nums) {
        vector<int> lis, lds;
        solve(nums, lis);
        reverse(nums.begin(), nums.end());
        solve(nums, lds);
        reverse(lds.begin(), lds.end());  // Reverse to align with original array

        int max_length = 0;
        for (int i = 0; i < n; i++) {
            if (lis[i] > 1 && lds[i] > 1) {  // Both parts must be valid
                max_length = max(max_length, lis[i] + lds[i] - 1);
            }
        }
        return max_length;
    }
};

