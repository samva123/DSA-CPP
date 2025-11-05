#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(vector<int>& nums , int start , int end){
        if(start>end) return 0;
        int coins = INT_MIN;
        for(int i = start ; i <= end ; i++){
            coins = max(coins , nums[start-1]*nums[i]*nums[end+1]
            +solve(nums , start , i-1)
            +solve(nums , i+1 ,end));
        }
        return coins;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin() ,1);
        nums.insert(nums.end() ,1);
        return solve(nums,1,nums.size()-2);

        
    }
};


class Solution {
public:
    int solve(vector<int>& nums , int start , int end , vector<vector<int>>&dp){
        if(start>end) return 0;

        if(dp[start][end] != -1) return dp[start][end];
        int coins = INT_MIN; 
        for(int i = start ; i <= end ; i++){
            coins = max(coins , nums[start-1]*nums[i]*nums[end+1]
            +solve(nums , start , i-1 ,dp)
            +solve(nums , i+1 ,end ,dp));
        }
        return dp[start][end] = coins;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin() ,1);
        nums.insert(nums.end() ,1);

        vector<vector<int>>dp(nums.size() , vector<int>(nums.size() , -1));
        return solve(nums,1,nums.size()-2 , dp);

        
    }
};

class Solution {
public:
    int solve(vector<int>& nums ){
        vector<vector<int>>dp(nums.size() , vector<int>(nums.size() , 0));
        //if(start>end) return 0;
        for(int start = nums.size()-2 ; start >= 1  ; start--){
            for(int end = start  ; end <= nums.size()-2 ; end++){

                // if(start >= end) {
                //     continue;
                // }
               
                int coins = INT_MIN; 
                for(int i = start ; i <= end ; i++){
                    coins = max(coins , nums[start-1]*nums[i]*nums[end+1]
                    +dp[start][i-1]
                    +dp[i+1][end]);
                }
                dp[start][end] = coins;
                
            }
        }
        return dp[1][nums.size()-2];
         
        
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin() ,1);
        nums.insert(nums.end() ,1);

        
        return solve(nums );

        
    }
};






// First Approach (Recursive)
// Time Complexity: (O(n!))
// The recursion explores all possible ways to burst the balloons, leading to a factorial time complexity.
// Space Complexity: (O(n))
// The recursion depth can go up to (n), where (n) is the number of balloons.


// Second Approach (Recursive with Memoization)
// Time Complexity: (O(n^3))
// The memoization table reduces the number of redundant calculations, leading to a cubic time complexity.
// Space Complexity: (O(n^2))
// The memoization table dp has dimensions ((n+2) \times (n+2)), leading to a quadratic space complexity.


// Third Approach (Dynamic Programming)
// Time Complexity: (O(n^3))
// The nested loops iterate over the possible subproblems and the possible balloons to burst, leading to a cubic time complexity.
// Space Complexity: (O(n^2))
// The DP table dp has dimensions ((n+2) \times (n+2)), leading to a quadratic space complexity.
// Optimization
// The third approach is already optimized in terms of time and space complexity. It uses a bottom-up dynamic programming approach with a time complexity of (O(n^3)) and a space complexity of (O(n^2)), which is the best we can achieve for this problem.








