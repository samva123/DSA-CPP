#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void maxprofitfinder(vector<int>&prices , int i , int&minprice , int&maxprofit){
        if(i == prices.size()) return ;

        if(prices[i] < minprice) minprice = prices[i];
        int todayprofit = prices[i] - minprice;
        if(todayprofit > maxprofit) maxprofit = todayprofit;

        maxprofitfinder(prices , i+1 , minprice , maxprofit);


    }
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = INT_MIN;
        maxprofitfinder(prices , 0 , minprice , maxprofit);
        return maxprofit;
        
    }
};