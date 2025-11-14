#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int helper(vector<int>&days , vector<int>& costs , int i){

    if(i >= days.size()) return 0;

    int cost1  = costs[0] + helper(days , costs , i+1);


    //7 day
    int passendday = days[i] +7 -1;
    int j =1;
    while(j<days.size() && days[j] <= passendday){
        j++;
    }
    int cost7 = costs[1] + helper(days , costs ,j);

    //30 days
    passendday = days[i] +30 -1;
    j =1;
    while(j<days.size() && days[j] <= passendday){
        j++;
    }
    int cost30 = costs[2] + helper(days , costs ,j);

    return min(cost1 , min(cost7 ,cost30));


    
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return helper(days , costs , 0);
        
    }
};


////////////////////////////
class Solution {
public:
int helper(vector<int>&days , vector<int>& costs , int i ,  vector<int>&dp){

    if(i >= days.size()) return 0;

    //int n = days.size()-1;

    if(dp[i] != -1){
        return dp[i];
    }

    int cost1  = costs[0] + helper(days , costs , i+1 , dp);

    int passendday = days[i] +7 -1;
    int j =1;
    while(j<days.size() && days[j] <= passendday){
        j++;
    }
    int cost7 = costs[1] + helper(days , costs ,j ,dp);


    passendday = days[i] +30 -1;
    j =1;
    while(j<days.size() && days[j] <= passendday){
        j++;
    }
    int cost30 = costs[2] + helper(days , costs ,j,dp);

    dp[i] = min(cost1 , min(cost7 ,cost30));
    return dp[i];



    
}
    int mincostTickets(vector<int>& days, vector<int>& costs ) {
        vector<int>dp(days.size()+1 , -1);
        return helper(days , costs , 0 ,dp);
        
    }
};


///////////////////////////////////////



class Solution {
public:
    int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
        int n = days.size();
        std::vector<int> dp(n + 1, 0); // dp[i] stores the min cost from day i to the end

        for (int i = n - 1; i >= 0; --i) {
            // Option 1: Buy a 1-day ticket
            int cost1 = costs[0] + dp[i + 1];

            // Option 2: Buy a 7-day ticket
            int j = i;
            while (j < n && days[j] <= days[i] + 7-1) {
                ++j;
            }
            int cost7 = costs[1] + dp[j];

            // Option 3: Buy a 30-day ticket
            j = i;
            while (j < n && days[j] <= days[i] + 30-1) {
                ++j;
            }
            int cost30 = costs[2] + dp[j];

            // Take the minimum of all three options
            dp[i] = std::min(cost1, std::min(cost7, cost30));
        }

        return dp[0];
    }
};

// 🥇 Approach 1 — Pure Recursion (No Memoization)
// int helper(vector<int>& days, vector<int>& costs, int i);

// 🔹 Logic

// At every index i, you try 3 options:

// Buy a 1-day, 7-day, or 30-day pass
// Each recursive branch moves the index i forward according to the pass duration.

// ⏱ Time Complexity: Exponential — O(3^n)

// Each call spawns up to 3 recursive calls.

// No memoization → subproblems recomputed many times.

// Rough upper bound: O(3^n).

// 💾 Space Complexity: O(n)

// Only recursion stack (depth = number of days n).

// No extra data structure.

// ✅ Summary:

// Case	Time	Space	Remarks
// Recursive	O(3^n)	O(n)	Exponential, inefficient
// 🥈 Approach 2 — Recursion + Memoization
// int helper(vector<int>& days, vector<int>& costs, int i, vector<int>& dp);

// 🔹 Logic

// Same recursion, but now results are stored in a dp array where
// dp[i] = minimum cost starting from day index i.

// ⏱ Time Complexity: O(n²)

// There are n distinct states (i from 0 to n-1).

// For each state, the while loop to find the next valid index may scan up to n in the worst case.
// ✅ So total work ≈ O(n × n) = O(n²).

// 👉 (With some optimization like using binary search for j, this can be reduced to O(n log n).)

// 💾 Space Complexity: O(n)

// O(n) for dp array.

// O(n) recursion stack (worst case).
// ✅ Total: O(n).

// ✅ Summary:

// Case	Time	Space	Remarks
// Memoized Recursion	O(n²)	O(n)	Optimal time with caching
// 🥉 Approach 3 — Bottom-Up DP (Tabulation)
// for (int i = n - 1; i >= 0; --i) { ... }

// 🔹 Logic

// Iterative version of memoization.
// You fill dp[i] (minimum cost from i to end) using future states already computed (dp[j]).

// ⏱ Time Complexity: O(n²)

// Outer loop → n iterations.

// Inner scanning loops (while for 7-day and 30-day passes) can move through up to n days total.
// ✅ So O(n²) overall.

// 👉 Again, using binary search instead of linear scan could bring this to O(n log n).

// 💾 Space Complexity: O(n)

// Only a single DP array of size n + 1.

// No recursion stack.

// ✅ Summary:

// Case	Time	Space	Remarks
// Bottom-Up DP	O(n²)	O(n)	Most practical — no recursion overhead
// 🧠 Final Comparison Table
// Approach	Technique	Time Complexity	Space Complexity	Remarks
// 1	Simple Recursion	O(3^n)	O(n)	Exponential brute force
// 2	Memoized Recursion	O(n²)	O(n)	Efficient (can optimize to O(n log n))
// 3	Bottom-Up DP	O(n²)	O(n)	✅ Best practical version (no stack, same logic)

// Optimization Opportunities
// The current solutions (especially the bottom-up DP) are quite optimized for practical scenarios. However, we can slightly improve the efficiency by reducing the overhead of searching for valid indices jjj in the 7-day and 30-day ticket calculations.
// Optimized Bottom-Up Approach Using a Pointer for Valid Indices
// Instead of using a loop to find jjj, we can maintain a pointer for 7-day and 30-day ranges, which slides forward as needed. This reduces the O(n)O(n)O(n) search per iteration to O(1)O(1)O(1) amortized.
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0); // dp[i] stores the min cost from day i to the end
        int p7 = n, p30 = n;

        for (int i = n - 1; i >= 0; --i) {
            // Move the pointers for the valid range
            while (p7 > i && days[p7 - 1] >= days[i] + 7) --p7;
            while (p30 > i && days[p30 - 1] >= days[i] + 30) --p30;

            // Calculate costs
            int cost1 = costs[0] + dp[i + 1];
            int cost7 = costs[1] + dp[p7];
            int cost30 = costs[2] + dp[p30];

            dp[i] = std::min({cost1, cost7, cost30});
        }

        return dp[0];
    }
};

// Optimized Approach Complexity
// •	Time Complexity:
// o	The sliding pointers move forward O(n) times, reducing the index search cost.
// o	Total: O(n).
// •	Space Complexity:
// o	DP Array: O(n).
// o	Total: O(n).
// ________________________________________
// Summary
// 1.	Recursive Approach: Exponential O(3n)O(3^n)O(3n), O(n)O(n)O(n) space.
// 2.	Top-Down with Memoization: O(n2)O(n^2)O(n2), O(n)O(n)O(n) space.
// 3.	Bottom-Up DP: O(n2)O(n^2)O(n2), O(n)O(n)O(n) space.
// 4.	Optimized Bottom-Up with Pointers: O(n)O(n)O(n), O(n)O(n)O(n) space.
// The Optimized Bottom-Up Approach with Pointers is the best in terms of both time and space efficiency.
