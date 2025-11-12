#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int numsquarehelper(int n){
        if(n == 0) return 1 ;
        if(n < 0) return 0;

        int ans = INT_MAX;
        int i = 1 ;
        int end = sqrt(n);

        
        while(i <= end){
            int perfect = i*i;
            int number = 1+numsquarehelper(n-perfect);
            if(number < ans){
                ans = number;
            }
            ++i;
        }
        return ans;
    }
    int numSquares(int n) {
        return numsquarehelper(n)-1;
        
    }
};


/////////////////////////////////////////////

class Solution {
public:

    int numsquarehelper(int n ,vector<int>&dp){
        if(n == 0) return 1 ;
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int ans = INT_MAX;
        int i = 1 ;
        int end = sqrt(n);
        while(i <= end){
            int perfect = i*i;
            int number = 1+numsquarehelper(n-perfect,dp);
            if(number < ans){
                ans = number;
            }
            ++i;
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1 , -1);
        return numsquarehelper(n,dp)-1;
        
    }
};

/////////////////////////////////////////////////////////////

class Solution {
public:

    int numsquarehelper(int n ){
        vector<int>dp(n+1 , -1);
        
        dp[0] =1;

        for(int i = 1 ; i <=  n ; ++i){
        int ans = INT_MAX;
        int j = 1 ;
        int end = sqrt(i);
        while(j <= end){
            int perfect = j*j;
            int number = 1+dp[i-perfect];
            if(number < ans){
                ans = number;
            }
            ++j;
        }
        dp[i] = ans;
        // return dp[n];
        }
        return dp[n]; 
    }
    int numSquares(int n) {
        
        return numsquarehelper(n)-1;
        
    }
};

// 🥇 Approach 1 — Simple Recursion (No Memoization)
// int numsquarehelper(int n);

// ⏱ Time Complexity: O(n√n) ❌ Incorrect for recursion — read below

// Actually, since you are exploring all combinations of perfect squares recursively without memoization,
// you recompute the same subproblems multiple times.

// 👉 The recursion tree branches roughly √n times at each level and goes down up to depth n.
// Hence, exponential time — approximately O(√n ^ n) (very large).
// Formally, it’s exponential time, not polynomial.

// 💾 Space Complexity: O(n)

// Recursion stack can go as deep as n.

// ✅ Summary:

// Case	Time	Space
// Recursive brute force	Exponential (>> O(n√n))	O(n)
// 🥈 Approach 2 — Recursion + Memoization
// int numsquarehelper(int n, vector<int>& dp);

// ⏱ Time Complexity: O(n√n)

// Each n is solved once due to memoization.

// For each n, you iterate through all possible squares up to √n.
// ✅ So, O(n * √n) total.

// 💾 Space Complexity: O(n)

// O(n) for dp array.

// O(n) recursion depth (worst case).
// → Overall still O(n).

// ✅ Summary:

// Case	Time	Space
// Memoized recursion	O(n√n)	O(n)
// 🥉 Approach 3 — Tabulation (Bottom-Up DP)
// int numsquarehelper(int n);

// ⏱ Time Complexity: O(n√n)

// Outer loop runs n times.

// Inner loop checks all perfect squares ≤ i (≈ √i).
// → Total 1 + 2 + 3 + ... + √n ≈ n√n.

// 💾 Space Complexity: O(n)

// dp array of size n + 1.

// No recursion stack.

// ✅ Summary:

// Case	Time	Space
// Bottom-up DP	O(n√n)	O(n)
// 🧠 Final Comparison Table
// Approach	Method	Time Complexity	Space Complexity	Remarks
// 1	Pure Recursion	Exponential	O(n)	Very slow, redundant work
// 2	Memoized Recursion	O(n√n)	O(n)	Optimal time, easy to code
// 3	Tabulation	O(n√n)	O(n)	Most efficient in practice (iterative)