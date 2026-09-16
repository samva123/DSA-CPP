#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            ans ^= i;
            ans ^= nums[i];
        }

        return ans;
    }
};


class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right = right & (right - 1);
        }
        return right;
    }
};