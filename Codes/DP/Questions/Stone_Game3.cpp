#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>&sv , int i){
        if(i == sv.size()) return 0;

        int ans = INT_MIN;
        int total = 0;
        for(int x = 1 ; x<=3 ; ++x){
            if(i+x-1 >= sv.size()) break ;
            total += sv[i+x-1];

            
            ans = max(ans , total - solve(sv , i+x));

        }
        return ans ;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int ans = solve(stoneValue,0);

        if(ans>0) return "Alice";
        if(ans<0) return "Bob";
        return "Tie";
        
    }
};



class Solution {
public:
    int solve(vector<int>&sv , int i ,vector<int>dp){
        if(i == sv.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MIN;
        int total = 0;
        for(int x = 1 ; x<=3 ; ++x){
            if(i+x-1 >= sv.size()) break ;
            total += sv[i+x-1];
            ans = max(ans , total - solve(sv , i+x , dp));

        }
        return dp[i] = ans ;
    }
    string stoneGameIII(vector<int>& stoneValue) {
       
        vector<int>dp(stoneValue.size()+1 ,-1);
         int ans = solve(stoneValue,0,dp);

        if(ans>0) return "Alice";
        if(ans<0) return "Bob";
        return "Tie";
        
    }
};



class Solution {
public:
    int solve(vector<int>&sv){
        vector<int>dp(sv.size()+1 ,0);
        for(int i = sv.size()-1 ; i>=0 ; i--){
            int ans = INT_MIN;
            int total = 0;
            for(int x = 1 ; x<=3 ; ++x){
                if(i+x-1 >= sv.size()) break ;
                total += sv[i+x-1];
                ans = max(ans , total - dp[i+x]);

            }
            dp[i] =ans;

        }
        return dp[0];

        
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int ans = solve(stoneValue);

        if(ans>0) return "Alice";
        if(ans<0) return "Bob";
        return "Tie";
        
    }
};


// First Approach (Recursive with Memoization)
// Time Complexity: (O(3^n))
// The recursion explores all possible moves, and for each move, it can go up to 3 steps, leading to an exponential time complexity.
// Space Complexity: (O(n))
// The recursion depth can go up to (n), where (n) is the number of elements in stoneValue.
// Second Approach (Dynamic Programming)
// Time Complexity: (O(n))
// The nested loops iterate over the elements of stoneValue and the possible moves (up to 3), leading to a linear time complexity.
// Space Complexity: (O(n))
// The DP array dp has a size of (n+1), leading to a linear space complexity.





// bottom up wali or niche wali ke time mein kuch khaas fark nahi hai



// Yes, we can reduce the space complexity to O(1)O(1)O(1) by observing that the computation for dp[i] only depends on the values dp[i+1], dp[i+2], and dp[i+3]. This allows us to use a rolling array or just a few variables to store the required states.
// Optimized Code with O(1)O(1)O(1) Space Complexity
// cpp
// Copy code
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(4, 0); // Only store dp[i+1], dp[i+2], dp[i+3]

        for (int i = n - 1; i >= 0; --i) {
            int total = 0, ans = INT_MIN;
            for (int x = 1; x <= 3; ++x) {
                if (i + x - 1 >= n) break;
                total += stoneValue[i + x - 1];
                ans = max(ans, total - dp[(i + x) % 4]);
            }
            dp[i % 4] = ans;
        }

        int ans = dp[0];

        if (ans > 0) return "Alice";
        if (ans < 0) return "Bob";
        return "Tie";
    }
};
// Explanation of Optimization
// •	The dp array now only keeps track of the last 4 states instead of all n+1n+1n+1 states, leveraging the observation that each state depends only on the next 3 states.
// •	By updating dp in a cyclic manner using i % 4, we ensure no extra space is used for the DP table.
// Final Complexity
// 1.	Time Complexity: O(n)O(n)O(n), since we iterate over nnn states with up to 3 iterations per state.
// 2.	Space Complexity: O(1)O(1)O(1), as only 4 variables are used to store the DP states.
// This is the most space-efficient solution while maintaining the same time complexity.

