#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(vector<int>&prices , int i , int buy , int limit){
        if(i >= prices.size() || limit == 0) return 0;

        int profit = 0;
        if(buy){
            int buyitprofit = -prices[i] + solve(prices , i+1 , 0 ,limit);
            int skipprofit = solve(prices , i+1 ,1 , limit);
            profit = max(buyitprofit , skipprofit);
        }
        else{
            int sellitprofit = prices[i] + solve(prices , i+1 , 1, limit-1);
            int skipprofit = solve(prices , i+1 ,0,limit);
            profit = max(sellitprofit , skipprofit);
        }
        return profit ;

    }
    int solveMemo(vector<int>&prices , int i , int buy , int limit , vector<vector<vector<int>>>&dp){
        if(i >= prices.size() || limit == 0) return 0;

        if(dp[i][buy][limit] != -1) return dp[i][buy][limit];

        int profit = 0;
        if(buy){
            int buyitprofit = -prices[i] + solveMemo(prices , i+1 , 0 ,limit,dp);
            int skipprofit = solveMemo(prices , i+1 ,1 , limit ,dp);
            profit = max(buyitprofit , skipprofit);
        }
        else{
            int sellitprofit = prices[i] + solveMemo(prices , i+1 , 1, limit-1,dp);
            int skipprofit = solveMemo(prices , i+1 ,0,limit,dp);
            profit = max(sellitprofit , skipprofit);
        }
        return dp[i][buy][limit] =  profit ;


    }
    int solveBU(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = prices.size() - 1; i >= 0; --i) {
            for (int buy = 0; buy < 2; ++buy) {
                for (int limit = 1; limit <= 2; ++limit) { // Start limit from 1
                    int profit = 0;
                    if (buy) {
                        int buyitprofit = -prices[i] + dp[i + 1][0][limit];
                        int skipprofit = dp[i + 1][1][limit];
                        profit = max(buyitprofit, skipprofit);
                    } else {
                        int sellitprofit = prices[i] + dp[i + 1][1][limit - 1];
                        int skipprofit = dp[i + 1][0][limit];
                        profit = max(sellitprofit, skipprofit);
                    }
                    dp[i][buy][limit] = profit;
                }
            }
        }

        return dp[0][1][2];
    }

    int solveSpaceOptimised(vector<int>& prices) {
        vector<vector<vector<int>>>dp(2, vector<vector<int>>(2, vector<int>(3,0)));
        

        for (int i = prices.size() - 1; i >= 0; --i) {
            for (int buy = 0; buy < 2; ++buy) {
                for (int limit = 1; limit <= 2; ++limit) { // Start limit from 1
                    int profit = 0;
                    if (buy) {
                        int buyitprofit = -prices[i] + dp[ 1][0][limit];
                        int skipprofit = dp[1][1][limit];
                        profit = max(buyitprofit, skipprofit);
                    } else {
                        int sellitprofit = prices[i] + dp[ 1][1][limit - 1];
                        int skipprofit = dp[ 1][0][limit];
                        profit = max(sellitprofit, skipprofit);
                    }
                    dp[0][buy][limit] = profit;
                }
            }
            dp[1] = dp[0];
        }

        return dp[0][1][2];

    

    }
    int maxProfit(vector<int>& prices) {
        //vector<vector<vector<int>>>dp(prices.size() + 1 , vector<vector<int>>(2, vector<int>(3,-1)));
        //return solveMemo(prices , 0,1,2,dp);
        return solveSpaceOptimised(prices);
        //return solveBU(prices);
        
        
    }
};