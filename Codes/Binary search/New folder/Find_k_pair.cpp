#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 1, count = 0;

        while (j < nums.size()) {
            int diff = nums[j] - nums[i];
            if (diff == k) {
                count++;
                i++;
                j++;
                // Skip duplicates
                while (j < nums.size() && nums[j] == nums[j - 1]) j++;
            } else if (diff > k) {
                i++;
            } else {
                j++;
            }
            if (i == j) j++;
        }
        return count;
    }
};

// this approach has time complexity of O(nlogn) and space complexity of O(1)

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: Count the frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        int count = 0;

        // Step 2: Check for valid pairs
        for (auto& [num, cnt] : freq) {
            if (k > 0 && freq.count(num + k)) {
                // Pair found where nums[j] = nums[i] + k
                count++;
            } else if (k == 0 && cnt > 1) {
                // Special case for k = 0, need at least two occurrences
                count++;
            }
        }

        return count;
    }
};

// this approach has time complexity of O(n) and space complexity of O(n)