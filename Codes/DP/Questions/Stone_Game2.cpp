#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(vector<int>&piles , int i , int m , int alice){
        if(i == piles.size()) return 0;

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0 ;

        for(int x=1 ; x<=2*m ; x++){
            if(i+x-1 >= piles.size()) break;
            total += piles[i+x-1];
            if(alice)
                ans = max(ans , total + solve(piles , i+x , max(x,m) , !alice));
            else
                ans = min(ans , solve(piles , i+x , max(x,m) , !alice));
        }
        return ans ;
    }
    int stoneGameII(vector<int>& piles) {
        return solve(piles ,0 ,1 , true);
        
    }
};

// iski time complexity n^3 hai or space complexity n but hame pata hai ye kaafi slow hoga 



class Solution {
public:
    int solve(vector<int>&piles , int i , int m , int alice ,vector<vector<vector<int>>>dp){
        if(i == piles.size()) return 0;

        if(dp[i][m][alice] != -1) return dp[i][m][alice];

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0 ;

        for(int x=1 ; x<=2*m ; x++){
            if(i+x-1 >= piles.size()) break;
            total += piles[i+x-1];
            if(alice)
                ans = max(ans , total + solve(piles , i+x , max(x,m) , !alice,dp));
            else
                ans = min(ans , solve(piles , i+x , max(x,m) , !alice,dp));
        }
        return dp[i][m][alice] = ans ;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
        return solve(piles ,0 ,1 , true ,dp);
        
    }
};



class Solution {
public:
    int solve(vector<int>&piles ){
        vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,0)));
        //if(i == piles.size()) return 0;

        for(int i = piles.size()-1 ; i>=0 ; --i){
            for(int M = piles.size() ; M>=1 ; --M){
                for(int alice = 0 ; alice<=1 ; ++alice){
                    int ans = alice ? INT_MIN : INT_MAX;
                    int total = 0 ;

                    for(int x=1 ; x<=2*M ; x++){
                        if(i+x-1 >= piles.size()) break;
                        total += piles[i+x-1];
                        if(alice)
                            ans = max(ans , total + dp[i+x][max(x,M)][!alice]);
                        else
                            ans = min(ans , dp[i+x][max(x,M)][!alice]);
                    }
                    dp[i][M][alice] = ans;
                }

            }
        }
        return dp[0][1][1];

       
    }
    int stoneGameII(vector<int>& piles) {
        //vect<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
        return solve(piles );
        
    }
};



// iski time complexity bhi n^3 hai but space complexity n^2 hai or ye fast hai or hum 
// isse jyada optimise minimally kar sakte hai isko time ke terms mein 


class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> suffixSum(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int M = 1; M <= n; ++M) {
                for (int x = 1; x <= 2 * M && i + x <= n; ++x) {
                    dp[i][M] = max(dp[i][M], suffixSum[i] - dp[i + x][max(M, x)]);
                }
            }
        }

        return dp[0][1];
    }
};

//ye samajh mein nahi aayi or jaruri hai kyunki iski or bottom up
//approach ki time complexity LC par kafi alag hai






















// Collecting workspace information

// For the two approaches you wrote for the Stone Game II question, here are the time and space complexities:

// ### First Approach (Recursive with Memoization)
// - **Time Complexity:** \(O(n^3)\)
//   - The recursion explores all possible moves, and for each move, it can go up to \(2m\) steps, leading to a cubic time complexity.
// - **Space Complexity:** \(O(n)\)
//   - The recursion depth can go up to \(n\), where \(n\) is the number of piles.

// ### Second Approach (Dynamic Programming)
// - **Time Complexity:** \(O(n^3)\)
//   - The nested loops iterate over the piles, the possible values of \(M\), and the possible moves, leading to a cubic time complexity.
// - **Space Complexity:** \(O(n^2)\)
//   - The DP table 

// dp

//  has dimensions \((n+1) \times (n+1) \times 2\), leading to a quadratic space complexity.

// ### Optimization
// To optimize the second approach further, you can reduce the space complexity by using a rolling array technique, which will help in reducing the space used by the DP table. However, the time complexity will remain \(O(n^3)\) due to the nature of the problem.

// Here is an optimized version of the second approach with reduced space complexity:

// ```cpp
// class Solution {
// public:
//     int stoneGameII(vector<int>& piles) {
//         int n = piles.size();
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//         vector<int> suffixSum(n + 1, 0);

//         for (int i = n - 1; i >= 0; --i) {
//             suffixSum[i] = suffixSum[i + 1] + piles[i];
//         }

//         for (int i = n - 1; i >= 0; --i) {
//             for (int M = 1; M <= n; ++M) {
//                 for (int x = 1; x <= 2 * M && i + x <= n; ++x) {
//                     dp[i][M] = max(dp[i][M], suffixSum[i] - dp[i + x][max(M, x)]);
//                 }
//             }
//         }

//         return dp[0][1];
//     }
// };
// ```

// - **Time Complexity:** \(O(n^3)\)
// - **Space Complexity:** \(O(n^2)\)

// This optimized version maintains the same time complexity but reduces the space complexity by using a 2D DP table instead of a 3D one.

// Similar code found with 1 license type
