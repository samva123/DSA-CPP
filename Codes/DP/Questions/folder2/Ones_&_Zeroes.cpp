#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    void convert(vector<string>&strs, vector<pair<int , int>>&numstrs){
        for(auto  str:strs){
            int zeros = 0 , ones =0;
            for(auto ch : str){
                if(ch == '0') ++zeros;
                else ++ones;
            }
            numstrs.push_back({zeros,ones});
        }
    }

    int solve(vector<pair<int , int>>&numstrs , int i ,int m ,int n){
        if(i == numstrs.size()) return 0;

        int zeros = numstrs[i].first;
        int ones = numstrs[i].second;
        int include = 0 , exclude = 0;
        if( m -zeros >= 0 && n-ones >=0){
            include = 1+solve(numstrs , i+1,m-zeros,n-ones);}
            exclude = solve(numstrs , i+1 ,m ,n);
            return max(include,exclude);  

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int , int>>numstrs;//no. of zero and ones
        convert(strs,numstrs);
        return solve(numstrs ,0, m,n);
        
    }
};

class Solution {
public:
    void convert(vector<string>&strs, vector<pair<int , int>>&numstrs){
        for(auto  str:strs){
            int zeros = 0 , ones =0;
            for(auto ch : str){
                if(ch == '0') ++zeros;
                else ++ones;
            }
            numstrs.push_back({zeros,ones});
        }
    }

    int solve(vector<pair<int , int>>&numstrs ,int m ,int n){
        vector<vector<vector<int>>>dp(numstrs.size() +1, vector<vector<int>>(m+1 , vector<int>(n+1 ,0)));
        for(int i = numstrs.size()-1 ; i>=0 ; --i){
            for(int j = 0 ; j<=m ; ++j){
                for(int k = 0 ; k<=n ; k++){
                    
                    int zeros = numstrs[i].first;
                    int ones = numstrs[i].second;
                    int include = 0 , exclude = 0;
                    if( j -zeros >= 0 && k-ones >=0){
                        include = 1+dp[i+1][j-zeros][k-ones];}
                        exclude = dp[i+1][j][k];
                        dp[i][j][k] = max(include,exclude);  

    


                }
            }
        }
        return dp[0][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int , int>>numstrs;//no. of zero and ones
        convert(strs,numstrs);
        return solve(numstrs , m,n);
        
    }
};

// iska memo bhi dekhn hai
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string &s : strs) {
            int zeros = count(s.begin(), s.end(), '0');
            int ones = count(s.begin(), s.end(), '1');

            // Go backwards to avoid reusing the same string multiple times
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }

        return dp[m][n];
    } 
    
};




// 🥇 Approach 1 — Simple Recursion (No Memoization)
// int solve(vector<pair<int,int>>& numstrs, int i, int m, int n);

// 🔹 Logic

// At every index i, you can either:

// include the current string (if enough zeros/ones left), or

// exclude it.

// This leads to a binary decision tree.

// ⏱ Time Complexity: Exponential — O(2^n)

// For each of the n strings, you make 2 choices (include/exclude).

// Hence O(2^n) recursive calls in the worst case.

// Each call does constant work (count comparisons and arithmetic).

// 💾 Space Complexity: O(n)

// Only recursion stack space (depth = number of strings n).

// No DP array or extra data structures.

// ✅ Summary:

// Case	Time	Space	Remarks
// Recursive	O(2^n)	O(n)	Exponential — recomputes subproblems
// 🥈 Approach 2 — 3D DP (Bottom-Up Tabulation)
// vector<vector<vector<int>>> dp(numstrs.size() + 1,
//     vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

// 🔹 Logic

// Bottom-up iteration filling a 3D DP table:

// i → index in numstrs (up to n)

// j → available zeros (up to m)

// k → available ones (up to n)

// ⏱ Time Complexity: O(N * M * K)

// Outer loop: N (number of strings)

// Two inner loops: M (zeros) × K (ones)
// ✅ Total → O(N × M × K)

// 💾 Space Complexity: O(N * M * K)

// 3D DP array of that size.

// No recursion.

// ✅ Summary:

// Case	Time	Space	Remarks
// 3D DP	O(N·M·K)	O(N·M·K)	Clean but memory-heavy
// 🥉 Approach 3 — 2D DP (Optimized Tabulation)
// vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

// 🔹 Logic

// This is a 0/1 knapsack-style DP optimization:

// Iterate strings one by one.

// Update the DP table backward to prevent reusing the same string multiple times.

// ⏱ Time Complexity: O(N * M * K)

// For each of the N strings, you iterate over all (M × K) states.
// ✅ Same as 3D DP.

// 💾 Space Complexity: O(M * K)

// Only a 2D array is needed.

// No recursion, no 3D storage.
// ✅ Big improvement from O(N·M·K).

// 🧠 Final Comparison Table
// Approach	Technique	Time Complexity	Space Complexity	Remarks
// 1	Simple Recursion	O(2^N)	O(N)	Exponential — impractical
// 2	3D DP	O(N·M·K)	O(N·M·K)	Efficient but high memory
// 3	2D DP (Optimized)	O(N·M·K)	O(M·K)	✅ Best — optimal time & space