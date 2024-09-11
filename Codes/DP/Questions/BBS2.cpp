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
            int sellitprofit = prices[i] + solve(prices , i+1 , 1);
            int skipprofit = solve(prices , i+1 ,0);
            profit = max(sellitprofit , skipprofit);
        }
        return profit ;
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices , 0 ,1);
        
    }
};


class Solution {
public:
    int solve(vector<int>&prices , int buy  ){
        vector<vector<int>>dp(prices.size() + 1 , vector<int>(2,0));
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
                    int sellitprofit = prices[i] + dp[i+1][1];
                    int skipprofit =  dp[i+1][0];
                    profit = max(sellitprofit , skipprofit);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
        
    }
    


       // int profit = 0;
       
    int maxProfit(vector<int>& prices) {
       
        return solve(prices, 1 );
        
    }
};
