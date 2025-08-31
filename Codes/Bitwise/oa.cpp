// Find the length of the longest subsequence in an array whose bitwise AND is not zero.

#include <bits/stdc++.h>
using namespace std;


int longestSubsequence(vector<int>& arr) {
    int ans = 0;
    for (int bit = 0; bit < 32; bit++) {
        int count = 0;
        for (int x : arr) {
            if (x & (1 << bit)) count++;
        }
        ans = max(ans, count);
    }
    return ans;
}
