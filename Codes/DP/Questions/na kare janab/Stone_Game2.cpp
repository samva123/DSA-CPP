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
    int solve(vector<int>& piles, int i, int M, vector<vector<int>>& dp, vector<int>& prefix) {
        int n = piles.size();
        if (i >= n) return 0;

        if (dp[i][M] != INT_MIN) return dp[i][M];

        int ans = INT_MIN;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            int sum = prefix[i + X] - prefix[i];
            int diff = sum - solve(piles, i + X, max(M, X), dp, prefix);
            ans = max(ans, diff);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n + 1, INT_MIN));

        int diff = solve(piles, 0, 1, dp, prefix);
        int total = prefix[n];

        return (total + diff) / 2;  // convert diff → Alice score
    }
};