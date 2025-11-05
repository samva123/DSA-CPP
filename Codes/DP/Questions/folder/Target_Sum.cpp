#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>&nums , int target , int i){
        if(i == nums.size()) return target == 0 ? 1 :0;

        int plus = solve(nums , target -nums[i] , i+1);
        int minus = solve(nums , target + nums[i] , i+1);
        return plus + minus ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums , target , 0);
        
    }
};


class Solution {
public:
// we can also use{i , target}
    int solve(vector<int>&nums , int target , int i , map<pair<int , int> , int>&dp){
        if(i == nums.size()) return target == 0 ? 1 :0;
        if(dp.find({target , i }) != dp.end()) return dp[{target , i}];

        int plus = solve(nums , target -nums[i] , i+1 , dp);
        int minus = solve(nums , target + nums[i] , i+1 ,dp);
        return dp[{target , i }] = plus + minus ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        map<pair<int , int> , int>dp; //{i , target} -> no. of ways 
        return solve(nums , target , 0 , dp);
        
    }
};

class Solution {
public:
    int solve(vector<int>&nums , int target){
        map<pair<int , int> , int>dp;
        dp[{nums.size() , 0}] = 1 ;

        int total = 0;
        for(auto num:nums) total +=num;

        for(int i = nums.size() -1 ; i>=0 ; --i){
            for(int sum = -total ; sum<=total ; ++sum){
                //if(dp.find({target , i }) != dp.end()) return dp[{target , i}];

                int plus = dp.find({i+1 , sum-nums[i]}) != dp.end() ? dp[{i+1,sum-nums[i]}] : 0;
                int minus = dp.find({i+1 , sum+nums[i]}) != dp.end() ? dp[{i+1,sum+nums[i]}] : 0;
                dp[{i,sum}] = plus + minus ;
    
            }

        }
        return dp[{0 ,target}];
    }        
        
    int findTargetSumWays(vector<int>& nums, int target) {

       // map<pair<int , int> , int>dp; //{i , target} -> no. of ways 
        return solve(nums , target);
        
    }
};



#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total) return 0; // If target is out of possible sum range

        // Initialize memoization table with dimensions (nums.size()) x (2*total+1)
        vector<vector<int>> memo(nums.size(), vector<int>(2 * total + 1, INT_MIN));
        return findWays(nums, target, 0, 0, total, memo);
    }

private:
    int findWays(vector<int>& nums, int target, int index, int currentSum, int total, vector<vector<int>>& memo) {
        if (index == nums.size()) {
            return currentSum == target ? 1 : 0;
        }
        if (memo[index][currentSum + total] != INT_MIN) {
            return memo[index][currentSum + total];
        }

        int add = findWays(nums, target, index + 1, currentSum + nums[index], total, memo);
        int subtract = findWays(nums, target, index + 1, currentSum - nums[index], total, memo);

        memo[index][currentSum + total] = add + subtract;
        return memo[index][currentSum + total];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int result = solution.findTargetSumWays(nums, target);
    cout << "Number of ways to achieve target " << target << ": " << result << endl;
    return 0;
}



#include <vector>
#include <numeric>

class Solution {
public:
    int solve(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total) return 0; // If target is out of possible sum range

        int n = nums.size();
        // Initialize dp array with dimensions (n+1) x (2*total+1)
        vector<vector<int>> dp(n + 1, vector<int>(2 * total + 1, 0));
        dp[n][total] = 1; // Base case: one way to sum up to 0 with no elements

        for (int i = n - 1; i >= 0; --i) {
            for (int sum = -total; sum <= total; ++sum) {
                if (dp[i + 1][sum + total] > 0) {
                    // Calculate the number of ways to achieve the current sum
                    dp[i][sum + nums[i] + total] += dp[i + 1][sum + total];
                    dp[i][sum - nums[i] + total] += dp[i + 1][sum + total];
                }
            }
        }
        return dp[0][target + total];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target);
    }
};


#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total) return 0; // If target is out of possible sum range

        int n = nums.size();
        // Initialize dp array with dimensions (n+1) x (2*total+1)
        vector<vector<int>> dp(n + 1, vector<int>(2 * total + 1, 0));
        dp[n][total] = 1; // Base case: one way to sum up to 0 with no elements

        for (int i = n - 1; i >= 0; --i) {
            for (int sum = -total; sum <= total; ++sum) {
                if (dp[i + 1][sum + total] > 0) {
                    // Calculate the number of ways to achieve the current sum
                    dp[i][sum + nums[i] + total] += dp[i + 1][sum + total];
                    dp[i][sum - nums[i] + total] += dp[i + 1][sum + total];
                }
            }
            // Print dp array state after each row iteration
            cout << "After processing element " << nums[i] << " (index " << i << "):" << endl;
            for (int j = 0; j <= 2 * total; ++j) {
                
                    cout << "dp[" << i << "][" << j  << "] = " << dp[i][j] << endl;
                
            }
            cout << endl;
        }
        return dp[0][target + total];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int result = solution.findTargetSumWays(nums, target);
    cout << "Number of ways to achieve target " << target << ": " << result << endl;
    return 0;
}
