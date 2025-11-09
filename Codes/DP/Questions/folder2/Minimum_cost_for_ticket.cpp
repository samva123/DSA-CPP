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


class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> daySet(days.begin(), days.end());
        int lastDay = days.back();
        vector<int> dp(lastDay + 1, 0);

        for (int i = 1; i <= lastDay; ++i) {
            if (daySet.find(i) == daySet.end()) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = min({
                    dp[i - 1] + costs[0],
                    dp[max(0, i - 7)] + costs[1],
                    dp[max(0, i - 30)] + costs[2]
                });
            }
        }

        return dp[lastDay];
    }
};


// this is also a approach written by co-pilot with O(n) time complexity and O(n) space complexity
// but pointer approach will work better 


