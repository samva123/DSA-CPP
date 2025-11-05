#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solveSpaceOptimised(int k ,vector<int>& prices) {
        vector<vector<vector<int>>>dp(2, vector<vector<int>>(2, vector<int>(k+1,0)));
        

        for (int i = prices.size() - 1; i >= 0; --i) {
            for (int buy = 0; buy < 2; ++buy) {
                for (int limit = 1; limit <= k; ++limit) { // Start limit from 1
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

        return dp[0][1][k];

    

    }
    int maxProfit(int k, vector<int>& prices) {
        return solveSpaceOptimised(k  , prices);
        
    }
};


// it is same as BBS3 just change 2 to k in the dp array