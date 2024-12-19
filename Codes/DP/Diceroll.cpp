#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long int MOD  = 1000000007;
    int solveUsingMem(int n , int k  , int target , vector<vector<int>>&dp){
        if(target < 0) return 0;
        if(n == 0 && target == 0) return 1;
        if(n == 0 && target != 0 )return 0;
        if(n != 0 && target == 0 ) return 0;

        if(dp[n][target] != -1){
            return dp[n][target];
        }

        int ans = 0 ;
        for(int i = 1 ;  i <= k ; i++){
            int rec = 0 ; 
            if(target - i  >= 0 )
                rec = (solveUsingMem(n-1 , k , target-i,dp))%MOD;
            ans = (ans % MOD + rec%MOD)%MOD;
        } 
        dp[n][target] = ans;
        return dp[n][target];


    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int ans = solveUsingMem(n , k , target , dp);
        return ans;
        
        
        
    }
};




class Solution {
public:
    long long int MOD = 1000000007;

    int solveUsingMem(int n, int k, int target, int diceUsed, int currSum, vector<vector<int>>& dp) {
        if (currSum > target) return 0; // Prune invalid states
        if (diceUsed == n) {
            return (currSum == target) ? 1 : 0;
        }
        if (dp[diceUsed][currSum] != -1) {
            return dp[diceUsed][currSum];
        }

        int ans = 0;
        for (int face = 1; face <= k && currSum + face <= target; face++) {
            ans = (ans + solveUsingMem(n, k, target, diceUsed + 1, currSum + face, dp)) % MOD;
        }
        dp[diceUsed][currSum] = ans;
        return dp[diceUsed][currSum];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solveUsingMem(n, k, target, 0, 0, dp);
    }
};



class Solution {
public:
    long long int MOD = 1000000007;
    int solveUsingMem(int n , int k , int target , int diceUsed , int currSum , vector<vector<int>>&dp){

        if(diceUsed == n  && currSum  == target){
            return 1;
        }
        if(diceUsed == n && currSum != target){
            return 0;
        }
        if(currSum  == target && diceUsed != n){
            return 0;

        }
        if(dp[diceUsed][currSum] != -1){
            return dp[diceUsed][currSum];
        }

        int ans = 0 ;
        for(int face = 1 ;face <=k ; face++){
            int recAns = 0;
            if(currSum + face  <= target ){
                recAns = solveUsingMem(n , k , target , diceUsed+1 , currSum+face , dp);
            }
            ans  = (ans%MOD + recAns%MOD)%MOD;
        }
        dp[diceUsed][currSum] = ans;
        return dp[diceUsed][currSum];
        
    }

    int solve(int n , int  k , int target  ){
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[n][target] = 1;

        for(int dice = n -1;dice >= 0 ; dice --){
            for(int sum  = target  ; sum >= 0 ; sum--){
                int ans  = 0 ;
                for(int face = 1; face <= k ; face++){
                    int recAns  = 0;
                    if(sum +face <= target){
                        recAns  = dp[dice+1][sum+face];
                    }
                    ans  = (ans%MOD + recAns%MOD)%MOD;
                }
                dp[dice][sum] = ans;
            }
        }
        return dp[0][0];        
    }
    int numRollsToTarget(int n, int k, int target) {
        int diceUsed  = 0 ;
        int currSum = 0;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int ans  = solveUsingMem(n,k,target , diceUsed , currSum , dp );
        return ans;
        
    }
};


class Solution {
public:
    long long int MOD = 1000000007;
    int solveUsingMem(int n , int k , int target , int diceUsed , int currSum , vector<vector<int>>&dp){

        if(diceUsed == n  && currSum  == target){
            return 1;
        }
        if(diceUsed == n && currSum != target){
            return 0;
        }
        if(currSum  == target && diceUsed != n){
            return 0;

        }
        if(dp[diceUsed][currSum] != -1){
            return dp[diceUsed][currSum];
        }

        int ans = 0 ;
        for(int face = 1 ;face <=k ; face++){
            int recAns = 0;
            if(currSum + face  <= target ){
                recAns = solveUsingMem(n , k , target , diceUsed+1 , currSum+face , dp);
            }
            ans  = (ans%MOD + recAns%MOD)%MOD;
        }
        dp[diceUsed][currSum] = ans;
        return dp[diceUsed][currSum];
        
    }

    int solveSO(int n , int  k , int target  ){


        vector<int>curr(target+1 , 0);
        vector<int>next(target+1,0);

        next[target] =1;

        for(int dice = n -1;dice >= 0 ; dice --){
            for(int sum  = target-1 ; sum >= 0 ; sum--){
                int ans  = 0 ;
                for(int face = 1; face <= k ; face++){
                    int recAns  = 0;
                    if(sum +face <= target){
                        recAns  = next[sum+face];
                    }
                    ans  = (ans%MOD + recAns%MOD)%MOD;
                }
                curr[sum] = ans;
            }
            next = curr;
        }
        return next[0];        
    }
    int numRollsToTarget(int n, int k, int target) {
        int diceUsed  = 0 ;
        int currSum = 0;
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int ans  = solveSO(n,k,target  );
        return ans;
        
    }
};