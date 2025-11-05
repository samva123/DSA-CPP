#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(vector<int>&prices , int i , int buy){
        if(i >= prices.size()) return 0;

        int profit = 0;
        if(buy){
            int buyitprofit = -prices[i] + solve(prices , i+1 , 0);
            int skipprofit = solve(prices , i+1 ,1);
            profit = max(buyitprofit , skipprofit);
        }
        else{
            int sellitprofit = prices[i] + solve(prices , i+2 , 1);
            int skipprofit = solve(prices , i+1 ,0);
            profit = max(sellitprofit , skipprofit);
        }
        return profit ;
    }

    int solveMemo(vector<int>&prices , int i , int buy , vector<vector<int>>&dp){
        if(i >= prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if(buy){
            int buyitprofit = -prices[i] + solveMemo(prices , i+1 , 0 ,dp);
            int skipprofit = solveMemo(prices , i+1 ,1,dp);
            profit = max(buyitprofit , skipprofit);
        }
        else{
            int sellitprofit = prices[i] + solveMemo(prices , i+2 , 1,dp);
            int skipprofit = solveMemo(prices , i+1 ,0,dp);
            profit = max(sellitprofit , skipprofit);
        }
        return dp[i][buy] =  profit ;
    }

    int solveBU(vector<int>&prices  ){
        vector<vector<int>>dp(prices.size() + 2 , vector<int>(2,0));
        //if(i >= prices.size()) return 0;
        

        for(int i = prices.size()-1 ;i>=0 ;--i){
            for(int buy = 0 ; buy < 2 ; ++buy){
                int profit = 0;
                if(buy){
                    int buyitprofit = -prices[i] + dp[i+1][0];
                    int skipprofit = dp[i+1][1];
                    profit = max(buyitprofit , skipprofit);
                }
                else{
                    int sellitprofit = prices[i] + dp[i+2][1];
                    int skipprofit =  dp[i+1][0];
                    profit = max(sellitprofit , skipprofit);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
        
    }


    int solveSO(vector<int>&prices  ){
        vector<vector<int>>dp(2, vector<int>(2,0));
        //if(i >= prices.size()) return 0;
        

        for(int i = prices.size()-1 ;i>=0 ;--i){
            for(int buy = 0 ; buy < 2 ; ++buy){
                int profit = 0;
                if(buy){
                    int buyitprofit = -prices[i] + dp[1][0];
                    int skipprofit = dp[1][1];
                    profit = max(buyitprofit , skipprofit);
                }
                else{
                    int sellitprofit = prices[i] + dp[1][1];
                    int skipprofit =  dp[1][0];
                    profit = max(sellitprofit , skipprofit);
                }
                dp[0][buy] = profit;
            }
            dp[1] = dp[0];
        }
        return dp[0][1];
        
    }



    int maxProfit(vector<int>& prices) {
        //vector<vector<int>>dp(prices.size() + 1 , vector<int>(2,-1));
        //return solveMemo(prices ,0,1,dp);
        return solveSO(prices);
        
    }
};