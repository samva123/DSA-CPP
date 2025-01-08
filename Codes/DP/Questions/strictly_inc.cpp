#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
#define INF (1e9+1)
    int solve(vector<int>&arr1 , vector<int>&arr2 , int prev , int i ){
        if(i == arr1.size()) return 0;

        int op1 = INF;
        if(prev < arr1[i]){
            op1 = solve(arr1 , arr2 , arr1[i] , i+1);
        }
        int op2  = INF;
        auto it = upper_bound(arr2.begin() , arr2.end() , prev);
        if(it != arr2.end()){
            int index = it - arr2.begin();
            // arr1[i] = arr2[index];
            op2 = 1+solve(arr1 , arr2 , arr2[index] , i+1);
        }
        return min(op1 , op2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin() , arr2.end());

        int ans =  solve(arr1 , arr2 , -1 , 0);
        return ans == INF ? -1: ans;
        
    }
};


class Solution {
public:
#define INF (1e9+1)
    int solve(vector<int>&arr1 , vector<int>&arr2 , int prev , int i , map<pair<int , int>,int>&dp ){
        if(i == arr1.size()) return 0;

        if(dp.find({prev , i})!= dp.end()) return dp[{prev , i}];

        int op1 = INF;
        if(prev < arr1[i]){
            op1 = solve(arr1 , arr2 , arr1[i] , i+1,dp);
        }
        int op2  = INF;
        auto it = upper_bound(arr2.begin() , arr2.end() , prev);
        if(it != arr2.end()){
            int index = it - arr2.begin();
            // arr1[i] = arr2[index];
            op2 = 1+solve(arr1 , arr2 , arr2[index] , i+1,dp);
        }
        return dp[{prev , i }] = min(op1 , op2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin() , arr2.end());

        map<pair<int , int>,int>dp;
        int ans =  solve(arr1 , arr2 , -1 , 0 ,dp);
        return ans == INF ? -1: ans;
        
    }
};

// Time Complexity
// Number of States: The number of unique states is determined by the parameters i (index in arr1), prev (previous value), and the size of arr2.
// i can range from 0 to n (length of arr1).
// prev can take any value from arr1 or arr2, but for simplicity, we consider it as n possible values.
// Time to Compute Each State: For each state, we perform a binary search on arr2, which takes O(log m) time, where m is the length of arr2.
// Combining these, the overall time complexity is:

// Time Complexity: O(n * n * log m), where n is the length of arr1 and m is the length of arr2.
// Space Complexity
// Memoization Table: The memoization table (dp) stores results for O(n * n) states.
// Recursion Stack: The depth of the recursion stack can be at most n.
// Combining these, the overall space complexity is:

// Space Complexity: O(n * n) for the memoization table and O(n) for the recursion stack.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int n = arr1.size();
        int m = arr2.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
        dp[0][0] = -1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (arr1[i - 1] > dp[i - 1][j]) {
                    dp[i][j] = min(dp[i][j], arr1[i - 1]);
                }
                if (j > 0) {
                    auto it = upper_bound(arr2.begin(), arr2.end(), dp[i - 1][j - 1]);
                    if (it != arr2.end()) {
                        dp[i][j] = min(dp[i][j], *it);
                    }
                }
            }
        }

        for (int j = 0; j <= n; ++j) {
            if (dp[n][j] != INF) {
                return j;
            }
        }
        return -1;
    }
};


// Time Complexity
// Number of States: The number of unique states is O(n * n), where n is the length of arr1.
// Time to Compute Each State: For each state, we perform a binary search on arr2, which takes O(log m) time.
// Combining these, the overall time complexity is:

// Time Complexity: O(n^2 * log m), where n is the length of arr1 and m is the length of arr2.
// Space Complexity
// DP Table: The DP table (dp) stores results for O(n * n) states.
// Combining these, the overall space complexity is:

// Space Complexity: O(n * n).


// enough hai ye bhi